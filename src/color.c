/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 17:23:37 by joeduard          #+#    #+#             */
/*   Updated: 2022/11/25 22:20:41 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	is_out_of_range(int n)
{
	return (n < 0 || n > 255);
}

static char	*get_next_octet(char *s)
{
	while (*s != ',')
		s++;
	return (s + 1);
}

static int	get_colors(char *file)
{
	int	color;
	int	r;
	int	g;
	int	b;

	printf("file1: %s\n", file);
	r = ft_atoi(file);
	file = get_next_octet(file);
	g = ft_atoi(file);
	printf("file2: %s\n", file);
	file = get_next_octet(file);
	b = ft_atoi(file);
	printf("file3: %s\n", file);
	if (is_out_of_range(r) || is_out_of_range(g) || is_out_of_range(b))
	{
		printf("Invalid color range\n");
		return (0);
	}

	color = (r << 16) + (g << 8) + b;
	printf("color:%d\n", color);
	return (color);
}

void	save_colors(char *file, int identifier, t_game *game)
{
	if (identifier == 4)
		game->param.ground_collor = get_colors(file + 1);
	if (identifier == 5)
		game->param.celling_collor = get_colors(file + 1);
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
