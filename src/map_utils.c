/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 12:14:36 by azamario          #+#    #+#             */
/*   Updated: 2022/11/27 11:05:41 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	find_player(t_game *game, int i, int j)
{
	if (game->map.map[i][j] == 'N' || game->map.map[i][j] == 'S'
		|| game->map.map[i][j] == 'W'|| game->map.map[i][j] == 'E')
	{
		game->map.number_of_players++;
		if (game->map.number_of_players > 1)
		{
			print_error(E_INVALINP);
			exit_game(game);
		}
		game->player.pos_x = j * TILE_SIZE + TILE_SIZE / 2;
		game->player.pos_y = i * TILE_SIZE + TILE_SIZE / 2;
		game->map.map[i][j] = '0';
	}
}

void	map_counter(char **map, t_game *game)
{
	int	i;
	int	j;

	i = 0;
	game->map.row = 0;
	game->map.col = 0;
	game->map.number_of_players = 0;
	while (map[i])
	{
		game->map.row++;
		i++;
	}
	printf("game->row %d\n", game->map.row);
	game->map.col = ft_strlen(*map);
	printf("game->col %d\n", game->map.col);
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
