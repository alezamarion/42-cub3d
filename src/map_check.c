/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 22:46:31 by azamario          #+#    #+#             */
/*   Updated: 2022/10/03 08:22:55 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	has_valid_walls(char **map, t_game *game)
{
	int	i;
	int	j;

	while (map[game->map_attributes.row])
		game->map_attributes.row++;
	game->map_attributes.row--;
	game->map_attributes.col = ft_strlen(*map) - 1;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[0][j] != '1' ||
				map[i][0] != '1' || map[i][game->map_attributes.col] != '1'
				|| map[game->map_attributes.row][j] != '1')
				return (0);
			j++;
		}
		i++;
	}
	printf("col_size: %d\nrow_size: %d\n\n", game->map_attributes.col, game->map_attributes.row);
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
				game->map_attributes.player++;
			if (map[i][j] == '0')
				game->map_attributes.space++;
			if (game->map_attributes.player > 0 && game->map_attributes.space > 0)
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
	if (ft_strncmp(extension,  ".cub", 5))
		return (0);
	return (1);	
}