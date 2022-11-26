/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_ray_horizontal.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 22:05:08 by azamario          #+#    #+#             */
/*   Updated: 2022/11/26 00:29:26 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	wall_content(t_game *game, double x_intercept, double y_intercept)
{
	game->rays->horiz_wall_hit_x = x_intercept;
	game->rays->horiz_wall_hit_y = y_intercept;
	game->rays->horiz_wall_content = game->map.map
	[(int)floor(y_intercept / TILE_SIZE)]
	[(int)floor(x_intercept / TILE_SIZE)];
	game->rays->found_horiz_wall_hit = true;
}

void	horizontal_ray_setup(t_game *game)
{
	game->rays->found_horiz_wall_hit = false;
	game->rays->horiz_wall_hit_x = 0;
	game->rays->horiz_wall_hit_y = 0;
	game->rays->horiz_wall_content = 0;
}

void	find_horizontal_intersection(double ray_angle, t_game *game)
{
	double	x_intercept;
	double	y_intercept;
	double	x_step;
	double	y_step;

	horizontal_ray_setup(game);
	y_intercept = floor(game->player.pos_y / TILE_SIZE) * TILE_SIZE;
	if (game->rays->is_ray_facing_down)
		y_intercept += TILE_SIZE;
	else
		y_intercept += 0;
	x_intercept = game->player.pos_x
		+ (y_intercept - game->player.pos_y) / tan(ray_angle);
	x_step = TILE_SIZE / tan(ray_angle);
	y_step = TILE_SIZE;
	if (game->rays->is_ray_facing_up)
		y_step *= -1;
	else
		y_step *= 1;
	if (game->rays->is_ray_facing_left && x_step > 0)
		x_step *= -1;
	else
		x_step *= 1;
	if (game->rays->is_ray_facing_right && x_step < 0)
		x_step *= -1;
	else
		x_step *= 1;
	while (x_intercept >= 0 && x_intercept <= (game->map.col
			* TILE_SIZE) && y_intercept >= 0 && y_intercept
		<= (game->map.row * TILE_SIZE))
	{
		if (game->rays->is_ray_facing_up)
			y_intercept += -1;
		if (has_wall(x_intercept, y_intercept, game))
		{
			wall_content(game, x_intercept, y_intercept);
			break ;
		}
		else
		{
			x_intercept += x_step;
			y_intercept += y_step;
		}
	}
}
