/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 21:40:09 by azamario          #+#    #+#             */
/*   Updated: 2022/11/16 12:25:50 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (validation (&game, argc, argv) == false)
		return (EXIT_FAILURE);
	init_game (&game);
	{
		init_game(&game);
		mlx_loop_hook(game.mlx, &render_game, &game);
		event_handler(&game);
//		cast_all_rays(&game);
		mlx_loop(game.mlx);
	}
	return (0);

}


