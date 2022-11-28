/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_ray_vertical.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 16:46:10 by azamario          #+#    #+#             */
/*   Updated: 2022/11/28 07:58:23 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	vert_less_horiz(double vert_hit_dist, int strip_id, t_game *game)
{
	game->rays[strip_id].distance = vert_hit_dist;
	game->rays[strip_id].wall_hit_x = game->rays->vert_wall_hit_x;
	game->rays[strip_id].wall_hit_y = game->rays->vert_wall_hit_y;
	game->rays[strip_id].was_hit_vertical = true;
}

static void	wall_content(t_game *game, double x_intercept, double y_intercept)
{
	game->rays->vert_wall_hit_x = x_intercept;
	game->rays->vert_wall_hit_y = y_intercept;
	game->rays->found_vert_wall_hit = true;
}

static void	vertical_ray_setup(t_game *game)
{
	game->rays->found_vert_wall_hit = false;
	game->rays->vert_wall_hit_x = 0;
	game->rays->vert_wall_hit_y = 0;
	game->rays->vert_wall_content = 0;
}

static void	vertical_intersection_calc(t_game *game, double ray_angle)
{
	game->vert_x_step = TILE_SIZE;
	if (game->rays->is_ray_facing_left)
		game->vert_x_step *= -1;
	game->vert_y_step = TILE_SIZE * tan(ray_angle);
	if (game->rays->is_ray_facing_up && game->vert_y_step > 0)
		game->vert_y_step *= -1;
	if (game->rays->is_ray_facing_down && game->vert_y_step < 0)
		game->vert_y_step *= -1;
}

void	find_vertical_intersection(double ray_angle, t_game *game)
{
	double	x_intercept;
	double	y_intercept;

	vertical_ray_setup(game);
	x_intercept = floor(game->player.pos_x / TILE_SIZE) * TILE_SIZE;
	if (game->rays->is_ray_facing_right)
		x_intercept += TILE_SIZE;
	y_intercept = game->player.pos_y + (x_intercept - game->player.pos_x)
		* tan(ray_angle);
	vertical_intersection_calc(game, ray_angle);
	while (x_intercept >= 0 && x_intercept
		< (game->map.col * TILE_SIZE) && y_intercept >= 0
		&& y_intercept < (game->map.row * TILE_SIZE))
	{
		if (has_wall(x_intercept - game->rays->is_ray_facing_left,
				y_intercept, game))
		{
			wall_content(game, x_intercept, y_intercept);
			break ;
		}
		x_intercept += game->vert_x_step;
		y_intercept += game->vert_y_step;
	}
}
