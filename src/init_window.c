/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 20:09:54 by azamario          #+#    #+#             */
/*   Updated: 2022/10/20 11:46:30 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_window(t_game *game)
{
	game->window = mlx_new_window(game->mlx, game->map.col * TILE_SIZE,
									game->map.row * TILE_SIZE, "CUB3D");
	if (game->window == NULL)
	{
		free(game->window);
		printf("MLX_ERROR: Could not initialize or create window");
	}
}