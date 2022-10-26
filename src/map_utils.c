/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 12:14:36 by azamario          #+#    #+#             */
/*   Updated: 2022/10/26 17:30:46 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	map_counter(char **map, t_game *game)
{
	int	i;

	i = 0;
	game->map.row = 0;
	game->map.col = 0;
	while (map[i])
	{
		game->map.row++;
		i++;
	}
	game->map.col = ft_strlen(*map);
	printf("row: %d\ncol: %d\n", game->map.row, game->map.col);

	i = 0;
	int j;
	while (i < game->map.row)
	{
		j = 0;
		while (j < game->map.col)
		{
			if (game->map.file[i][j] == 'N')
			{
				game->player.posX = i;
				game->player.posY = j;
			}
			j++;
		}
		i++;
	}
}


