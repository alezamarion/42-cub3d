/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 20:12:13 by azamario          #+#    #+#             */
/*   Updated: 2022/09/28 17:59:51 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	initialize_image(t_game *game)
{
	game->image.image = mlx_new_image(game->mlx, game->map_attributes.map_row_size * TILE_SIZE,
										game->map_attributes.map_col_size * TILE_SIZE);
	game->image.data = (int *)mlx_get_data_addr(game->image.image, &game->image.bits_per_pixel,
							&game->image.size_l, &game->image.endian);
}