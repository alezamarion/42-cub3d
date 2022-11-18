/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 17:39:22 by azamario          #+#    #+#             */
/*   Updated: 2022/11/18 14:56:19 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/*
void	draw_rays(t_game *game, double x1, double y1, double x2, double y2)
{
	double	delta_x;
	double	delta_y;
	double	step;

	delta_x = x2 - x1;
	delta_y = y2 - y1;
	step = (fabs(delta_x) > fabs(delta_y)) ? fabs(delta_x) : fabs(delta_y);
	delta_x /= step;
	delta_y /= step;
	while (fabs(x2 - x1) > 0.01 || fabs(y2 - y1) > 0.01)
	{
		game->img.data[((int)floor(y1) * game->map.col * TILE_SIZE + (int)floor(x1))] = 0x4B0082;
		x1 += delta_x;
		y1 += delta_y;
	}
}

void	render_rays(t_game *game)
{
	int i;

	i = 0;
	while (i < NUM_RAYS)
	{
		draw_rays(game,1.0 * game->player.pos_x, 1.0 * game->player.pos_y, 1.0 * game->rays[i].wall_hit_x, 1.0 * game->rays[i].wall_hit_y);
		i++;
	}
}
*/

void	draw_minimap(t_game *game)
{
	draw_rectangles(game);
	//draw_lines(game);
}

//vai renderizar cada um dos raios, para distorcer, calculamos a distancia perpendicular
void	generate_3d_projection(t_game *game)
{
	for (int i = 0; i < NUM_RAYS; i++)
	{
		float	perpendicular_distance;
		float	distance_proj_plane;
		float	projected_wall_height;
		int		wall_strip_height;
		int		wall_top_pixel;
		int		wall_botton_pixel;
		int		y;

		perpendicular_distance = game->rays[i].distance
			* cos(game->rays[i].ray_angle - game->player.rotation_angle);
		distance_proj_plane = (WINDOW_WIDTH / 2) / tan(FOV_ANGLE / 2);
		projected_wall_height = (TILE_SIZE / perpendicular_distance)
			* distance_proj_plane;

		//qual o tamanho da projecao da parede
		wall_strip_height = (int)projected_wall_height;

		//acha o pixel superior e inferior, essa distancia vai ser preenchida para renderizar a parede
		wall_top_pixel = (WINDOW_HEIGHT / 2) - (wall_strip_height / 2);
			//wall_top_pixel = wall_top_pixel < 0 ? 0 : wall_top_pixel;
		if (wall_top_pixel < 0)
			wall_top_pixel = 0;
		//else
		//	wall_top_pixel = wall_top_pixel;

		wall_botton_pixel = (WINDOW_HEIGHT / 2) + (wall_strip_height / 2);
			//wall_botton_pixel = wall_botton_pixel > WINDOW_HEIGHT ? WINDOW_HEIGHT : wall_botton_pixel;
		if (wall_botton_pixel > WINDOW_HEIGHT)
			wall_botton_pixel = WINDOW_HEIGHT;
		//else
		//	wall_botton_pixel = wall_botton_pixel;

		// set the color of the ceiling
        for (int y = 0; y < wall_top_pixel; y++)
            game->img.data[(WINDOW_WIDTH * y) + i] = 0xFF333333;

		// render the wall from wall_top_pixel to wall_botton_pixel //a coordenada x e o i
		for (y = wall_top_pixel; y < wall_botton_pixel; y++)
		{
			game->img.data[(WINDOW_WIDTH * y) + i] = game->rays[i].was_hit_vertical
				? 0xFFFFFFFF : 0xFFCCCCCC;
		}

        // set the color of the floor
        for (int y = wall_botton_pixel; y < WINDOW_HEIGHT; y++)
            game->img.data[(WINDOW_WIDTH * y) + i] = 0xFF777777;		
	}
}

int		render_game(t_game *game)
{
		cast_all_rays(game);
		generate_3d_projection(game);
	//	draw_minimap(game);
	//	draw_player(game);
	mlx_put_image_to_window(game->mlx, game->window, game->img.img, 0, 0);
	return (0);
}
