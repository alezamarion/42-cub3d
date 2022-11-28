/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 19:59:47 by azamario          #+#    #+#             */
/*   Updated: 2022/11/28 07:11:46 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	initialize_mlx(t_game *game)
{
	game->mlx = mlx_init();
	if (game->mlx == NULL)
		print_error(E_MLX, game);
}

static void	initialize_data(t_game *game)
{
	game->player.rotation_angle = PI + (PI / 2);
	game->player.turn_speed = (PI / 180);
	game->player.walk_speed = 4;
	game->image_width = 32;
	game->image_height = 32;
	map_counter(game->map.map, game);
}

static void	initialize_rendering(t_game *game)
{
	init_window(game);
	initialize_image(game);
}

void	init_game(t_game *game)
{
	initialize_mlx(game);
	initialize_data(game);
	initialize_rendering(game);
}
