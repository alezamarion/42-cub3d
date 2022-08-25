/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 19:59:47 by azamario          #+#    #+#             */
/*   Updated: 2022/08/25 22:30:04 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	initialize_mlx(t_game *game)
{
	game->mlx = mlx_init();
	if (game->mlx == 0)
	{
		printf("mlx_init error :(\n");
		exit (1);	
	}
		
}

static void	initialize_data(t_game *game)
{
	map_counter(game->map, game);
	game->moves = 0;
	game->end_game = 0;
	game->player_direction = 'r';
}

static void	initialize_rendering(t_game *game)
{
	init_window(game);
	initialize_image(game);
	map_render(game);
}

void	init_game(t_game *game)
{
	initialize_mlx(game);
	initialize_data(game);
	initialize_rendering(game);
}