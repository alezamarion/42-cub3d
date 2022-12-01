/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 14:57:28 by azamario          #+#    #+#             */
/*   Updated: 2022/12/01 15:20:02 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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

void	save_file_info(char **file, t_game *game)
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
