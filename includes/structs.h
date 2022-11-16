/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 11:37:50 by joeduard          #+#    #+#             */
/*   Updated: 2022/11/16 12:02:14 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# define NUM_RAYS WINDOW_WIDTH

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
}				t_map;

	//You don't need to understand the 3 values below.
	//After declaration, it will be automatically initialized
	//when passed to mlx_new_data_add function
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
	int		is_ray_facing_up;
	int		is_ray_facing_down;
	int		is_ray_facing_left;
	int		is_ray_facing_right;
	int		wall_hit_content;

    float horizontal_hit_distance;
    float vertical_hit_distance;

	int     found_horizontal_wall_hit;
    float   horizontal_wall_hit_x;
    float   horizontal_wall_hit_y;
    int     horizontal_wall_content;

	float next_horizontal_touch_x;
    float next_horizontal_touch_y;

	int found_vertical_wall_hit;
    float vertical_wall_hit_x;
    float vertical_wall_hit_y;
    int vertical_wall_content;

	float next_vertical_touch_x;
    float next_vertical_touch_y;
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
}					t_game;

typedef enum e_bool
{
	false,
	true
}	t_bool;

#endif