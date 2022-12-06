/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 03:32:02 by joeduard          #+#    #+#             */
/*   Updated: 2022/12/06 11:03:50 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <stdint.h>
# include <math.h>
# include <limits.h>
# include "../libraries/mlx-linux/mlx.h"
# include "../libraries/libft/libft.h"

# include "defines.h"
# include "error.h"
# include "structs.h"

//# define XK_MISCELLANY //porque esse define vem antes das libs abaixo?
# include <X11/keysymdef.h>
# include <X11/keysym.h>
# include <X11/X.h>

//VALIDATION
//validation.c
t_bool	validation(t_game *game, int argc, char **argv);

//save_file_info.c
void	save_file_info(char **file, t_game *game);

//save_file_info1.c
int	    is_color(char *file, int *identifier);
void	save_colors(char *file, int identifier, t_game *game);
void	save_colors(char *file, int identifier, t_game *game);
int		is_color(char *file, int *identifier);

//map_info_validate.c
int		map_info_validate(t_game *game);
int		is_map(char *file);
char	*get_map(char *file);

//is_map_playable.c
void	is_map_playable(t_game *game);

//is_map_playable1.c
void	check_line(t_game *game);
void	check_column(t_game *game);
size_t	count_vectors(void **matrix);
int		is_out_of_range(int n);

//read_file.c
char	**read_file(char *path_to_file);

//INIT_GAME
//init_game.c
void	init_game(t_game *game);

//map_counter.c
void	map_counter(char **map, t_game *game);
size_t	get_max_line_size(char **map, t_game *game);

//init_windown.c
void	init_window(t_game *game);

//init_image.c
void	initialize_image(t_game *game);

//exit_game.c
void	free_map(char **map);
t_bool	print_error(char *error, t_game *game);
int		exit_game(t_game *game);
int		click_close(t_game *game);

//RENDER_GAME
//render_game.c
void	strip_wall_projection(t_wall *wall, t_game *game, int i);
void	dist_text_color(t_wall wall, int *current_img, t_game *game, int i);
int		*get_right_texture(t_game *game, t_ray *ray);
void	wall_pixel(t_wall *wall, t_game *game, int i);
int		render_game(t_game *game);
void	render_player(t_game *game, int x, int y, int color);

//move_player.c
void	move_player(t_game *game);
void	draw_player(t_game *game);

//cast_all_rays.c
void	generate_3d_projection(t_game *game);
void	cast_all_rays(t_game *game);
void	cast_ray(double ray_angle, int strip_id, t_game *game);
double	distance_between_points(double x1, double y1, double x2, double y2);
double	normalize_angle_cast_ray(double angle);

//draw_minimap
void	draw_rectangle(t_game *game, int x, int y, int color);
void	draw_rectangles(t_game *game);

//find_horizontal_intersection.c
void	horiz_less_vert(double htz_hit_dist, int strip_id, t_game *game);
void	find_horizontal_intersection(double ray_angle, t_game *game);

//find_vertical_intersection.c
void	vert_less_horiz(double vert_hit_dist, int strip_id, t_game *game);
void	find_vertical_intersection(double ray_angle, t_game *game);

//choose_smallest_distance.c
void	where_is_ray_facing(double ray_angle, t_game *game);
void	choose_smalest_distance(double ray_angle, int strip_id, t_game *game);

//EVENT_HANDLER
//event_handler
void	event_handler(t_game *game);
int		has_wall(double x, double y, t_game *game);

#endif