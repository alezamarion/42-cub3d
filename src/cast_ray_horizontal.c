/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_ray_horizontal.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 22:05:08 by azamario          #+#    #+#             */
/*   Updated: 2022/11/21 18:35:07 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	horizontal_ray_setup(t_game *game)
{
	game->rays->found_horiz_wall_hit = false;
	game->rays->horiz_wall_hit_x = 0;
	game->rays->horiz_wall_hit_y = 0;
	game->rays->horiz_wall_content = 0;
}

void	find_horizontal_intersection(float ray_angle, t_game *game)
{
	float	x_intercept;
	float	y_intercept;
	float	x_step;
	float	y_step;

	// ray_angle = normalize_angle_cast_ray(ray_angle);
	horizontal_ray_setup(game);
	// Find the y-coordinate of the closest horizontal grid intersection
	y_intercept = floor(game->player.posY / TILE_SIZE) * TILE_SIZE;
	// y_intercept += game->rays->is_ray_facing_down ? TILE_SIZE : 0;
	if(game->rays->is_ray_facing_down)
		y_intercept += TILE_SIZE;
	else
		y_intercept += 0;

	// Find the x-coordinate of the closest horizontal grid intersection
	x_intercept = game->player.posX + (y_intercept - game->player.posY) / tan(ray_angle);

	// Calculate the increment x_step and y_step
	y_step = TILE_SIZE;
	// y_step *= game->rays->is_ray_facing_up ? -1 : 1;
	if (game->rays->is_ray_facing_up)
		y_step *= -1;
	else
		y_step *= 1;

	x_step = TILE_SIZE / tan(ray_angle);
	// x_step *= (game->rays->is_ray_facing_left && x_step > 0) ? -1 : 1;
	if(game->rays->is_ray_facing_left && x_step > 0)
		x_step *= -1;
	else
		x_step *= 1;

	// x_step *= (game->rays->is_ray_facing_right && x_step < 0) ? -1 : 1;
	if(game->rays->is_ray_facing_right && x_step < 0)
		x_step *= -1;
	else
		x_step *= 1;

	float next_horiz_touch_x;
	float next_horiz_touch_y;

	next_horiz_touch_x = x_intercept;
	next_horiz_touch_y = y_intercept;

	// Increment x_step and y_step until we find a wall
	while (next_horiz_touch_x >= 0 && next_horiz_touch_x <= (game->map.col * TILE_SIZE) && next_horiz_touch_y >= 0 && next_horiz_touch_y <= (game->map.row * TILE_SIZE))
	{
		float x_to_check = next_horiz_touch_x;
		float y_to_check = next_horiz_touch_y + (game->rays->is_ray_facing_up ? -1 : 0);

		if (has_wall(x_to_check, y_to_check, game))
		{
			// found a wall hit
    		game->rays->horiz_wall_hit_x = next_horiz_touch_x;
    		game->rays->horiz_wall_hit_y = next_horiz_touch_y;
    		game->rays->horiz_wall_content = game->map.file[(int)floor(y_to_check / TILE_SIZE)][(int)floor(x_to_check / TILE_SIZE)];
    		game->rays->found_horiz_wall_hit = true;
    		break;
		}
		else
		{
			next_horiz_touch_x += x_step;
			next_horiz_touch_y += y_step;
		}
	}
}