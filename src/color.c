/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 18:16:38 by azamario          #+#    #+#             */
/*   Updated: 2022/11/27 09:22:16 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	is_out_of_range(int n)
{
	return (n < 0 || n > 255);
}

static char	*get_next_octet(char *s)
{
	while (*s && *s != ',')
		s++;
	return (s + 1);
}

static int	get_colors(char *file, t_game *game)
{
	int	color;
	int	r;
	int	g;
	int	b;

	r = ft_atoi(file);
	file = get_next_octet(file);
	g = ft_atoi(file);
	file = get_next_octet(file);
	b = ft_atoi(file);
	if (is_out_of_range(r) || is_out_of_range(g) || is_out_of_range(b))
	{
		printf("Invalid color range\n");
		exit_game(game);
		return (0);
	}
	color = (r << 16) + (g << 8) + b;
	return (color);
}

void	save_colors(char *file, int identifier, t_game *game)
{	
	if (identifier == 4)
	{
		game->param.ground = file + 1;
		if (!validate_colors(game->param.ground))
		{
			print_error(E_NOCOLORP);
			exit_game(game);
		}
		game->param.ground_collor = get_colors(file + 1, game);
	}
	if (identifier == 5)
	{
		game->param.celling = file + 1;
		if (!validate_colors(game->param.celling))
		{
			print_error(E_NOCOLORP);
			exit_game(game);
		}
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
