/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 11:37:50 by joeduard          #+#    #+#             */
/*   Updated: 2022/11/22 10:17:12 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

//# define NUM_RAYS WINDOW_WIDTH

typedef struct s_player
{	
	float	pos_x;
	float	pos_y;
	int		turn_direction;
	int		walk_direction;
	int		side_direction;
	float	rotation_angle;
	float	walk_speed;
	float	turn_speed;
}				t_player;
typedef struct s_map
{
	char	**file;
	int		row;
	int		col;
	int		player;
	int		space;
	void	*img;
}				t_map;

typedef struct s_img
{
	void	*img;
	int		*data;
	int		size_l;
	int		bpp;
	int		endian;
}				t_img;
typedef struct ray
{
	float	ray_angle;
	float	rotation_angle;
	float	wall_hit_x;
	float	wall_hit_y;
	float	distance;
	int		was_hit_vertical;
	int		wall_hit_content;
	int		is_ray_facing_up;	
	int		is_ray_facing_down;	
	int		is_ray_facing_left;	
	int		is_ray_facing_right;
	float	horiz_wall_hit_x;
	float	horiz_wall_hit_y;
	float	vert_wall_hit_x;
	float	vert_wall_hit_y;
	float	horiz_x;
	float	horiz_y;
	float	vert_x;
	float	vert_y;
	int		found_horiz_wall_hit;
	int		found_vert_wall_hit;
	int		horiz_wall_content;
	int		vert_wall_content;
}				t_ray;
typedef struct s_game
{
	t_img		img;
	t_map		map;
	t_player	player;
	t_ray		rays[NUM_RAYS];
	void		*mlx;
	void		*window;
	void		*wall;
	void		*empty_space;
	int			image_width;
	int			image_height;
	int			window_width;
	int			window_height;
	int			end_game;
}				t_game;

typedef enum e_bool
{
	false,
	true
}	t_bool;

#endif