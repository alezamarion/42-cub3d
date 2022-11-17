/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 12:14:36 by azamario          #+#    #+#             */
/*   Updated: 2022/11/16 23:20:15 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	map_counter(char **map, t_game *game)
{
	int	i;
	int	j;

	i = 0;
	game->map.row = 0;
	game->map.col = 0;
	while (map[i])
	{
		game->map.row++;
		i++;
	}
	game->map.col = ft_strlen(*map);
	i = 0;
	while (i < game->map.row)
	{
		j = 0;
		while (j < game->map.col)
		{
			if (game->map.file[i][j] == 'N')
			{
				game->player.posX = j * TILE_SIZE + TILE_SIZE / 2;
				game->player.posY = i * TILE_SIZE + TILE_SIZE / 2;
				game->map.file[i][j] = '0';
			}
			j++;
		}
		i++;
	}
}
