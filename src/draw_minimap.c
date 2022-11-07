/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 08:19:23 by azamario          #+#    #+#             */
/*   Updated: 2022/10/28 14:13:50 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

//Draw the line by DDA algorithm
void	draw_line(t_game *game, double x1, double y1, double x2, double y2)
{
	double	deltaX;
	double	deltaY;
	double	step;

	deltaX = x2 - x1;
	deltaY = y2 - y1;
	step = (fabs(deltaX) > fabs(deltaY)) ? fabs(deltaX) : fabs(deltaY);
	deltaX /= step;
	deltaY /= step;
	while (fabs(x2 - x1) > 0.01 || fabs(y2 - y1) > 0.01)
	{
		game->img.data[((int)floor(y1) * game->map.col * TILE_SIZE + (int)floor(x1))] = 0x4B0082;
		x1 += deltaX;
		y1 += deltaY;
	}
}

void 	draw_lines(t_game *game)
{
	int		i;
	int		j;

	i = 0;
	while (i < game->map.col)
	{
		draw_line(game, i * TILE_SIZE, 0, i * TILE_SIZE, game->map.row * TILE_SIZE);
		i++;
	}
	draw_line(game, game->map.col * TILE_SIZE - 1, 0, game->map.col * TILE_SIZE - 1, game->map.row * TILE_SIZE);
	j = 0;
	while (j < game->map.row)
	{
		draw_line(game, 0, j * TILE_SIZE, game->map.col * TILE_SIZE, j * TILE_SIZE);
		j++;
	}
	draw_line(game, 0, game->map.row * TILE_SIZE - 1, game->map.col * TILE_SIZE, game->map.row * TILE_SIZE - 1);
}

void	draw_rectangle(t_game *game, int x, int y, int color)
{
	int i;
	int j;

	x *= TILE_SIZE;
	y *= TILE_SIZE;
	i = 0;
	while (i < TILE_SIZE)
	{
		j = 0;
		while (j < TILE_SIZE)
		{
			game->img.data[(y + i) * game->map.col * TILE_SIZE + x + j] = color;
			j++;
		}
		i++;
	}
}

void	draw_rectangles(t_game *game)
{
	int		i;
	int		j;

	i = 0;
	while (i < game->map.row)
	{
		j = 0;
		while (j < game->map.col)
		{
			if (game->map.file[i][j] == '1')
				draw_rectangle(game, j, i, 0x4B0082);
			if (game->map.file[i][j] == '0' || game->map.file[i][j] == 'N')
				draw_rectangle(game, j, i, 0xF5FFA);
			// if (game->map.file[i][j] == 'N')
			// 	draw_player(game, j, i, 0x8FCE00);
				//draw_rectangle(game, j, i, 0x8FCE00);
			j++;
		}
		i++;
	}
}
