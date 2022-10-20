/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 12:14:36 by azamario          #+#    #+#             */
/*   Updated: 2022/10/19 21:43:42 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	map_counter(char **map, t_game *game)
{
	int	i;

	i = 0;
	game->map_attributes.row = 0;
	game->map_attributes.col = 0;
	while (map[i])
	{
		game->map_attributes.row++;
		i++;
	}
	game->map_attributes.col = ft_strlen(*map);
	printf("row: %d\ncol: %d\n", game->map_attributes.row, game->map_attributes.col);

	i = 0;
	int j;
	while (i < game->map_attributes.row)
	{
		j = 0;
		while (j < game->map_attributes.col)
		{
			if (game->map[i][j] == 'N')
			{
				game->x = i;
				game->y = j;
			}
			j++;
		}
		i++;
	}
}


