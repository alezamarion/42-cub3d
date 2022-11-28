/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 17:39:22 by azamario          #+#    #+#             */
/*   Updated: 2022/11/27 18:27:36 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	strip_wall_projection(t_wall *wall, t_game *game, int i)
{
	wall->perpend_dist = game->rays[i].distance
		* cos(game->rays[i].ray_angle - game->player.rotation_angle);
	wall->dist_proj_plane = (WIN_WIDTH / 2) / tan(FOV_ANGLE / 2); //esse calculo OK?
	wall->proj_wall_height = (TILE_SIZE / wall->perpend_dist)
		* wall->dist_proj_plane;
	wall->strip_height = (int)wall->proj_wall_height;
}

static void	wall_pixel(t_wall *wall, t_game *game, int i)
{
	int	y;

	wall->top_pixel = (WIN_HEIGHT / 2) - (wall->strip_height / 2);
	if (wall->top_pixel < 0)
		wall->top_pixel = 0;
	wall->botton_pixel = (WIN_HEIGHT / 2) + (wall->strip_height / 2);
	if (wall->botton_pixel > WIN_HEIGHT)
		wall->botton_pixel = WIN_HEIGHT;
	if (wall->top_pixel < WIN_HEIGHT)
	{	
		y = 0;
		while (y < wall->top_pixel)
		{
			game->img.color_buffer[((WIN_WIDTH) * y) + i]
				= game->param.celling_collor;
			y++;
		}
		y = wall->botton_pixel;
		while (y < WIN_HEIGHT)
		{
			game->img.color_buffer[((WIN_WIDTH) * y) + i]
				= game->param.ground_collor;
			y++;
		}
	}
}

static int	*get_right_texture(t_game *game, t_ray *ray)
{	
	if (!ray->was_hit_vertical)
	{
		if (ray->is_ray_facing_up)
			return (game->no.color_buffer);
		return (game->so.color_buffer);
	}
	else
	{
		if (ray->is_ray_facing_right)
			return (game->ea.color_buffer);
		return (game->we.color_buffer);
	}	
}

static void	dist_text_color(t_wall wall, int *current_img, t_game *game, int i)
{
	wall.dist_from_top = wall.top_pixel + (wall.strip_height / 2)
		- (WIN_HEIGHT / 2);
	wall.text_offset_y = wall.dist_from_top
		* ((double)TEXT_HEIGHT / wall.strip_height);
	wall.pix_color = current_img[(TEXT_WIDTH
			* wall.text_offset_y) + wall.text_offset_x];
	game->img.color_buffer[(WIN_WIDTH * wall.top_pixel) + i] = wall.pix_color;
}

void	generate_3d_projection(t_game *game)
{
	int			i;
	t_wall		wall;
	int			*current_img;

	i = 0;
	ft_bzero(&wall, sizeof(t_wall));
	while (i++ < NUM_RAYS)
	{
		strip_wall_projection(&wall, game, i);
		wall_pixel(&wall, game, i);
		if (game->rays[i].was_hit_vertical)
			wall.text_offset_x = (int)game->rays[i].wall_hit_y % TILE_SIZE;
		else
			wall.text_offset_x = (int)game->rays[i].wall_hit_x % TILE_SIZE;
		current_img = get_right_texture(game, game->rays + i);
		while (wall.top_pixel++ < wall.botton_pixel)
		{
			dist_text_color(wall, current_img, game, i);
		}
	}
}

int	render_game(t_game *game)
{	
	move_player(game);
	cast_all_rays(game);
	generate_3d_projection(game);
	mlx_put_image_to_window(game->mlx, game->window, game->img.structure, 0, 0);
	return (0);
}
