/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 12:14:36 by azamario          #+#    #+#             */
/*   Updated: 2022/11/28 05:54:04 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	save_rotation_angle(t_game *game, char c)
{
	if (c == 'N')
		game->player.rotation_angle = PI_PLUS_HALF_PI;
	else if (c == 'S')
		game->player.rotation_angle = HALF_PI;
	else if (c == 'W')
		game->player.rotation_angle = PI;
	else if (c == 'E')
		game->player.rotation_angle = 0;
}

static void	find_player(t_game *game, int i, int j)
{
	if (game->map.map[i][j] == 'N' || game->map.map[i][j] == 'S'
		|| game->map.map[i][j] == 'W' || game->map.map[i][j] == 'E')
	{
		game->map.number_of_players++;
		if (game->map.number_of_players > 1)
			print_error(E_INVALINP, game);
		save_rotation_angle(game, game->map.map[i][j]);
		game->player.pos_x = j * TILE_SIZE + TILE_SIZE / 2;
		game->player.pos_y = i * TILE_SIZE + TILE_SIZE / 2;
		game->map.map[i][j] = '0';
	}
}

size_t	get_max_line_size(char **map, t_game *game)
{
	size_t	max_line_size;
	int		i;

	max_line_size = 0;
	i = 0;
	while (map[i])
	{
		if (ft_strlen(map[i]) > max_line_size)
			max_line_size = ft_strlen(map[i]);
		i++;
	}
	game->map.row = i;
	return (max_line_size);
}

void	map_counter(char **map, t_game *game)
{
	size_t	i;
	size_t	j;

	game->map.row = 0;
	game->map.col = 0;
	game->map.number_of_players = 0;
	game->map.col = get_max_line_size(game->map.map, game);
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			find_player(game, i, j);
			j++;
		}
		i++;
	}
}
