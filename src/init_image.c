/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 20:12:13 by azamario          #+#    #+#             */
/*   Updated: 2022/11/23 15:42:18 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/*this function returns actual address of image (pointer on CHAR) as a simple 
array of pixels
with CHAR we navigate the array one byte at time, but an pixel has 4 bytes (int)
*/

static void	*convert_image(char *img, t_game *game)
{
	int	width;
	int	height;

	game->wall = mlx_xpm_file_to_image
		(game->mlx, img, &width, &height);
	if (game->wall == NULL)
	{
		perror(E_MLX_XPM);
		exit_game(game);
	}
	game->wall->width = width;
	game->wall->height = height;
	return (game->wall->data);
}

static void	init_texture(t_game *game)
{
	game->imgs_buffers.wall_buffer = convert_image(FILE_WALL, game);
}

void	initialize_image(t_game *game)
{
	init_texture(game);
	game->img = mlx_new_image(game->mlx, WIN_WIDTH,
			WIN_HEIGHT);
	if (game->img == NULL)
	{
		print_error(E_MLX_IMG);
		exit_game(game);
	}
	game->imgs_buffers.img_buffer = (uint32_t *) game->img->data;
}
