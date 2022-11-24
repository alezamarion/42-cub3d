/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_all_rays.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 16:44:17 by azamario          #+#    #+#             */
/*   Updated: 2022/11/24 11:31:58 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

float	normalize_angle_cast_ray(float angle)
{
	angle = remainder(angle, TWO_PI);
	if (angle < 0)
		angle = TWO_PI + angle;
	return (angle);
}

float	distance_between_points(float x1, float y1, float x2, float y2)
{
	float	result;

	result = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
	return (result);
}

void	where_is_ray_facing(float ray_angle, t_game *game)
{
	game->rays->is_ray_facing_down = ray_angle > 0 && ray_angle < PI;
	game->rays->is_ray_facing_up = !game->rays->is_ray_facing_down;
	game->rays->is_ray_facing_right = ray_angle < 0.5 * PI || ray_angle > 1.5
		* PI;
	game->rays->is_ray_facing_left = !game->rays->is_ray_facing_right;
}

void	cast_ray(float ray_angle, int strip_id, t_game *game)
{
	ray_angle = normalize_angle_cast_ray(ray_angle);
	where_is_ray_facing(ray_angle, game);
	find_horizontal_intersection(ray_angle, game);
	find_vertical_intersection(ray_angle, game);
	choose_smalest_distance(ray_angle, strip_id, game);
}

//start first ray subtracting half of our FOV
void	cast_all_rays(t_game *game)
{
	float	ray_angle;
	int		strip_id;

	ray_angle = game->player.rotation_angle - (FOV_ANGLE / 2);
	strip_id = 0;
	while (strip_id < NUM_RAYS)
	{
		cast_ray(ray_angle, strip_id, game);
		ray_angle += FOV_ANGLE / NUM_RAYS;
		strip_id++;
	}
}
