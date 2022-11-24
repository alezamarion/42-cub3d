/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_ray_horizontal.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 22:05:08 by azamario          #+#    #+#             */
/*   Updated: 2022/11/24 09:04:53 by joeduard         ###   ########.fr       */
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
	float	next_horiz_touch_x;
	float	next_horiz_touch_y;
	float	x_to_check;
	float	y_to_check;

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
	next_horiz_touch_x = x_intercept;
	next_horiz_touch_y = y_intercept;
	while (next_horiz_touch_x >= 0 && next_horiz_touch_x <= (game->map.col 
	* TILE_SIZE) && next_horiz_touch_y >= 0 && next_horiz_touch_y <= (game->map.row * TILE_SIZE))
	{
		x_to_check = next_horiz_touch_x;
		y_to_check = next_horiz_touch_y + (game->rays->is_ray_facing_up ? -1 : 0);
		if (has_wall(x_to_check, y_to_check, game))
		{
			game->rays->horiz_wall_hit_x = next_horiz_touch_x;
			game->rays->horiz_wall_hit_y = next_horiz_touch_y;
			game->rays->horiz_wall_content = game->map.file 
			[(int)floor(y_to_check / TILE_SIZE)] 
			[(int)floor(x_to_check / TILE_SIZE)];
			game->rays->found_horiz_wall_hit = true;
			break ;
		}
		else
		{
			next_horiz_touch_x += x_step;
			next_horiz_touch_y += y_step;
		}
	}
}

// void	find_horizontal_intersection(float ray_angle, t_game *game)
// {
// 	float	x_step;
// 	float	y_step;

// 	horizontal_ray_setup(game);
// 	game->rays->horiz_y = floor(game->player.pos_y / TILE_SIZE) * TILE_SIZE;

// 	if (game->rays->is_ray_facing_down)
// 		game->rays->horiz_y += TILE_SIZE;

// 	game->rays->horiz_x = game->player.pos_x 
// 	+ ((game->rays->horiz_y - game->player.pos_y) / tan(ray_angle));

// 	y_step = TILE_SIZE;
// 	x_step = TILE_SIZE / tan(ray_angle);

// 	if (game->rays->is_ray_facing_up)
// 		y_step *= -1;

// 	x_step = TILE_SIZE / tan(ray_angle);

// 	if (game->rays->is_ray_facing_left && x_step > 0)
// 		x_step *= -1;

// 	if (game->rays->is_ray_facing_right && x_step < 0)
// 		x_step *= -1;
		
// 	while (game->rays->horiz_x >= 0 && game->rays->horiz_x <= (game->map.col 
// 	* TILE_SIZE) && game->rays->horiz_y >= 0 && game->rays->horiz_y <= (game->map.row * TILE_SIZE))
// 	{
		
// 		if (has_wall(game->rays->horiz_x, game->rays->horiz_y - game->rays->is_ray_facing_up, game))
// 		{
// 			game->rays->found_horiz_wall_hit = true;
// 			break ;
// 		}
// 		game->rays->horiz_x += x_step;
// 		game->rays->horiz_y += y_step;
// 	}
// }