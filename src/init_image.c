/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 20:12:13 by azamario          #+#    #+#             */
/*   Updated: 2022/11/28 07:19:09 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/*this function returns actual address of image (pointer on CHAR) as a simple 
array of pixels
with CHAR we navigate the array one byte at time, but an pixel has 4 bytes (int)
*/

static void	convert_image(char *img_path, t_game *game, t_image *img)
{
	int	width;
	int	height;

	img->structure = mlx_xpm_file_to_image
		(game->mlx, img_path, &width, &height);
	if (img->structure == NULL)
	{
		perror(E_MLX_XPM);
		exit_game(game);
	}
	img->color_buffer = (int *)img->structure->data;
}

static void	init_texture(t_game *game)
{
	convert_image(game->param.no, game, &game->no);
	convert_image(game->param.so, game, &game->so);
	convert_image(game->param.we, game, &game->we);
	convert_image(game->param.ea, game, &game->ea);
}

void	initialize_image(t_game *game)
{
	init_texture(game);
	game->img.structure = mlx_new_image(game->mlx, WIN_WIDTH,
			WIN_HEIGHT);
	if (game->img.structure == NULL)
		print_error(E_MLX_IMG, game);
	game->img.color_buffer = (int *) game->img.structure->data;
}
