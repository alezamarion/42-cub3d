/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 16:18:09 by azamario          #+#    #+#             */
/*   Updated: 2022/08/31 16:20:04 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	hook_player(t_game *game, int i, int j)
{
	draw_image(game, game->player_right, i, j);
	if (game->player_direction == 'u')
		draw_image(game, game->player_up, i, j);
	if (game->player_direction == 'd')
		draw_image(game, game->player_down, i, j);
	if (game->player_direction == 'l')
		draw_image(game, game->player_left, i, j);
	if (game->player_direction == 'r')
		draw_image(game, game->player_right, i, j);
	game->x = i;
	game->y = j;
}