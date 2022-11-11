/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 17:39:22 by azamario          #+#    #+#             */
/*   Updated: 2022/11/11 13:41:05 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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
	mlx_put_image_to_window(game->mlx, game->window, game->img.img, 0, 0);
	if (&mlx_put_image_to_window == NULL)
	{
		print_error(E_MLX_IMG);
		exit_game(game);
	}
	return (0);
}