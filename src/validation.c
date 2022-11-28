/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 03:00:11 by joeduard          #+#    #+#             */
/*   Updated: 2022/11/28 05:49:05 by joeduard         ###   ########.fr       */
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
			break ;
		}
		else
			print_error(E_FILEELEMENT, game);
		if (game->map.map == 0)
			element_count++;
		i++;
	}
}

t_bool	validation(t_game *game, int argc, char **argv)
{
	if (WIN_WIDTH != 800 || WIN_HEIGHT != 600)
		return (print_error(E_RESINVAL, game));
	if (argc < 2)
		return (print_error(E_NOMAP, game));
	if (argc > 2)
		return (print_error(E_MANYARG, game));
	game->map.file = read_file(argv[1]);
	if (!game->map.file || !(*game->map.file))
		print_error(E_EMPTY_F, game);
	if (!has_valid_extension(argv[1]))
		print_error(E_WRONGEXT, game);
	save_file_info(game->map.file, game);
	is_valid_map_info(game);
	is_map_playable(game);
	return (true);
}
