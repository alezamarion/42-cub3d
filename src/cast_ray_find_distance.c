/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_ray_find_distance.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 22:07:50 by azamario          #+#    #+#             */
/*   Updated: 2022/11/27 15:59:20 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	vert_less_horiz(double vert_hit_dist, int strip_id, t_game *game)
{
	game->rays[strip_id].distance = vert_hit_dist;
	game->rays[strip_id].wall_hit_x = game->rays->vert_wall_hit_x;
	game->rays[strip_id].wall_hit_y = game->rays->vert_wall_hit_y;
	game->rays[strip_id].was_hit_vertical = true;
}

static void	horiz_less_vert(double htz_hit_dist, int strip_id, t_game *game)
{
	game->rays[strip_id].distance = htz_hit_dist;
	game->rays[strip_id].wall_hit_x = game->rays->horiz_wall_hit_x;
	game->rays[strip_id].wall_hit_y = game->rays->horiz_wall_hit_y;
	game->rays[strip_id].was_hit_vertical = false;
}

static void	other_rays_setup(double ray_angle, int strip_id, t_game *game)
{
	int		x;
	int		y;

	game->rays[strip_id].ray_angle = ray_angle;
	x = (int)game->rays[strip_id].wall_hit_x / TILE_SIZE;
	y = (int)game->rays[strip_id].wall_hit_y / TILE_SIZE;
	game->rays[strip_id].wall_hit_content = game->map.map[y][x];
	game->rays[strip_id].is_ray_facing_down = game->rays->is_ray_facing_down;
	game->rays[strip_id].is_ray_facing_up = game->rays->is_ray_facing_up;
	game->rays[strip_id].is_ray_facing_left = game->rays->is_ray_facing_left;
	game->rays[strip_id].is_ray_facing_right = game->rays->is_ray_facing_right;
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
