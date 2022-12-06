/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_game2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 16:44:17 by azamario          #+#    #+#             */
/*   Updated: 2022/12/01 15:35:13 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	generate_3d_projection(t_game *game)
{
	int			i;
	t_wall		wall;
	int			*current_img;

	i = 0;
	ft_bzero(&wall, sizeof(t_wall));
	while (i++ < NUM_RAYS)
	{
		strip_wall_projection(&wall, game, i);
		wall_pixel(&wall, game, i);
		if (game->rays[i].was_hit_vertical)
			wall.text_offset_x = (int)game->rays[i].wall_hit_y % TILE_SIZE;
		else
			wall.text_offset_x = (int)game->rays[i].wall_hit_x % TILE_SIZE;
		current_img = get_right_texture(game, game->rays + i);
		while (wall.top_pixel++ < wall.botton_pixel)
		{
			dist_text_color(wall, current_img, game, i);
		}
	}
}

void	where_is_ray_facing(double ray_angle, t_game *game)
{
	game->rays->is_ray_facing_down = ray_angle > 0 && ray_angle < PI;
	game->rays->is_ray_facing_up = !game->rays->is_ray_facing_down;
	game->rays->is_ray_facing_right = ray_angle < HALF_PI
		|| ray_angle > PI_PLUS_HALF_PI;
	game->rays->is_ray_facing_left = !game->rays->is_ray_facing_right;
}

double	distance_between_points(double x1, double y1, double x2, double y2)
{
	double	result;

	result = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
	return (result);
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
