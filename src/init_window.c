/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 20:09:54 by azamario          #+#    #+#             */
/*   Updated: 2022/10/05 11:35:09 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_window(t_game *game)
{
	game->window = mlx_new_window(game->mlx, game->map_attributes.col * TILE_SIZE,
									game->map_attributes.row * TILE_SIZE, "CUB3D");
}