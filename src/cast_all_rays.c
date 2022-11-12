/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_all_rays.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 16:44:17 by azamario          #+#    #+#             */
/*   Updated: 2022/11/11 23:18:45 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"


float   normalize_angle_cast_ray(float angle)
{
    angle = remainder(angle, PI * 2);
    if (angle < 0)
        angle = PI * 2 + angle;
    return (angle);
}

void    cast_ray(float ray_angle, int strip_id, t_game *game)
{
    int     is_ray_facing_down;
    int     is_ray_facing_up;
    int     is_ray_facing_right;
    int     is_ray_facing_left;

    float   x_intercept;
    float   y_intercept;
    float   x_step;
    float   y_step;

    //here all crazy logic for horizontal, vertical and distance to wall
    ray_angle = normalize_angle_cast_ray(ray_angle);

    is_ray_facing_down = ray_angle > 0 && ray_angle < PI;
    is_ray_facing_up = !is_ray_facing_down;
    
    is_ray_facing_right = ray_angle < 0.5 * PI || ray_angle > 1.5 * PI;
    is_ray_facing_left = !is_ray_facing_right;

    // -- HORIZONTAL RAY-GRID INTERSECTION CODE -- //
    //find_horizontal_intersection();

    int     found_horizontal_wall_hit;
    float   horizontal_wall_hit_x;
    float   horizontal_wall_hit_y;
    int     horizontal_wall_content;

    found_horizontal_wall_hit = false;
    horizontal_wall_hit_x = 0;
    horizontal_wall_hit_y = 0;
    horizontal_wall_content = 0;

    //find the y-coordinate fo the closest horizontal grid intersection
    y_intercept = floor(game->player.posY / TILE_SIZE) * TILE_SIZE;
        // y_intercept += is_ray_facing_down ? TILE_SIZE : 0;
    if (is_ray_facing_down)
        y_intercept += TILE_SIZE;

    //find the x-coordinate of the closest horizontal grid intersection
    x_intercept = game->player.posX + (y_intercept - game->player.posY) / tan(ray_angle);

    //calculate the increment x_step and y_step
    y_step = TILE_SIZE;
        // y_step *= is_ray_facing_up ? -1 : 1
    if (is_ray_facing_up)
        y_step *= -1;
    else
        y_step += 1;

    x_step = TILE_SIZE / tan(ray_angle);
        //x_step *= (is_ray_facing_left && x_step > 0) ? -1 : 1;
    if (is_ray_facing_left && x_step > 0)
        x_step *= -1;
    else    
        x_step *= 1;
        //x_step *= (is_ray_facing_right && x_step < 0) ? -1 : 1;
    if (is_ray_facing_right && x_step < 0)
        x_step *= -1;
    else    
        x_step *= 1;

    float next_horizontal_touch_x;
    float next_horizontal_touch_y;

    next_horizontal_touch_x = x_intercept;
    next_horizontal_touch_y = y_intercept;

    //increment x_step and y_step until we find a wall
    

}


void    cast_all_rays(t_game *game)
{
    //start first ray subtracting half of our FOV
    float ray_angle;
    int strip_id;

    ray_angle = game->player.rotation_angle - (FOV_ANGLE / 2); //rotation_angle inicializado a 90 graus

    strip_id = 0;
    while (strip_id < NUM_RAYS)
    {
        cast_ray(ray_angle, strip_id, game);
        ray_angle += FOV_ANGLE / NUM_RAYS;
        strip_id++;
    }
}