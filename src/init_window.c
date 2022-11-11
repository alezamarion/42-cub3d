/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 20:09:54 by azamario          #+#    #+#             */
/*   Updated: 2022/11/11 13:30:23 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_window(t_game *game)
{
	// game->window = mlx_new_window(game->mlx, game->map.col * TILE_SIZE,
	// 								game->map.row * TILE_SIZE, "CUB3D");
	game->window = mlx_new_window(game->mlx, WIN_WIDTH, WIN_HEIGHT, "CUB3D");
	if (game->window == NULL)
	{
		free(game->window);
		print_error(E_MLX_WIN);
		exit_game(game);
	}
}