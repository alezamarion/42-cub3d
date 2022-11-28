/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_all_rays.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 16:44:17 by azamario          #+#    #+#             */
/*   Updated: 2022/11/27 23:39:53 by azamario         ###   ########.fr       */
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

double	distance_between_points(double x1, double y1, double x2, double y2)
{
	double	result;

	result = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
	return (result);
}

void	where_is_ray_facing(double ray_angle, t_game *game)
{
	game->rays->is_ray_facing_down
		= ray_angle > 0 && ray_angle < PI;
	game->rays->is_ray_facing_up = !game->rays->is_ray_facing_down;
	game->rays->is_ray_facing_right
		= ray_angle < HALF_PI || ray_angle > PI_PLUS_HALF_PI;
	game->rays->is_ray_facing_left = !game->rays->is_ray_facing_right;
}

void	cast_ray(double ray_angle, int strip_id, t_game *game)
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
	double	ray_angle;
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
