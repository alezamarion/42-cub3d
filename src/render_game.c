/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 17:39:22 by azamario          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/11/11 13:41:05 by joeduard         ###   ########.fr       */
=======
/*   Updated: 2022/11/13 19:23:10 by azamario         ###   ########.fr       */
>>>>>>> c5f5675af302cd843e47950c401a27d86c49a034
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"


/*
void render_rays(t_game *game)
{
	SDL_Renderer* renderer = NULL;

    SDL_SetRenderDrawColor(renderer, 153, 51, 255, 255);
    for (int i = 0; i < NUM_RAYS; i++)
	{
        SDL_RenderDrawLine(
            renderer,
            game->player.posX,
            game->player.posY,
            game->rays[i].wall_hit_x,
            game->rays[i].wall_hit_y
        );
		printf("i: %d", i);
    }
}
*/
/*
void	draw_rays(t_game *game, double x1, double y1, double x2, double y2)
{
	double	deltaX;
	double	deltaY;
	double	step;

	deltaX = x2 - x1;
	deltaY = y2 - y1;
	step = (fabs(deltaX) > fabs(deltaY)) ? fabs(deltaX) : fabs(deltaY);
	deltaX /= step;
	deltaY /= step;
	while (fabs(x2 - x1) > 0.01 || fabs(y2 - y1) > 0.01)
	{
		game->img.data[((int)floor(y1) * game->map.col * TILE_SIZE + (int)floor(x1))] = 0x4B0082;
		x1 += deltaX;
		y1 += deltaY;
	}
}



void	render_rays(t_game *game)
{
	int i;

	i = 0;
	while (i < NUM_RAYS)
	{
		draw_rays(game,1.0 * game->player.posX, 1.0 * game->player.posY, 1.0 * game->rays[i].wall_hit_x, 1.0 * game->rays[i].wall_hit_y);
		i++;
	}


}
*/

void	draw_minimap(t_game *game)
{
	draw_rectangles(game);
	//draw_lines(game);
}

void generate_3d_projection(t_game *game)
{
    for (int i = 0; i < NUM_RAYS; i++) 
	{
		//vai renderizar cada um dos raios, para distorcer, calculamos a distancia perpendicular
        float perpendicular_distance;
		float distance_proj_plane;
		float projected_wall_height;
		int	wall_strip_height;
		int	wall_top_pixel;
		int wall_botton_pixel;
		int y;

		//printf("DISTANCE %f\n",game->rays[i].distance);
		
		perpendicular_distance = game->rays[i].distance * cos(game->rays[i].ray_angle - game->player.rotation_angle);
		distance_proj_plane = (WINDOW_WIDTH / 2) / tan(FOV_ANGLE / 2);
        projected_wall_height = (TILE_SIZE / perpendicular_distance) * distance_proj_plane;

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

        // render the wall from wall_top_pixel to wall_botton_pixel //a coordenada x e o i
        for (y = wall_top_pixel; y < wall_botton_pixel; y++)
		{
            game->img.data[(WINDOW_WIDTH * y) + i] = game->rays[i].was_hit_vertical ? 0xFFFFFFFF : 0xFFCCCCCC;
        }
    }
}



void	draw_flor_and_ceiling(t_game *game)
{
	(void)game;
}

void	draw_walls(t_game *game)
{
	(void)game;

}

int		render_game(t_game *game)
{

	cast_all_rays(game);
	generate_3d_projection(game);
	
	//draw_minimap(game);
	//draw_player(game);
	//render_rays(game);

	mlx_put_image_to_window(game->mlx, game->window, game->img.img, 0, 0);
<<<<<<< HEAD
	if (&mlx_put_image_to_window == NULL)
	{
		print_error(E_MLX_IMG);
		exit_game(game);
	}
=======
	

>>>>>>> c5f5675af302cd843e47950c401a27d86c49a034
	return (0);
}