/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_ray_horizontal.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 22:05:08 by azamario          #+#    #+#             */
/*   Updated: 2022/11/18 21:45:06 by joeduard         ###   ########.fr       */
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
	float	x_step;
	float	y_step;

	horizontal_ray_setup(game); 

	game->rays->horiz_y = floor((game->player.posY / TILE_SIZE)) * TILE_SIZE;
	game->rays->horiz_y *= TILE_SIZE *game->rays->is_ray_facing_down;
	game->rays->horiz_x = game->player.posX + ((game->rays->horiz_y - game->player.posY) / tan(ray_angle));
	y_step = TILE_SIZE;
	if(game->rays->is_ray_facing_up)
		y_step *= -1;
	x_step = TILE_SIZE / tan(ray_angle);
	if (game->rays->is_ray_facing_left && x_step > 0)
		y_step *= -1;
	if (game->rays->is_ray_facing_right && x_step > 0)
		x_step *= -1;
	while (game->rays->horiz_x >= 0 && game->rays->horiz_x < (game->map.col * TILE_SIZE)
	&& game->rays->horiz_y >= 0 && game->rays->horiz_y < (game->map.row * TILE_SIZE))
	{
		if (has_wall(game->rays->horiz_x, game->rays->horiz_y - game->rays->is_ray_facing_up, game))
		{
			game->rays->found_horiz_wall_hit = true;
			break;
		}
	}
	game->rays->horiz_x = x_step;
	game->rays->horiz_y = y_step;
}