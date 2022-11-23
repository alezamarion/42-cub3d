/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 12:14:36 by azamario          #+#    #+#             */
/*   Updated: 2022/11/23 15:48:38 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	find_player(t_game *game, int i, int j)
{
	if (game->map.file[i][j] == 'N')
	{
		game->player.pos_x = j * TILE_SIZE + TILE_SIZE / 2;
		game->player.pos_y = i * TILE_SIZE + TILE_SIZE / 2;
		game->map.file[i][j] = '0';
	}
}

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
			find_player(game, i, j);
			j++;
		}
		i++;
	}
}
