/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 22:08:14 by joeduard          #+#    #+#             */
/*   Updated: 2022/11/10 22:08:18 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	draw_player(t_game *game)
{
	int i;
	int j;

	int x;
	int y;

	x = (int)game->player.posX - 8;
	y = (int)game->player.posY - 8;

	i = 0;
	while (i < 16)
	{
		j = 0;
		while (j < 16)
		{
			game->img.data[(y + i) * game->map.col * TILE_SIZE + x + j] = 0x8FCE00;
			j++;
		}
		i++;
	}
}
