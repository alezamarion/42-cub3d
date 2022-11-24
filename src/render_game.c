/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 17:39:22 by azamario          #+#    #+#             */
/*   Updated: 2022/11/24 11:24:51 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	draw_minimap(t_game *game)
{
	draw_rectangles(game);
}

void	generate_3d_projection(t_game *game)
{
	int	i;

	i = 0;
	while (i < NUM_RAYS)
	{
		float		perpend_dist;
		float		dist_proj_plane;
		float		proj_wall_height;
		int			wall_strip_height;
		int			wall_top_pixel;
		int			wall_botton_pixel;
		int			y;
		int			text_offset_x;
		int			text_offset_y;
		int			distance_from_top;
		uint32_t	text_pix_color;

		perpend_dist = game->rays[i].distance
			* cos(game->rays[i].ray_angle - game->player.rotation_angle);
		dist_proj_plane = (WIN_WIDTH / 2) / tan(FOV_ANGLE / 2);
		proj_wall_height = (TILE_SIZE / perpend_dist)
			* dist_proj_plane;
		wall_strip_height = (int)proj_wall_height;
		wall_top_pixel = (WIN_HEIGHT / 2) - (wall_strip_height / 2);
		if (wall_top_pixel < 0)
			wall_top_pixel = 0;
		wall_botton_pixel = (WIN_HEIGHT / 2) + (wall_strip_height / 2);
		if (wall_botton_pixel > WIN_HEIGHT)
			wall_botton_pixel = WIN_HEIGHT;
		if (wall_top_pixel < WIN_HEIGHT)
		{	
			y = 0;
			while (y < wall_top_pixel)
			{
				game->imgs_buffers.img_buffer[((WIN_WIDTH) * y) + i] = GREY;
				y++;
			}
			y = wall_botton_pixel;
			while (y < WIN_HEIGHT)
			{
				game->imgs_buffers.img_buffer[((WIN_WIDTH) * y) + i] = RED;
				y++;
			}
		}
		if (game->rays[i].was_hit_vertical)
			text_offset_x = (int)game->rays[i].wall_hit_y % TILE_SIZE;
		else
			text_offset_x = (int)game->rays[i].wall_hit_x % TILE_SIZE;
		y = wall_top_pixel;
		while (y < wall_botton_pixel)
		{
			distance_from_top = y + (wall_strip_height / 2) - (WIN_HEIGHT / 2);
			text_offset_y = distance_from_top * ((float)TEXT_HEIGHT
					/ wall_strip_height);
			text_pix_color = game->imgs_buffers.wall_buffer[(TEXT_WIDTH
					* text_offset_y) + text_offset_x];
			game->imgs_buffers.img_buffer[(WIN_WIDTH * y) + i] = text_pix_color;
			y++;
		}
		i++;
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
