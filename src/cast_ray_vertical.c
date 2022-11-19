/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_ray_vertical.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 16:46:10 by azamario          #+#    #+#             */
/*   Updated: 2022/11/18 22:58:52 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"


void    vertical_ray_setup(t_game *game)
{
    game->rays->found_vert_wall_hit = false;
    game->rays->vert_wall_hit_x = 0;
    game->rays->vert_wall_hit_y = 0;
    game->rays->vert_wall_content = 0;
}

void    find_vertical_intersection(float ray_angle, t_game *game)
{
    float	x_step;
	float	y_step;

	vertical_ray_setup(game); 

	game->rays->vert_x = floor((game->player.posX / TILE_SIZE)) * TILE_SIZE;
	game->rays->vert_x *= TILE_SIZE *game->rays->is_ray_facing_right;
	game->rays->vert_y = game->player.posY + ((game->rays->vert_x - game->player.posX) / tan(ray_angle));
	x_step = TILE_SIZE;
	if(game->rays->is_ray_facing_left)
		x_step *= -1;
	y_step = TILE_SIZE / tan(ray_angle);
	if (game->rays->is_ray_facing_up && y_step > 0)
		y_step *= -1;
	if (game->rays->is_ray_facing_down && y_step < 0)
		y_step *= -1;
	while (game->rays->vert_y >= 0 && game->rays->vert_y < (game->map.col * TILE_SIZE)
	&& game->rays->vert_x >= 0 && game->rays->vert_x < (game->map.row * TILE_SIZE))
	{
		if (has_wall(game->rays->vert_y - game->rays->is_ray_facing_left, game->rays->vert_x , game))
		{
			game->rays->found_horiz_wall_hit = true;
			break;
		}
	}
	game->rays->vert_x = x_step;
	game->rays->vert_y = y_step;
}
