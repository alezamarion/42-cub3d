/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 22:30:16 by azamario          #+#    #+#             */
/*   Updated: 2022/11/26 19:38:36 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	is_valid_map(char **map, char *file, t_game *game)
{
	if (!map)
		return (0);
	if (has_valid_chars(map) && has_minimum_chars(map, game)
		&& has_valid_extension(file))
	{
		printf("Map is valid\n");
		return (1);
	}
	return (0);
}
