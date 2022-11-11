/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 22:30:16 by azamario          #+#    #+#             */
/*   Updated: 2022/11/11 13:17:13 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	map_check_init(t_game *game)
{
	game->map.player = 0;
	game->map.space = 0;
	game->map.row = 0;
	game->map.col = 0;
}

int	is_valid_map(char **map, char *file, t_game *game)
{
	if (!map)
		return (0);
	map_check_init(game);
	if (has_valid_walls(map, game) && has_valid_chars(map)
		&& has_minimum_chars(map, game) && has_valid_extension(file))
	{
		printf("Map is valid\n");
		return (1);		
	}
	return (0);
}


t_bool	print_error(char *error)
{
	ft_putstr_fd(error, 2);
	return (false);
}

t_bool validation(t_game *game, int argc, char **argv)
{
	if (WIN_WIDTH < 1024 || WIN_HEIGHT < 768)
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
