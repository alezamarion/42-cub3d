/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 17:39:22 by azamario          #+#    #+#             */
/*   Updated: 2022/11/12 18:41:59 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	render_rays(t_game *game)
{
	int i;

	i = 0;
	while (i < NUM_RAYS)
	{
		draw_line(game,game->player.posX, game->player.posY, game->rays[i].wall_hit_x, game->rays[i].wall_hit_y);
	}
}


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