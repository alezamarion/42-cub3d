/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 20:12:13 by azamario          #+#    #+#             */
/*   Updated: 2022/10/03 08:22:55 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	initialize_image(t_game *game)
{
	game->img.img = mlx_new_image(game->mlx, game->map_attributes.col * TILE_SIZE,
										game->map_attributes.row * TILE_SIZE);
	game->img.data = (int *)mlx_get_data_addr(game->img.img, &game->img.bpp,
							&game->img.size_l, &game->img.endian);
}