/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 20:20:20 by azamario          #+#    #+#             */
/*   Updated: 2022/08/24 20:20:56 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	map_counter(char **map, t_game *game)
{
	int	i;

	i = 0;
	game->window_height = 0;
	while (map[i])
	{
		game->window_height++;
		i++;
	}
	game->window_width = ft_strlen(*map);
}

void	print_map(char **map)
{
	int	i;

	i = 0;
	printf("\n------------- Mapa: ------------\n");
	while (map[i])
	{
		printf("%s\n", map[i]);
		i++;
	}
	printf("\n");
}