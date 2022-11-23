/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 17:39:22 by azamario          #+#    #+#             */
/*   Updated: 2022/11/22 22:55:18 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	draw_minimap(t_game *game)
{
	draw_rectangles(game);
	//draw_lines(game);
}

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
		int		texture_offset_x; //para calcular a textura da parede
		int		tex_num;
		int 	distance_from_top;
		int		texture_offset_y;
		uint32_t texture_pixel_color;
		uint32_t *textures[NUMBER_OF_TEXTURES];

		textures[0] = (uint32_t*) FILE_WALL;
		
		perpendicular_distance = game->rays[i].distance
			* cos(game->rays[i].ray_angle - game->player.rotation_angle);
		distance_proj_plane = (WINDOW_WIDTH / 2) / tan(FOV_ANGLE / 2);
		projected_wall_height = (TILE_SIZE / perpendicular_distance)
			* distance_proj_plane;
		wall_strip_height = (int)projected_wall_height;
		wall_top_pixel = (WINDOW_HEIGHT / 2) - (wall_strip_height / 2);
		if (wall_top_pixel < 0)
			wall_top_pixel = 0;
		wall_botton_pixel = (WINDOW_HEIGHT / 2) + (wall_strip_height / 2);
		if (wall_botton_pixel > WINDOW_HEIGHT)
			wall_botton_pixel = WINDOW_HEIGHT;
		if (wall_top_pixel < WINDOW_HEIGHT)
		{
			for (int y = 0; y < wall_top_pixel; y++)
            	game->img.data[((WINDOW_WIDTH) * y) + i] = 0x333333; //cinza para preto (teto)

			for (int y = wall_botton_pixel; y < WINDOW_HEIGHT; y++)
				game->img.data[((WINDOW_WIDTH) * y) + i] = 0xFF777777; //cinza escuro (chao)
		}
		/////////////////////////////
		//calculo do texture_offset_x
		if (game->rays[i].was_hit_vertical)
			texture_offset_x = (int)game->rays[i].wall_hit_y % TILE_SIZE;
		else
			texture_offset_x = (int)game->rays[i].wall_hit_x % TILE_SIZE;

		//pega o numero de id da textura do conteudo do mapa
		tex_num = game->rays[i].wall_hit_content - 1;

		//render the wall
		for (y = wall_top_pixel; y < wall_botton_pixel; y++)
		{
			distance_from_top = y + (wall_strip_height / 2) - (WINDOW_HEIGHT / 2);
			texture_offset_y = distance_from_top * ((float)TEXTURE_HEIGHT / wall_strip_height);

			//set the color of the wall based on the color from the texture
			texture_pixel_color = textures[tex_num][(TEXTURE_WIDTH * texture_offset_y) + texture_offset_x];
			game->img.data[(WINDOW_WIDTH * y) + i] = texture_pixel_color;
			
			//game->rays[i].was_hit_vertical
			//	? 0xFFFFFFFF : 0xFFCCCCCC; //branco e cinza claro
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
	mlx_put_image_to_window(game->mlx, game->window, game->img.img, 0, 0);
	return (0);
}
