/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 20:12:13 by azamario          #+#    #+#             */
/*   Updated: 2022/11/22 16:30:04 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/*this function returns actual address of image (pointer on CHAR) as a simple 
array of pixels
with CHAR we navigate the array one byte at time, but an pixel has 4 bytes (int)
*/

// static void	*convert_image(char *img, t_game *game)
// {
// 	game->img.img = mlx_xpm_file_to_image
// 		(game->mlx, img, game->image_width * TILE_SIZE, game->img.img_height * TILE_SIZE);
// 	return (game->img.img);
//}

void	initialize_image(t_game *game)
{
	//game->wall = convert_image(FILE_WALL, game);
	
	game->img.img = mlx_new_image(game->mlx, WINDOW_WIDTH,
			WINDOW_HEIGHT);
	if (game->img.img == NULL)
	{
		print_error(E_MLX_IMG);
		exit_game(game);
	}
	game->img.data = (int *)mlx_get_data_addr(game->img.img, &game->img.bpp,
			&game->img.size_l, &game->img.endian);
	if (game->img.data == NULL)
	{
		print_error(E_MLX_ADDR);
		exit_game(game);
	}
}
