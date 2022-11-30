/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 11:37:50 by joeduard          #+#    #+#             */
/*   Updated: 2022/11/28 08:15:12 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "../libraries/mlx-linux/mlx_int.h"

typedef struct s_player
{	
	double	pos_x;
	double	pos_y;
	double	new_player_x;
	double	new_player_y;
	int		turn_direction;
	int		walk_direction;
	int		side_direction;
	double	rotation_angle;
	double	walk_speed;
	double	turn_speed;
}				t_player;

typedef struct s_map
{
	char	**map;
	char	**file;
	size_t	row;
	size_t	col;
	size_t	line_size;
	int		player;
	int		space;
	int		wall;
	void	*img;
	int		number_of_players;
	int		minimap_height;
	int		minimap_width;
}				t_map;

typedef struct s_wall
{
	double		perpend_dist;
	double		dist_proj_plane;
	double		proj_wall_height;
	int			strip_height;
	int			top_pixel;
	int			botton_pixel;
	int			text_offset_x;
	int			text_offset_y;
	int			dist_from_top;
	int			pix_color;
}				t_wall;

typedef struct ray
{
	double	ray_angle;
	double	rotation_angle;
	double	wall_hit_x;
	double	wall_hit_y;
	double	distance;
	int		was_hit_vertical;
	int		wall_hit_content;
	int		is_ray_facing_up;	
	int		is_ray_facing_down;	
	int		is_ray_facing_left;	
	int		is_ray_facing_right;
	double	horiz_wall_hit_x;
	double	horiz_wall_hit_y;
	double	vert_wall_hit_x;
	double	vert_wall_hit_y;
	double	horiz_x;
	double	horiz_y;
	double	vert_x;
	double	vert_y;
	int		found_horiz_wall_hit;
	int		found_vert_wall_hit;
	int		horiz_wall_content;
	int		vert_wall_content;
}				t_ray;

typedef struct s_param
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*celling;
	char	*ground;
	int		celling_collor;
	int		ground_collor;
	int		number_of_colors;

}				t_param;

typedef struct s_images
{
	int			*color_buffer;
	t_img		*structure;

}				t_image;

typedef struct s_game
{
	t_map				map;
	t_player			player;
	t_ray				rays[NUM_RAYS];
	t_param				param;
	t_image				no;
	t_image				so;
	t_image				we;
	t_image				ea;
	t_image				img;
	void				*mlx;
	void				*window;
	void				*empty_space;
	int					image_width;
	int					image_height;
	int					end_game;
	char				*file_content;
	double				horiz_x_step;
	double				horiz_y_step;
	double				vert_x_step;
	double				vert_y_step;
}							t_game;

typedef enum e_bool
{
	false,
	true
}	t_bool;

typedef enum e_column_limits
{
	TOP_LINE,
	BOT_LINE
}			t_column_limits;

#endif