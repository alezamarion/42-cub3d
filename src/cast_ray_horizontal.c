/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_ray_horizontal.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 22:05:08 by azamario          #+#    #+#             */
/*   Updated: 2022/11/18 15:11:20 by azamario         ###   ########.fr       */
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
	float	x_step; //distancia entre pontos interseccao horizontal
	float	y_step; //distancia entre pontos interseccao vertical

	// ray_angle = normalize_angle_cast_ray(ray_angle);
	horizontal_ray_setup(game);
	// Find the y-coordinate of the closest horizontal grid intersection
	// a primeira interseccao a partir do jogador
	y_intercept = floor((game->player.posY / TILE_SIZE) * TILE_SIZE); ////////(AY) -> primeiro toque y
	// y_intercept += game->rays->is_ray_facing_down ? TILE_SIZE : 0;
	if(game->rays->is_ray_facing_down)
		y_intercept += TILE_SIZE;
	else
		y_intercept += 0;

	// Find the x-coordinate of the closest horizontal grid intersection
	x_intercept = game->player.posX + ((y_intercept - game->player.posY) / tan(ray_angle)); ///(AX) -> primeiro toque x

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
	while (next_horiz_touch_x >= 0 && next_horiz_touch_x <= WINDOW_WIDTH
			&& next_horiz_touch_y >= 0 && next_horiz_touch_y <= WINDOW_HEIGHT)
	{
		if (game->rays->is_ray_facing_up)
			next_horiz_touch_y -=1;
		else
			next_horiz_touch_y += 0;

		if (has_wall(next_horiz_touch_x, next_horiz_touch_y, game))
		{
			// found a wall hit
    		game->rays->horiz_wall_hit_x = next_horiz_touch_x;
    		game->rays->horiz_wall_hit_y = next_horiz_touch_y;
    		// game->rays->horiz_wall_content = game->map.file[(int)floor(next_horiz_touch_y / TILE_SIZE)][(int)floor(next_horiz_touch_x/ TILE_SIZE)];
    		// printf("horiz_wall_content %d\n", game->rays->horiz_wall_content);
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
