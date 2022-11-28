/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 18:16:38 by azamario          #+#    #+#             */
/*   Updated: 2022/11/28 06:07:10 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static char	*get_next_octet(char *s)
{
	while (*s && *s != ',')
		s++;
	if (*s == ',')
		return (s + 1);
	return (s);
}

int	color_check(char *file, t_game *game)
{
	while (*file == ' ')
	{
		file++;
		if (*file == '\0')
			break ;
	}
	if (!ft_isdigit(*file))
		print_error(E_COLORNESP, game);
	return (true);
}

static int	get_colors(char *file, t_game *game)
{
	int	color;
	int	r;
	int	g;
	int	b;

	if (color_check(file, game))
		r = ft_atoi(file);
	file = get_next_octet(file);
	if (color_check(file, game))
		g = ft_atoi(file);
	file = get_next_octet(file);
	if (color_check(file, game))
		b = ft_atoi(file);
	if (is_out_of_range(r) || is_out_of_range(g) || is_out_of_range(b))
		print_error(E_INVCOLOR, game);
	color = (r << 16) + (g << 8) + b;
	return (color);
}

void	save_colors(char *file, int identifier, t_game *game)
{	
	if (identifier == 4)
	{
		game->param.ground = file + 1;
		if (!validate_colors(game->param.ground))
			print_error(E_NOCOLORP, game);
		game->param.ground_collor = get_colors(file + 1, game);
	}
	if (identifier == 5)
	{
		game->param.celling = file + 1;
		if (!validate_colors(game->param.celling))
			print_error(E_NOCOLORP, game);
		game->param.celling_collor = get_colors(file + 1, game);
	}
}

int	is_color(char *file, int *identifier)
{
	if (!ft_strncmp(file, "F", 1))
		*identifier = 4;
	else if (!ft_strncmp(file, "C", 1))
		*identifier = 5;
	else
		return (0);
	return (1);
}
