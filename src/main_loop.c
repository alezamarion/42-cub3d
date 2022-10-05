/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 17:39:22 by azamario          #+#    #+#             */
/*   Updated: 2022/10/05 11:36:10 by azamario         ###   ########.fr       */
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
		game->img.data[((int)floor(y1) * game->map_attributes.col * TILE_SIZE + (int)floor(x1))] = 0xFFFFFF;
		x1 += deltaX;
		y1 += deltaY;
	}
}

void 	draw_lines(t_game *game)
{
	int		i;
	int		j;

	i = 0;
	while (i < game->map_attributes.col)
	{
		draw_line(game, i * TILE_SIZE, 0, i * TILE_SIZE, game->map_attributes.row * TILE_SIZE);
		i++;
	}
	draw_line(game, game->map_attributes.col * TILE_SIZE - 1, 0, game->map_attributes.col * TILE_SIZE - 1, game->map_attributes.row * TILE_SIZE);
	j = 0;
	while (j < game->map_attributes.row)
	{
		draw_line(game, 0, j * TILE_SIZE, game->map_attributes.col * TILE_SIZE, j * TILE_SIZE);
		j++;
	}
	draw_line(game, 0, game->map_attributes.row * TILE_SIZE - 1, game->map_attributes.col * TILE_SIZE, game->map_attributes.row * TILE_SIZE - 1);
}

void	draw_rectangle(t_game *game, int x, int y)
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
			game->img.data[(y + i) * game->map_attributes.col * TILE_SIZE + x + j] = 0x9900FF;
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
	while (i < game->map_attributes.row)
	{
		j = 0;
		while (j < game->map_attributes.col)
		{
			if (game->map[i][j] == '1')
				draw_rectangle(game, j, i);
			j++;
		}
		printf("valor do j: %d", j);
		i++;
	}
}

int		main_loop(t_game *game)
{
	draw_rectangles(game);
	draw_lines(game);
	mlx_put_image_to_window(game->mlx, game->window, game->img.img, 0, 0);
	return (0);
}