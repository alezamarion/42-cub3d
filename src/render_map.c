/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 17:39:22 by azamario          #+#    #+#             */
/*   Updated: 2022/10/26 08:25:54 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	draw_minimap(t_game *game)
{
	draw_rectangles(game);
	draw_lines(game);
}

void	draw_walls(t_game *game)
{
	(void)game;

}

int		render_map(t_game *game)
{
	draw_walls(game);
	//draw_floor_and_ceiling;
	draw_minimap(game);
	mlx_put_image_to_window(game->mlx, game->window, game->img.img, 0, 0);
	return (0);
}