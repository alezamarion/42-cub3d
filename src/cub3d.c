/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 21:40:09 by azamario          #+#    #+#             */
/*   Updated: 2022/11/11 13:04:27 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (validation (&game, argc, argv) == false)
		return (EXIT_FAILURE);
	init_game (&game);
	printf("voltou no main\n");
	mlx_loop_hook (game.mlx, &render_game, &game);
	event_handler (&game);
	mlx_loop (game.mlx);
	return (0);

	// if (argc == 2)
	// {
	// 	game.map.file = read_map(argv[1]);
	// 	if (is_valid_map(game.map.file, argv[1], &game))
	// 	{
	// 		init_game(&game);
	// 		mlx_loop_hook(game.mlx, &render_game, &game);
	// 		event_handler(&game);
	// 		mlx_loop(game.mlx);
	// 	}
	// 	else
	// 	{
	// 		printf("Map is not valid\n");
	// 		free_map(game.map.file);
	// 		exit (0);					
	// 	}
	// }
	// else
	// {
	// 	printf("No map specified\n");
	// 	exit (0);	
	// }
	// return (0);
}



