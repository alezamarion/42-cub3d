/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 20:12:13 by azamario          #+#    #+#             */
/*   Updated: 2022/08/24 20:55:33 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	*convert_image(char *image, t_game *game)
{
	game->image = mlx_xpm_file_to_image
		(game->mlx, image, &game->image_width, &game->image_height);
	return (game->image);
}

void	initialize_image(t_game *game)
{
	game->wall = convert_image(FILE_WALL, game);
	game->empty_space = convert_image(FILE_EMPTY, game);
	game->player_up = convert_image(FILE_PLAYER_U, game);
	game->player_down = convert_image(FILE_PLAYER_D, game);
	game->player_left = convert_image(FILE_PLAYER_L, game);
	game->player_right = convert_image(FILE_PLAYER_R, game);
}