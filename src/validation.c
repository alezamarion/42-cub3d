/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 03:00:11 by joeduard          #+#    #+#             */
/*   Updated: 2022/11/26 21:20:43 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	is_texture(char *file, int *identifier)
{
	if (!ft_strncmp(file, "NO", 2))
		*identifier = 0;
	else if (!ft_strncmp(file, "SO", 2))
		*identifier = 1;
	else if (!ft_strncmp(file, "WE", 2))
		*identifier = 2;
	else if (!ft_strncmp(file, "EA", 2))
		*identifier = 3;
	else
		return (0);
	return (1);
}

static char	*get_content(char *file)
{
	while (*file == ' ')
		file++;
	return (file);
}

static void	save_texture(char *file, int identifier, t_game *game)
{
	if (identifier == 0)
		game->param.no = get_content(file + 2);
	if (identifier == 1)
		game->param.so = get_content(file + 2);
	if (identifier == 2)
		game->param.we = get_content(file + 2);
	if (identifier == 3)
		game->param.ea = get_content(file + 2);
}

static void	save_file_info(char **file, t_game *game)
{
	int	i;
	int	identifier;
	int	element_count;

	element_count = 0;
	i = 0;
	while (file[i])
	{
		if (is_texture(file[i], &identifier))
			save_texture(file[i], identifier, game);
		else if (is_color(file[i], &identifier))
			save_colors(file[i], identifier, game);
		else if (element_count == 6)
		{
			game->map.map = file + i;
//			game->map.cub = *game->map.map;
			break ;
		}
		else
		{
			print_error(E_FILEELEMENT);
			exit_game(game);
		}
		if (game->map.map == 0)
			element_count++;
		i++;
	}
}

t_bool	validation(t_game *game, int argc, char **argv)
{
	if (WIN_WIDTH < 800 || WIN_HEIGHT < 600)
		return (print_error(E_RESINVAL));
	if (argc < 2)
		return (print_error(E_NOMAP));
	if (argc > 2)
		return (print_error(E_MANYARG));

	game->map.file = read_file(argv[1]);
	save_file_info(game->map.file, game);

	//validando caracteres e player
	if (!has_valid_chars(game->map.map))
	{
		print_error(E_INPUTNVAL);
		exit_game(game);
	}
	if (!has_minimum_chars(game->map.map, game))
	{
		print_error(E_NOMINCHAR);
		exit_game(game);
	}

	// validando as cores
	if (!validate_colors(game->param.ground))
	{
		print_error(E_INVNUMCOLOR);
		exit_game(game);
	}


	//validando caminho va


	//if (!is_map_valid(game));

	// if (!is_valid_map(game->map.map, argv[1], game))
	// {
	// 	exit_game(game);
	// 	return (print_error(E_MAPINVAL));
	// }
	
	return (true);
}
