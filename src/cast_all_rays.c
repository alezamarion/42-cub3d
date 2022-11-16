/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_all_rays.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 16:44:17 by azamario          #+#    #+#             */
/*   Updated: 2022/11/16 13:11:08 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void cast_all_rays(t_game *game)
{

    else
        y_step *= 1;

        //ystep *= (isRayFacingDown && ystep < 0) ? -1 : 1;
    if (is_ray_facing_down && y_step < 0)
        y_step *= -1;
    else
        y_step *= 1;

    float next_vertical_touch_x;
    float next_vertical_touch_y;
    
    next_vertical_touch_x = x_intercept;
    next_vertical_touch_y = y_intercept;

    // Increment xstep and ystep until we find a wall
    while (next_vertical_touch_x >= 0 && next_vertical_touch_x <= WINDOW_WIDTH
            && next_vertical_touch_y >= 0 && next_vertical_touch_y <= WINDOW_HEIGHT)
    {
        float x_to_check;
        float y_to_check;

            //x_to_check = next_vertical_touch_x + (is_ray_facing_left ? -1 : 0);
        if (is_ray_facing_left)
            x_to_check = next_vertical_touch_x -1;
        else
            x_to_check = next_vertical_touch_x + 0;
        
        y_to_check = next_vertical_touch_y;
        
        if (has_wall(x_to_check, y_to_check, game))
        {
            // found a wall hit
            vertical_wall_hit_x = next_vertical_touch_x;
            vertical_wall_hit_y = next_vertical_touch_y;
            vertical_wall_content = game->map.file[(int)floor(y_to_check / TILE_SIZE)][(int)floor(x_to_check / TILE_SIZE)];
            found_vertical_wall_hit = true;
            break;
        } 
        else 
        {
            next_vertical_touch_x += x_step;
            next_vertical_touch_y += y_step;
        }
    }

    ////////////////////////////////////////////////////////////////////////////////////
    // Calculate both horizontal and vertical hit distances and choose the smallest one
    
    float horizontal_hit_distance;
    float vertical_hit_distance;

    if (found_horizontal_wall_hit)
        horizontal_hit_distance = distance_between_points(game->player.posX, game->player.posY, horizontal_wall_hit_x, horizontal_wall_hit_y);
    else
        horizontal_hit_distance = FLT_MAX;

    if (found_vertical_wall_hit)
        vertical_hit_distance =  distance_between_points(game->player.posX, game->player.posY, vertical_wall_hit_x, vertical_wall_hit_y);
    else
        vertical_hit_distance = FLT_MAX;  


    if (vertical_hit_distance < horizontal_hit_distance)
    {
        game->rays[strip_id].distance = vertical_hit_distance;
        game->rays[strip_id].wall_hit_x = vertical_wall_hit_x;
        game->rays[strip_id].wall_hit_y = vertical_wall_hit_y;
        game->rays[strip_id].wall_hit_content = vertical_wall_content;
        game->rays[strip_id].was_hit_vertical = true;
    } 
    else
    {
        game->rays[strip_id].distance = horizontal_hit_distance;
        game->rays[strip_id].wall_hit_x = horizontal_wall_hit_x;
        game->rays[strip_id].wall_hit_y = horizontal_wall_hit_y;
        game->rays[strip_id].wall_hit_content = horizontal_wall_content;
        game->rays[strip_id].was_hit_vertical = false;
    }
    game->rays[strip_id].ray_angle = ray_angle;
    game->rays[strip_id].is_ray_facing_down = is_ray_facing_down;
    game->rays[strip_id].is_ray_facing_up = is_ray_facing_up;
    game->rays[strip_id].is_ray_facing_left = is_ray_facing_left;
    game->rays[strip_id].is_ray_facing_right = is_ray_facing_right;
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
//    printf("\nfinal RAY_ANGLE %f\n",ray_angle);
  //  printf("strip_id %d\n", strip_id);
}