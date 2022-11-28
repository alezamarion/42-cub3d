/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 03:32:02 by joeduard          #+#    #+#             */
/*   Updated: 2022/11/28 08:09:58 by joeduard         ###   ########.fr       */
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

//read_map.c
char	**read_file(char *path_to_file);

//validate_map_info.c
int		is_valid_map_info(t_game *game);
int		has_valid_extension(char *file);

//exit_game.c
void	free_map(char **map);

//init_game.c
void	init_game(t_game *game);

//init_image.c
void	initialize_image(t_game *game);

//init_windown.c
void	init_window(t_game *game);

//map_utils.c
void	map_counter(char **map, t_game *game);
size_t	get_max_line_size(char **map, t_game *game);

//event_handler
void	move_player(t_game *game);
void	event_handler(t_game *game);
int		has_wall(double x, double y, t_game *game);
void	normalize_angle_move_player(double *angle);

//exit_game.c
int		exit_game(t_game *game);
void	free_map(char **map);
int		click_close(t_game *game);

//player_update.c
void	player_update(int keycode, t_game *game);

//move_player.c
void	handle_situation(t_game *game, int x, int y);

//map_render.c
void	map_render(char **map, t_game *game);
void	draw_image(t_game *game, void *image, int x, int y);

//hook_player.c
void	hook_player(t_game *game, int i, int j);

//render_game.c
void	strip_wall_projection(t_wall *wall, t_game *game, int i);
void	dist_text_color(t_wall wall, int *current_img, t_game *game, int i);
int		*get_right_texture(t_game *game, t_ray *ray);
void	wall_pixel(t_wall *wall, t_game *game, int i);
int		render_game(t_game *game);

//draw_minimap
void	draw_rectangle(t_game *game, int x, int y, int color);
void	draw_rectangles(t_game *game);

//draw_player.c
void	draw_player(t_game *game);
void	render_player(t_game *game, int x, int y, int color);

//cast_all_rays.c
void	generate_3d_projection(t_game *game);
void	cast_all_rays(t_game *game);
void	cast_ray(double ray_angle, int strip_id, t_game *game);
double	distance_between_points(double x1, double y1, double x2, double y2);
double	normalize_angle_cast_ray(double angle);

//cast_ray.c
void	where_is_ray_facing(double ray_angle, t_game *game);
void	choose_smalest_distance(double ray_angle, int strip_id, t_game *game);

//cast_ray_horizontal.c
void	horiz_less_vert(double htz_hit_dist, int strip_id, t_game *game);
void	find_horizontal_intersection(double ray_angle, t_game *game);

//cast_ray_vertical.c
void	vert_less_horiz(double vert_hit_dist, int strip_id, t_game *game);
void	find_vertical_intersection(double ray_angle, t_game *game);

// validation.c
t_bool	print_error(char *error, t_game *game);
t_bool	validation(t_game *game, int argc, char **argv);

//color
void	save_colors(char *file, int identifier, t_game *game);
int		is_color(char *file, int *identifier);

//map.c
int		is_map(char *file);
char	*get_map(char *file);

//validate_input_file
int		validate_input_file(t_game *game);

//validate_colors
int		validate_colors(char *color);

//is_map_playable.c
void	is_map_playable(t_game *game);

//is_map_playable_utils.c
void	resize_line(t_game *game);
void	resize_column(t_game *game);

//is_map_playable_utils2.c
size_t	count_vectors(void **matrix);
int		is_out_of_range(int n);

#endif