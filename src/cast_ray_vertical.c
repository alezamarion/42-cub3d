/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_ray_vertical.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 16:46:10 by azamario          #+#    #+#             */
/*   Updated: 2022/11/17 16:35:53 by azamario         ###   ########.fr       */
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
//	horizontal: x_intercept = game->player.posX + ((game->player.posY - y_intercept) / tan(ray_angle)); ///(AX) -> primeiro toque x
//	horizontal: y_intercept = floor((game->player.posY / TILE_SIZE) * TILE_SIZE); ////////(AY) -> primeiro toque y
 
    x_intercept = floor(game->player.posX / TILE_SIZE) * TILE_SIZE; //primeiro ponto de contato x
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
    while (next_vertical_touch_x >= 0 && next_vertical_touch_x <= WINDOW_WIDTH
            && next_vert_touch_y >= 0 && next_vert_touch_y <= WINDOW_HEIGHT) 
    {
        if (game->rays->is_ray_facing_left)
            next_vertical_touch_x -= 1;
        else   
            next_vertical_touch_x += 0;
        
        if (has_wall(next_vert_touch_y, next_vertical_touch_x, game)) {
            // found a wall hit
            game->rays->vert_wall_hit_x = next_vertical_touch_x;
            game->rays->vert_wall_hit_y = next_vert_touch_y;
            game->rays->vert_wall_content = game->map.file[(int)floor(next_vert_touch_y/ TILE_SIZE)][(int)floor(next_vertical_touch_x / TILE_SIZE)];
            game->rays->found_vert_wall_hit = true;
            break;
        } 
        else
        {
            next_vertical_touch_x += x_step;
            next_vert_touch_y += y_step;
        }
    }
}

