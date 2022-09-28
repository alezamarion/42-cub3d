/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 22:30:16 by azamario          #+#    #+#             */
/*   Updated: 2022/09/28 18:27:23 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	map_check_init(t_game *game)
{
	game->map_attributes.player = 0;
	game->map_attributes.space = 0;
	game->map_attributes.map_row_size = 0;
	game->map_attributes.map_col_size = 0;
}
		      //(mapa lido por gnl, arquivo .cub)
int	is_valid_map(char **map, char *file, t_game *game)
{
	if (!map)
		return (0);
	map_check_init(game);
	if (has_valid_walls(map,game) && has_valid_chars(map)
		&& has_minimum_chars(map, game) && has_valid_extension(file))
	{
		printf("Map is valid\n");
		return (1);		
	}
	return (0);
}