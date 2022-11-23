/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 22:11:09 by azamario          #+#    #+#             */
/*   Updated: 2022/11/23 14:47:35 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	draw_player(t_game *game)
{
	int	i;
	int	j;
	int	x;
	int	y;

	x = (int)game->player.pos_x - 8;
	y = (int)game->player.pos_y - 8;
	i = 0;
	while (i < 16)
	{
		j = 0;
		while (j < 16)
		{
			game->imgs_buffers.img_buffer[(y + i) * game->map.col * \
			TILE_SIZE + x + j] = YELLOW;
			j++;
		}
		i++;
	}
}
