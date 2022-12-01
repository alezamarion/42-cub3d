/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_ray_find_distance.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 22:07:50 by azamario          #+#    #+#             */
/*   Updated: 2022/11/28 06:22:01 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

double	normalize_angle_cast_ray(double angle)
{
	angle = remainder(angle, TWO_PI);
	if (angle < 0)
		angle = TWO_PI + angle;
	return (angle);
}

static void	get_ray_content(t_game *game, t_ray *ray)
{
	int	x;
	int	y;

	if (ray->was_hit_vertical)
	{
		x = (int)floor((ray->wall_hit_x - ray->is_ray_facing_left) / TILE_SIZE);
		y = (int)floor(ray->wall_hit_y / TILE_SIZE);
	}
	else
	{
		x = (int)floor(ray->wall_hit_x / TILE_SIZE);
		y = (int)floor((ray->wall_hit_y - ray->is_ray_facing_up) / TILE_SIZE);
	}
	ray->wall_hit_content = game->map.map[y][x];
}

static void	other_rays_setup(double ray_angle, int strip_id, t_game *game)
{
	game->rays[strip_id].ray_angle = ray_angle;
	game->rays[strip_id].is_ray_facing_down = game->rays->is_ray_facing_down;
	game->rays[strip_id].is_ray_facing_up = game->rays->is_ray_facing_up;
	game->rays[strip_id].is_ray_facing_left = game->rays->is_ray_facing_left;
	game->rays[strip_id].is_ray_facing_right = game->rays->is_ray_facing_right;
	get_ray_content(game, game->rays + strip_id);
}

// Calculate both horizontal and vertical hit dist. and choose the smallest one
void	choose_smalest_distance(double ray_angle, int strip_id, t_game *game)
{
	double	horiz_hit_distance;
	double	vert_hit_distance;

	if (game->rays->found_horiz_wall_hit)
		horiz_hit_distance = distance_between_points(game->player.pos_x, \
			game->player.pos_y, game->rays->horiz_wall_hit_x, \
				game->rays->horiz_wall_hit_y);
	else
		horiz_hit_distance = __FLT_MAX__;
	if (game->rays->found_vert_wall_hit)
		vert_hit_distance = distance_between_points(game->player.pos_x,
				game->player.pos_y, game->rays->vert_wall_hit_x,
				game->rays->vert_wall_hit_y);
	else
		vert_hit_distance = __FLT_MAX__;
	if (vert_hit_distance < horiz_hit_distance)
		vert_less_horiz(vert_hit_distance, strip_id, game);
	else
		horiz_less_vert(horiz_hit_distance, strip_id, game);
	other_rays_setup(ray_angle, strip_id, game);
}
