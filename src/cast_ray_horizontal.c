/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_ray_horizontal.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 22:05:08 by azamario          #+#    #+#             */
/*   Updated: 2022/11/28 08:02:45 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	horiz_less_vert(double htz_hit_dist, int strip_id, t_game *game)
{
	game->rays[strip_id].distance = htz_hit_dist;
	game->rays[strip_id].wall_hit_x = game->rays->horiz_wall_hit_x;
	game->rays[strip_id].wall_hit_y = game->rays->horiz_wall_hit_y;
	game->rays[strip_id].was_hit_vertical = false;
}

static void	wall_content(t_game *game, double x_intercept, double y_intercept)
{
	game->rays->horiz_wall_hit_x = x_intercept;
	game->rays->horiz_wall_hit_y = y_intercept;
	game->rays->found_horiz_wall_hit = true;
}

void	horizontal_ray_setup(t_game *game)
{
	game->rays->found_horiz_wall_hit = false;
	game->rays->horiz_wall_hit_x = 0;
	game->rays->horiz_wall_hit_y = 0;
	game->rays->horiz_wall_content = 0;
}

static void	horizontal_intersection_calc(t_game *game, double ray_angle)
{
	game->horiz_x_step = TILE_SIZE / tan(ray_angle);
	game->horiz_y_step = TILE_SIZE;
	if (game->rays->is_ray_facing_up)
		game->horiz_y_step *= -1;
	if (game->rays->is_ray_facing_left && game->horiz_x_step > 0)
		game->horiz_x_step *= -1;
	if (game->rays->is_ray_facing_right && game->horiz_x_step < 0)
		game->horiz_x_step *= -1;
}

void	find_horizontal_intersection(double ray_angle, t_game *game)
{
	double	x_intercept;
	double	y_intercept;

	horizontal_ray_setup(game);
	y_intercept = floor(game->player.pos_y / TILE_SIZE) * TILE_SIZE;
	if (game->rays->is_ray_facing_down)
		y_intercept += TILE_SIZE;
	x_intercept = game->player.pos_x
		+ (y_intercept - game->player.pos_y) / tan(ray_angle);
	horizontal_intersection_calc(game, ray_angle);
	while (x_intercept >= 0 && x_intercept < (game->map.col
			* TILE_SIZE) && y_intercept >= 0 && y_intercept
		< (game->map.row * TILE_SIZE))
	{
		if (has_wall(x_intercept, y_intercept
				- game->rays->is_ray_facing_up, game))
		{
			wall_content(game, x_intercept, y_intercept);
			break ;
		}
		x_intercept += game->horiz_x_step;
		y_intercept += game->horiz_y_step;
	}
}
