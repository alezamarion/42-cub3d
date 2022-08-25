/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 22:30:16 by azamario          #+#    #+#             */
/*   Updated: 2022/08/25 03:59:39 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	map_check_init(t_map *map)
{
	map->collectible = 0;
	map->player = 0;
	map->space = 0;
	map->map_row_size = 0;
	map->map_col_size = 0;
}

int	is_valid_map(char **map, char *file)
{
	t_map	mp;

	if (!map)
		return (0);
	map_check_init(&mp);
	if (has_valid_walls(map,&mp) && has_valid_chars(map)
		&& has_minimum_chars(map, &mp) && has_valid_extension(file))
	{
		printf("Map is valid\n");
		return (1);		
	}
	return (0);
}