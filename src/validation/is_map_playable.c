/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_map_playable.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 10:36:31 by azamario          #+#    #+#             */
/*   Updated: 2022/12/05 23:04:19 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

size_t	count_vectors(void **matrix)
{
	size_t	i;

	i = 0;
	while (matrix[i])
		i++;
	return (i);
}

static int	is_closed_on_the_sides(char **map)
{
	if (ft_strrchr(*map, '1') < ft_strrchr(*map, '0'))
		return (0);
	if (ft_strchr(*map, '1') > ft_strchr(*map, '0') && ft_strchr(*map, '0'))
		return (0);
	return (1);
}

static int	is_surrounded(char **map, t_validation v)
{
	if (!v.line_num || v.line_num == v.total_lines - 1)
		return (0);
	if (map[v.line_num][v.column - 1] != '1' && !v.is_closed_behind)
		return (0);
	if (v.line_num)
		if ((v.column >= v.column_limit[TOP_LINE] || \
			(map[v.line_num - 1][v.column - 1] == ' ') || \
			(map[v.line_num - 1][v.column] == ' ')))
			return (0);
	if (v.line_num < v.total_lines - 1)
		if ((v.column >= v.column_limit[BOT_LINE] || \
			(map[v.line_num + 1][v.column - 1] == ' ') || \
			(map[v.line_num + 1][v.column] == ' ')))
			return (0);
	return (1);
}

static int	line_validate(char **map, t_validation v)
{
	if (!is_closed_on_the_sides(map + v.line_num))
		return (EXIT_FAILURE);
	if (v.line_num)
		v.column_limit[TOP_LINE] = ft_strlen(map[v.line_num - 1]) - 1;
	if (v.line_num < v.total_lines - 1)
		v.column_limit[BOT_LINE] = ft_strlen(map[v.line_num + 1]) - 1;
	while (map[v.line_num][v.column])
	{
		if (!ft_strchr("0NEWS", map[v.line_num][v.column]))
		{
			if (map[v.line_num][v.column] != '1' && v.is_closed_behind)
				return (EXIT_FAILURE);
			v.is_closed_behind = 0;
		}
		else
		{
			if (!is_surrounded(map, v))
				return (EXIT_FAILURE);
			v.is_closed_behind = 1;
		}
		v.column++;
	}
	return (EXIT_SUCCESS);
}

static void	validate_empty_lines(t_game *game)
{
	int	i;
	int	bl;
	int	lines_qtd;

	i = -1;
	bl = 0;
	lines_qtd = count_vectors((void **)game->map.map);
	while (game->map.map[++i])
	{
		if (*game->map.map[i] == '\n')
		{
			bl++;
			if (*game->map.map[i + 1] == '\n' && bl < lines_qtd)
				print_error(E_EMPTY_L, game);
		}
	}
}

void	is_map_playable(t_game *game)
{
	t_validation	v;

	check_line(game);
	check_column(game);
	validate_empty_lines(game);
	ft_bzero(v.column_limit, sizeof(int) * 2);
	v.total_lines = count_vectors((void **)game->map.map);
	v.line_num = -1;
	v.column = 0;
	v.is_closed_behind = 0;
	while (++v.line_num < v.total_lines)
	{
		if (line_validate(game->map.map, v))
			print_error(E_NOTSORR, game);
	}
	game->map.minimap_width = get_max_line_size(game->map.map, game);
	game->map.minimap_height = count_vectors((void **)game->map.map);
}
