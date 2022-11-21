/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_ray_vertical.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 16:46:10 by azamario          #+#    #+#             */
/*   Updated: 2022/11/21 18:50:33 by joeduard         ###   ########.fr       */
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
    float   x_intercept;
    float   y_intercept;
    float   x_step;
    float   y_step;

//    ray_angle = normalize_angle_cast_ray(ray_angle);
    vertical_ray_setup(game);  
 
    // Find the x-coordinate of the closest horizontal grid intersection
    x_intercept = floor(game->player.posX / TILE_SIZE) * TILE_SIZE;
    x_intercept += game->rays->is_ray_facing_right ? TILE_SIZE : 0;

    // Find the y-coordinate of the closest horizontal grid intersection
    y_intercept = game->player.posY + (x_intercept - game->player.posX) * tan(ray_angle);

    // Calculate the increment x_step and y_step
    x_step = TILE_SIZE;
    x_step *= game->rays->is_ray_facing_left ? -1 : 1;

    y_step = TILE_SIZE * tan(ray_angle);
    y_step *= (game->rays->is_ray_facing_up && y_step > 0) ? -1 : 1;
    y_step *= (game->rays->is_ray_facing_down && y_step < 0) ? -1 : 1;

    float next_vertical_touch_x = x_intercept;
    float next_vert_touch_y = y_intercept;

    // Increment x_step and y_step until we find a wall
    while (next_vertical_touch_x >= 0 && next_vertical_touch_x <= (game->map.col * TILE_SIZE) && next_vert_touch_y >= 0 && next_vert_touch_y <= (game->map.row * TILE_SIZE)) {
        float x_to_check = next_vertical_touch_x + (game->rays->is_ray_facing_left ? -1 : 0);
        float y_to_check = next_vert_touch_y;
        
        if (has_wall(x_to_check, y_to_check, game)) {
            // found a wall hit
            game->rays->vert_wall_hit_x = next_vertical_touch_x;
            game->rays->vert_wall_hit_y = next_vert_touch_y;
            game->rays->vert_wall_content = game->map.file[(int)floor(y_to_check / TILE_SIZE)][(int)floor(x_to_check / TILE_SIZE)];
            game->rays->found_vert_wall_hit = true;
            break;
        } else {
            next_vertical_touch_x += x_step;
            next_vert_touch_y += y_step;
        }
    }
}

