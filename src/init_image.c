/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 20:12:13 by azamario          #+#    #+#             */
/*   Updated: 2022/11/16 13:07:32 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	initialize_image(t_game *game)
{
	game->img.img = mlx_new_image(game->mlx, game->map.col * TILE_SIZE,
										game->map.row * TILE_SIZE);
	if (game->img.img == NULL)
//	game->img.img = mlx_new_image(game->mlx, game->map.col * TILE_SIZE,
//										game->map.row * TILE_SIZE);

	game->img.data = (int *)mlx_get_data_addr(game->img.img, &game->img.bpp,
							&game->img.size_l, &game->img.endian);
	{
	
		print_error(E_MLX_ADDR);
		exit_game(game);
	}
					//this function returns actual address of image (pointer on CHAR) as a simple array of pixels
					//with CHAR we navigate the array one byte at time, but an pixel has 4 bytes (int)
} 