/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 22:46:31 by azamario          #+#    #+#             */
/*   Updated: 2022/11/14 01:31:20 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	has_valid_walls(char **map, t_game *game)
{
	int	i;
	int	j;

	while (map[game->map.row])
		game->map.row++;
	game->map.row--;
	game->map.col = ft_strlen(*map) - 1;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[0][j] != '1' ||
				map[i][0] != '1' || map[i][game->map.col] != '1'
				|| map[game->map.row][j] != '1')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	has_valid_chars(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '1' && map[i][j] != '0' && map[i][j] != 'N')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	has_minimum_chars(char **map, t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N')
				game->map.player++;
			if (map[i][j] == '0')
				game->map.space++;
			if (game->map.player > 0 && game->map.space > 0)
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
