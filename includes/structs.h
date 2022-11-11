/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 11:37:50 by joeduard          #+#    #+#             */
/*   Updated: 2022/11/11 13:23:26 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef enum e_bool
{
	false,
	true
}	t_bool;

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
//	double	rotation_speed;

}				t_player;


typedef struct	s_map
{
	char	**file;
	int		row;
	int		col;
	int		player;
	int		space;
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

typedef struct	s_game
{
	t_img		img;
	t_map		map;
	t_player 	player;

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


#endif