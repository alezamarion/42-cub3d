/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 19:59:47 by azamario          #+#    #+#             */
/*   Updated: 2022/11/18 21:48:44 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	initialize_mlx(t_game *game)
{
	game->mlx = mlx_init();
	if (game->mlx == NULL)
	{
		print_error(MLX_ERROR);
		exit_game(game);
	}
}

static void	initialize_data(t_game *game)
{
	game->player.posX = 0;
	game->player.posY = 0;
	game->player.turn_direction = 0;
	game->player.walk_direction = 0;
	game->player.side_direction = 0;
	game->player.rotation_angle = PI + (PI / 2); //inicializando a 90 graus
	game->player.turn_speed = 45 * (PI / 180);
	game->player.walk_speed = 4;
	map_counter(game->map.file, game);
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
