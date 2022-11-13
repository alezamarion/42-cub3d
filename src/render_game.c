/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 17:39:22 by azamario          #+#    #+#             */
/*   Updated: 2022/11/12 21:29:53 by azamario         ###   ########.fr       */
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

void	draw_walls(t_game *game)
{
	(void)game;

}

int		render_game(t_game *game)
{
	draw_walls(game);
	//draw_floor_and_ceiling;
	draw_minimap(game);
	draw_player(game);
	render_rays(game);
	mlx_put_image_to_window(game->mlx, game->window, game->img.img, 0, 0);
	return (0);
}