/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_all_rays.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 16:44:17 by azamario          #+#    #+#             */
/*   Updated: 2022/11/16 12:16:05 by joeduard         ###   ########.fr       */
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

float distance_between_points(float x1, float y1, float x2, float y2)
{
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

static void vertical_smallest_horizontal(int strip_id, t_game *game)
{

    game->rays[strip_id].distance = game->rays->vertical_hit_distance;
    game->rays[strip_id].wall_hit_x = game->rays->vertical_wall_hit_x;
    game->rays[strip_id].wall_hit_y = game->rays->vertical_wall_hit_y;
    game->rays[strip_id].wall_hit_content = game->rays->vertical_wall_content;
    game->rays[strip_id].was_hit_vertical = true;
} 

static void horizontal_smallest_vertical(int strip_id, t_game *game)
{   
    game->rays[strip_id].distance = game->rays->horizontal_hit_distance;
    game->rays[strip_id].wall_hit_x = game->rays->horizontal_wall_hit_x;
    game->rays[strip_id].wall_hit_y = game->rays->horizontal_wall_hit_y;
    game->rays[strip_id].wall_hit_content = game->rays->horizontal_wall_content;
    game->rays[strip_id].was_hit_vertical = false;
}

 void calcule_smallest_distance(float ray_angle, int strip_id, t_game *game)
{

    if (game->rays->found_horizontal_wall_hit)
        game->rays->horizontal_hit_distance = distance_between_points(game->player.pos_x, game->player.pos_y, game->rays->horizontal_wall_hit_x, game->rays->horizontal_wall_hit_y);
    else
        game->rays->horizontal_hit_distance = FLT_MAX;

    if (game->rays->found_vertical_wall_hit)
        game->rays->vertical_hit_distance =  distance_between_points(game->player.pos_x, game->player.pos_y, game->rays->vertical_wall_hit_x, game->rays->vertical_wall_hit_y);
    else
        game->rays->vertical_hit_distance = FLT_MAX;  
    if (game->rays->vertical_hit_distance < game->rays->horizontal_hit_distance)
        vertical_smallest_horizontal(strip_id, game);
    else
        horizontal_smallest_vertical(strip_id, game);
    game->rays[strip_id].ray_angle = ray_angle;
    game->rays[strip_id].is_ray_facing_down = game->rays->is_ray_facing_down;
    game->rays[strip_id].is_ray_facing_up = game->rays->is_ray_facing_up;
    game->rays[strip_id].is_ray_facing_left = game->rays->is_ray_facing_left;
    game->rays[strip_id].is_ray_facing_right = game->rays->is_ray_facing_right;
}

void    cast_ray(float ray_angle, int strip_id, t_game *game)
{
    float   x_intercept;
    float   y_intercept;
    float   x_step;
    float   y_step;

    //here all crazy logic for horizontal, vertical and distance to wall
    ray_angle = normalize_angle_cast_ray(ray_angle);
    game->rays->is_ray_facing_down = ray_angle > 0 && ray_angle < PI;
    game->rays->is_ray_facing_up = !game->rays->is_ray_facing_down;
    game->rays->is_ray_facing_right = ray_angle < 0.5 * PI || ray_angle > 1.5 * PI;
    game->rays->is_ray_facing_left = !game->rays->is_ray_facing_right;

    //////////////////////////////////////////////////
    // -- HORIZONTAL RAY-GRID INTERSECTION CODE -- //
    //find_horizontal_intersection();

    game->rays->found_horizontal_wall_hit = false;
    game->rays->horizontal_wall_hit_x = 0;
    game->rays->horizontal_wall_hit_y = 0;
    game->rays->horizontal_wall_content = 0;

    //find the y-coordinate fo the closest horizontal grid intersection
    y_intercept = floor(game->player.pos_y / TILE_SIZE) * TILE_SIZE;
        // y_intercept += game->rays->is_ray_facing_down ? TILE_SIZE : 0;
    if (game->rays->is_ray_facing_down)
        y_intercept += TILE_SIZE;
    else
        y_intercept += 0;

    //find the x-coordinate of the closest horizontal grid intersection
    x_intercept = game->player.pos_x + (y_intercept - game->player.pos_y) / tan(ray_angle);

    //calculate the increment x_step and y_step
    y_step = TILE_SIZE;
        // y_step *= game->rays->is_ray_facing_up ? -1 : 1
    if (game->rays->is_ray_facing_up)
        y_step *= -1;
    else
        y_step *= 1;

    x_step = TILE_SIZE / tan(ray_angle);
        //x_step *= (game->rays->is_ray_facing_left && x_step > 0) ? -1 : 1;
    if (game->rays->is_ray_facing_left && x_step > 0)
        x_step *= -1;
    else    
        x_step *= 1;
        //x_step *= (game->rays->is_ray_facing_right && x_step < 0) ? -1 : 1;
    if (game->rays->is_ray_facing_right && x_step < 0)
        x_step *= -1;
    else    
        x_step *= 1;
 
    game->rays->next_horizontal_touch_x = x_intercept;
    game->rays->next_horizontal_touch_y = y_intercept;

    //increment x_step and y_step until we find a wall
    while (game->rays->next_horizontal_touch_x >= 0 && game->rays->next_horizontal_touch_x <= WINDOW_WIDTH 
            && game->rays->next_horizontal_touch_y >= 0 && game->rays->next_horizontal_touch_y <= WINDOW_HEIGHT)
    {
        float x_to_check; //pixel to check
        float y_to_check;

        x_to_check = game->rays->next_horizontal_touch_x;
            //float yToCheck = nextHorzTouchY + (isRayFacingUp ? -1 : 0);
            //float yToCheck = nextHorzTouchY + -1
            //float yToCheck = nextHorzTouchY + 0

        //float y_to_check = game->rays->next_horizontal_touch_y + (game->rays->is_ray_facing_up ? -1 : 0);
        if (game->rays->is_ray_facing_up)
            y_to_check = game->rays->next_horizontal_touch_y -1;
        else
            y_to_check = game->rays->next_horizontal_touch_y + 0;     
        if (has_wall(x_to_check, y_to_check, game))
        {
            // found a wall hit
            game->rays->horizontal_wall_hit_x = game->rays->next_horizontal_touch_x;
            game->rays->horizontal_wall_hit_y = game->rays->next_horizontal_touch_y;
            game->rays->horizontal_wall_content = game->map.file[(int)floor(y_to_check / TILE_SIZE)][(int)floor(x_to_check / TILE_SIZE)];
            game->rays->found_horizontal_wall_hit = true;
            break;
        } 
        else
        {
            game->rays->next_horizontal_touch_x += x_step;
            game->rays->next_horizontal_touch_y += y_step;
        }
    }


    ///////////////////////////////////////////
    // VERTICAL RAY-GRID INTERSECTION CODE
    ///////////////////////////////////////////
    
    game->rays->found_vertical_wall_hit = false;
    game->rays->vertical_wall_hit_x = 0;
    game->rays->vertical_wall_hit_y = 0;
    game->rays->vertical_wall_content = 0;

    // Find the x-coordinate of the closest horizontal grid intersection
    x_intercept = floor(game->player.pos_x / TILE_SIZE) * TILE_SIZE;
        //x_intercept += isRayFacingRight ? TILE_SIZE : 0;
    if (game->rays->is_ray_facing_right)
        x_intercept += TILE_SIZE;
    else
        x_intercept += 0;

    // Find the y-coordinate of the closest horizontal grid intersection
    y_intercept = game->player.pos_y + (x_intercept - game->player.pos_x) * tan(ray_angle);

    // Calculate the increment xstep and ystep
    x_step = TILE_SIZE;
        //xstep *= isRayFacingLeft ? -1 : 1;
    if (game->rays->is_ray_facing_left)
        x_step *= -1;
    else   
        x_step *= 1;

    y_step = TILE_SIZE * tan(ray_angle);
        //ystep *= (isRayFacingUp && ystep > 0) ? -1 : 1;
    if (game->rays->is_ray_facing_up && y_step > 0)
        y_step *= -1;
    else
        y_step *= 1;

        //ystep *= (isRayFacingDown && ystep < 0) ? -1 : 1;
    if (game->rays->is_ray_facing_down && y_step < 0)
        y_step *= -1;
    else
        y_step *= 1;
    
    game->rays->next_vertical_touch_x = x_intercept;
    game->rays->next_vertical_touch_y = y_intercept;

    // Increment xstep and ystep until we find a wall
    while (game->rays->next_vertical_touch_x >= 0 && game->rays->next_vertical_touch_x <= WINDOW_WIDTH
            && game->rays->next_vertical_touch_y >= 0 && game->rays->next_vertical_touch_y <= WINDOW_HEIGHT)
    {
        float x_to_check;
        float y_to_check;

            //x_to_check = game->rays->next_vertical_touch_x + (game->rays->is_ray_facing_left ? -1 : 0);
        if (game->rays->is_ray_facing_left)
            x_to_check = game->rays->next_vertical_touch_x -1;
        else
            x_to_check = game->rays->next_vertical_touch_x + 0;
        
        y_to_check = game->rays->next_vertical_touch_y;
        
        if (has_wall(x_to_check, y_to_check, game))
        {
            // found a wall hit
            game->rays->vertical_wall_hit_x = game->rays->next_vertical_touch_x;
            game->rays->vertical_wall_hit_y = game->rays->next_vertical_touch_y;
            game->rays->vertical_wall_content = game->map.file[(int)floor(y_to_check / TILE_SIZE)][(int)floor(x_to_check / TILE_SIZE)];
            game->rays->found_vertical_wall_hit = true;
            break;
        } 
        else 
        {
            game->rays->next_vertical_touch_x += x_step;
            game->rays->next_vertical_touch_y += y_step;
        }
    }
    ////////////////////////////////////////////////////////////////////////////////////
    // Calculate both horizontal and vertical hit distances and choose the smallest one
   calcule_smallest_distance(ray_angle, strip_id, game);
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