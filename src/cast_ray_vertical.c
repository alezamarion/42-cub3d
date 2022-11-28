/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_ray_vertical.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 16:46:10 by azamario          #+#    #+#             */
/*   Updated: 2022/11/27 21:54:47 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	wall_content(t_game *game, double x_intercept, double y_intercept)
{
	game->rays->vert_wall_hit_x = x_intercept;
	game->rays->vert_wall_hit_y = y_intercept;
	game->rays->vert_wall_content = game->map.map
	[(int)floor(y_intercept / TILE_SIZE)]
	[(int)floor((x_intercept - game->rays->is_ray_facing_left) / TILE_SIZE)];
	game->rays->found_vert_wall_hit = true;
}

static void	vertical_ray_setup(t_game *game)
{
	game->rays->found_vert_wall_hit = false;
	// game->rays->vert_wall_hit_x = 0;
	// game->rays->vert_wall_hit_y = 0;
	// game->rays->vert_wall_content = 0;
}

void	find_vertical_intersection(double ray_angle, t_game *game)
{
	double	x_intercept;
	double	y_intercept;
	double	x_step;
	double	y_step;

	vertical_ray_setup(game);
	x_intercept = floor(game->player.pos_x / TILE_SIZE) * TILE_SIZE;
	if (game->rays->is_ray_facing_right)
		x_intercept += TILE_SIZE;
	y_intercept = game->player.pos_y + (x_intercept - game->player.pos_x)
		* tan(ray_angle);
	x_step = TILE_SIZE;
	if (game->rays->is_ray_facing_left)
		x_step *= -1;
	y_step = TILE_SIZE * tan(ray_angle);
	if (game->rays->is_ray_facing_up && y_step > 0)
		y_step *= -1;
	if (game->rays->is_ray_facing_down && y_step < 0)
		y_step *= -1;
	while (x_intercept >= 0 && x_intercept
		< (game->map.col * TILE_SIZE) && y_intercept >= 0 //tirei =
		&& y_intercept < (game->map.row * TILE_SIZE)) //tirei =
	{
		if (has_wall(x_intercept - game->rays->is_ray_facing_left, y_intercept, game))
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
