/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 22:11:09 by azamario          #+#    #+#             */
/*   Updated: 2022/11/16 23:25:19 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	draw_player(t_game *game)
{
	int	i;
	int	j;
	int	x;
	int	y;

	x = (int)game->player.posX - 8;
	y = (int)game->player.posY - 8;
	i = 0;
	while (i < 16)
	{
		j = 0;
		while (j < 16)
		{
			game->img.data[(y + i) * game->map.col
				* TILE_SIZE + x + j] = YELLOW;
			j++;
		}
		i++;
	}
}
