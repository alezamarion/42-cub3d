/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_info.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 22:30:16 by azamario          #+#    #+#             */
/*   Updated: 2022/11/28 05:55:32 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	has_valid_chars(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != ' ' && map[i][j] != '1' && map[i][j] != '0'
				&& map[i][j] != 'N' && map[i][j] != 'S' && map[i][j] != 'E'
				&& map[i][j] != 'W')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int	has_minimum_chars(char **map, t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'S'
				|| map[i][j] == 'W' || map[i][j] == 'E')
				game->map.player++;
			if (map[i][j] == '0')
				game->map.space++;
			if (map[i][j] == '1')
				game->map.wall++;
			if (game->map.player > 0 && game->map.space > 0
				&& game->map.wall > 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	has_valid_extension(char *file)
{
	char	*extension;

	if (!file)
		return (0);
	extension = ft_strrchr(file, '.');
	if (extension == NULL)
		return (0);
	if (ft_strncmp(extension, ".cub", 5))
		return (0);
	return (1);
}

int	is_valid_map_info(t_game *game)
{
	if (!game->map.map)
		print_error(E_NO_MAP, game);
	if (!has_valid_chars(game->map.map))
		print_error(E_INPUTNVAL, game);
	if (!has_minimum_chars(game->map.map, game))
		print_error(E_NOMINCHAR, game);
	return (true);
}
