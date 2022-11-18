/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_ray_find_distance.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 22:07:50 by azamario          #+#    #+#             */
/*   Updated: 2022/11/17 19:17:37 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	vert_smallest_horiz(float vert_hit_dist, int strip_id, t_game *game)
{
	game->rays[strip_id].distance = vert_hit_dist;
	game->rays[strip_id].wall_hit_x = game->rays->vert_wall_hit_x;
	game->rays[strip_id].wall_hit_y = game->rays->vert_wall_hit_y;
	game->rays[strip_id].wall_hit_content = game->rays->vert_wall_content;
	game->rays[strip_id].was_hit_vertical = true;
}

static void	horiz_smallest_vert(float horiz_hit_dist, int strip_id, t_game *game)
{
	game->rays[strip_id].distance = horiz_hit_dist;
	game->rays[strip_id].wall_hit_x = game->rays->horiz_wall_hit_x;
	game->rays[strip_id].wall_hit_y = game->rays->horiz_wall_hit_y;
	game->rays[strip_id].wall_hit_content = game->rays->horiz_wall_content;
	game->rays[strip_id].was_hit_vertical = false;
}

// Calculate both horizontal and vertical hit dist. and choose the smallest one
void	choose_smalest_distance(float ray_angle, int strip_id, t_game *game)
{
	float	horiz_hit_distance;
	float	vert_hit_distance;

	// horiz_hit_distance = game->rays->found_horiz_wall_hit ? distance_between_points(game->player.posX, game->player.posY, game->rays->horiz_wall_hit_x, game->rays->horiz_wall_hit_y) : FLT_MAX;
	if (game->rays->found_horiz_wall_hit)
		horiz_hit_distance = distance_between_points(game->player.posX, \
			game->player.posY, game->rays->horiz_wall_hit_x, \
				game->rays->horiz_wall_hit_y);
	else
		horiz_hit_distance = FLT_MAX;
	// vert_hit_distance = game->rays->found_vert_wall_hit ? distance_between_points(game->player.posX, game->player.posY, game->rays->vert_wall_hit_x, game->rays->vert_wall_hit_y) : FLT_MAX;
	if (game->rays->found_vert_wall_hit)
		vert_hit_distance = distance_between_points(game->player.posX,
				game->player.posY, game->rays->vert_wall_hit_x,
				game->rays->vert_wall_hit_y);
	else
		vert_hit_distance = FLT_MAX;
	if (vert_hit_distance < horiz_hit_distance)
		vert_smallest_horiz(vert_hit_distance, strip_id, game);
	else
		horiz_smallest_vert(horiz_hit_distance, strip_id, game);
	game->rays[strip_id].ray_angle = ray_angle;
	game->rays[strip_id].is_ray_facing_down = game->rays->is_ray_facing_down;
	game->rays[strip_id].is_ray_facing_up = game->rays->is_ray_facing_up;
	game->rays[strip_id].is_ray_facing_left = game->rays->is_ray_facing_left;
	game->rays[strip_id].is_ray_facing_right = game->rays->is_ray_facing_right;
}
