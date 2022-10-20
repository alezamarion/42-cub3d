/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 21:40:09 by azamario          #+#    #+#             */
/*   Updated: 2022/10/20 12:34:53 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc == 2)
	{
		game.map.file = read_map(argv[1]);
		if (is_valid_map(game.map.file, argv[1], &game))
		{
			init_game(&game);
			mlx_loop_hook(game.mlx, &render_map, &game);
			event_handler(&game);
			mlx_loop(game.mlx);
		}
		else
		{
			printf("Map is not valid\n");
			free_map(game.map.file);
			exit (0);					
		}
	}
	else
	{
		printf("No map specified\n");
		exit (0);	
	}
	return (0);
}