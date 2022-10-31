/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 19:59:47 by azamario          #+#    #+#             */
/*   Updated: 2022/10/27 22:28:41 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	initialize_mlx(t_game *game)
{
	game->mlx = mlx_init();
	if (game->mlx == NULL)
	{
		free(game->mlx);
		printf("MLX_ERROR: Could not initialize or create window");
	}
}

static void	initialize_data(t_game *game)
{
	game->player.posX  = 0;
	game->player.posY = 0;

	game->player.turn_direction = 0;
	game->player.walk_direction = 0;
	game->player.rotation_angle = PI / 2;
	game->player.mov_speed = 2;
	game->player.rotation_speed = 2 * (PI / 180);

	// game->player.dirX = -1;
	// game->player.dirY = 0;
	// game->player.planeX = 0;
	// game->player.planeY = 0.66;
	// game->time = 0;

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