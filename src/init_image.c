/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 20:12:13 by azamario          #+#    #+#             */
/*   Updated: 2022/11/23 13:10:52 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/*this function returns actual address of image (pointer on CHAR) as a simple 
array of pixels
with CHAR we navigate the array one byte at time, but an pixel has 4 bytes (int)
*/

static void	*convert_image(char *img, t_game *game)
{
	game->texture.texture = mlx_xpm_file_to_image
		(game->mlx, img, &game->texture.width, &game->texture.height);
	return (game->texture.texture);
}

void	initialize_image(t_game *game)
{
	game->wall = convert_image(FILE_WALL, game);
	if (game->texture.texture == NULL)
		printf(" erro!");		
	
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
