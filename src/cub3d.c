/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 21:40:09 by azamario          #+#    #+#             */
/*   Updated: 2022/11/23 12:09:09 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/*
init_game();
load_file();
save_infos();
file_validadte();
load_game();
start_game();


*/


int	main(int argc, char **argv)
{
	t_game	game;

	if (validation (&game, argc, argv) == false)
		return (EXIT_FAILURE);
	init_game (&game);
	// load_file();
	// save_infos();
	// file_validate();
	// map_validate();
	mlx_loop_hook (game.mlx, &render_game, &game);
	event_handler (&game);
	mlx_loop (game.mlx);
	return (0);
}
