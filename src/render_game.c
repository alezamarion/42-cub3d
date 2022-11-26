/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 17:39:22 by azamario          #+#    #+#             */
/*   Updated: 2022/11/25 22:08:38 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	draw_minimap(t_game *game)
{
	draw_rectangles(game);
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
			game->imgs_buffers.img_buffer[((WIN_WIDTH) * y) + i] = game->param.celling_collor;
			y++;
		}
		y = wall->botton_pixel;
		while (y < WIN_HEIGHT)
		{
			game->imgs_buffers.img_buffer[((WIN_WIDTH) * y) + i] = game->param.ground_collor;
			y++;
		}
	}
}

static void	strip_wall_projection(t_wall *wall, t_game *game, int i)
{
	wall->perpend_dist = game->rays[i].distance
		* cos(game->rays[i].ray_angle - game->player.rotation_angle);
	wall->dist_proj_plane = (WIN_WIDTH / 2) / tan(FOV_ANGLE / 2);
	wall->proj_wall_height = (TILE_SIZE / wall->perpend_dist)
		* wall->dist_proj_plane;
	wall->strip_height = (int)wall->proj_wall_height;
}

void	generate_3d_projection(t_game *game)
{
	int		i;
	int		y;
	t_wall	wall;

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
		y = wall.top_pixel;
		while (y++ < wall.botton_pixel)
		{
			wall.dist_from_top = y + (wall.strip_height / 2) - (WIN_HEIGHT / 2);
			wall.text_offset_y = wall.dist_from_top
				* ((float)TEXT_HEIGHT / wall.strip_height);
			wall.pix_color = game->imgs_buffers.wall_buffer[(TEXT_WIDTH
					* wall.text_offset_y) + wall.text_offset_x];
			game->imgs_buffers.img_buffer[(WIN_WIDTH * y) + i] = wall.pix_color;
		}
	}
}

int	render_game(t_game *game)
{		
	move_player(game);
	cast_all_rays(game);
	generate_3d_projection(game);
	//	draw_minimap(game);
	//	draw_player(game);
	mlx_put_image_to_window(game->mlx, game->window, game->img, 0, 0);
	return (0);
}
