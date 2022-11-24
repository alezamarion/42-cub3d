/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_ray_vertical.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 16:46:10 by azamario          #+#    #+#             */
/*   Updated: 2022/11/24 14:33:27 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	wall_content(t_game *game, float x_intercept, float y_intercept)
{
	game->rays->vert_wall_hit_x = x_intercept;
	game->rays->vert_wall_hit_y = y_intercept;
	game->rays->vert_wall_content = game->map.file
	[(int)floor(y_intercept / TILE_SIZE)]
	[(int)floor(x_intercept / TILE_SIZE)];
	game->rays->found_vert_wall_hit = true;
}

static void	vertical_ray_setup(t_game *game)
{
	game->rays->found_vert_wall_hit = false;
	game->rays->vert_wall_hit_x = 0;
	game->rays->vert_wall_hit_y = 0;
	game->rays->vert_wall_content = 0;
}

void	find_vertical_intersection(float ray_angle, t_game *game)
{
	float	x_intercept;
	float	y_intercept;
	float	x_step;
	float	y_step;

	y_step = 0;
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
		<= (game->map.col * TILE_SIZE) && y_intercept >= 0
		&& y_intercept <= (game->map.row * TILE_SIZE))
	{
		if (game->rays->is_ray_facing_left)
			x_intercept += -1;
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
