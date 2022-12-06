/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 03:00:11 by joeduard          #+#    #+#             */
/*   Updated: 2022/12/01 14:58:13 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	has_valid_extension(char *file)
{
	char	*extension;

	if (!file)
		return (0);
	extension = ft_strrchr(file, '.');
	if (extension == NULL)
		return (0);
	if (ft_strncmp(extension, ".cub", 5))
		return (0);
	return (1);
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
