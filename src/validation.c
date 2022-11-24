/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 03:00:11 by joeduard          #+#    #+#             */
/*   Updated: 2022/11/24 11:20:58 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_bool	print_error(char *error)
{
	ft_putstr_fd(error, 2);
	return (false);
}

t_bool	validation(t_game *game, int argc, char **argv)
{
	if (WIN_WIDTH < 800 || WIN_HEIGHT < 600)
		return (print_error(E_RESINVAL));
	if (argc < 2)
		return (print_error(E_NOMAP));
	if (argc > 2)
		return (print_error(E_MANYARG));
	ft_bzero(&game->map, sizeof(t_map));
	game->map.file = read_map(argv[1]);
	if (!is_valid_map(game->map.file, argv[1], game))
	{
		free_map(game->map.file);
		return (print_error(E_MAPINVAL));
	}
	return (true);
}
