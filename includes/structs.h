/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 11:37:50 by joeduard          #+#    #+#             */
/*   Updated: 2022/11/17 18:34:59 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

//# define NUM_RAYS WINDOW_WIDTH

typedef struct s_player
{	
	float	posX;
	float	posY;
	int		turn_direction;
	int		walk_direction;
	int		side_direction;
	float	rotation_angle;
	float	walk_speed;
	float	turn_speed;
}				t_player;


typedef struct	s_map
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
	void 	*img;
	int		*data;
	//You don't need to understand the 3 values below.
	//After declaration, it will be automatically initialized when passed to mlx_new_data_add function
	int		size_l;
	int		bpp;
	int		endian;
	
}				t_img;

typedef struct ray		//verificar se todos estao sendo usados
{
	float 	ray_angle;
	float	rotation_angle;
	float 	wall_hit_x;
	float 	wall_hit_y;
	float 	distance;
	int		was_hit_vertical;
	int		wall_hit_content;

	int		is_ray_facing_up;	
	int		is_ray_facing_down;	
	int		is_ray_facing_left;	
	int		is_ray_facing_right;

	int		found_horiz_wall_hit;
	float	horiz_wall_hit_x;
	float	horiz_wall_hit_y;
	int		horiz_wall_content;

	int		found_vert_wall_hit;
	float	vert_wall_hit_x;
	float	vert_wall_hit_y;
	int		vert_wall_content;
}				t_ray;


typedef struct	s_game
{
	t_img		img;
	t_map		map;
	t_player 	player;
	t_ray		rays[NUM_RAYS];

	void	*mlx;
	void	*window;
	void	*wall;
	void	*empty_space;
	int		image_width;
	int		image_height;
	int		window_width;
	int		window_height;
	int		end_game;

}				t_game;

typedef enum e_bool
{
	false,
	true
}	t_bool;

#endif