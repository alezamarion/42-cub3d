#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <math.h>
# include "../libraries/mlx-linux/mlx.h"
# include "../libraries/libft/libft.h"

# define XK_MISCELLANY
# include <X11/keysymdef.h>
# include <X11/keysym.h>
# include <X11/X.h>

# include "defines.h"
# include "erros.h"
# include "structs.h"

//read_map.c
char	**read_map(char *path_to_file);

//map_check.c
int		has_valid_walls(char **map, t_game *game);
int		has_valid_chars(char **map);
int		has_minimum_chars(char **map, t_game *game);
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
void	print_map(char **map);

//event_handler
void    event_handler(t_game *game);

//exit_game.c
int 	exit_game(t_game *game);
void    free_map(char **map);

//player_update.c
void    player_update(int keycode, t_game *game);

//move_player.c
void    handle_situation(t_game *game, int x, int y);

//map_render.c
void	map_render(char **map, t_game *game);
void    draw_image(t_game *game, void *image, int x, int y);

//hook_player.c
void	hook_player(t_game *game, int i, int j);

//main_loop.c
int		render_game(t_game *game);

//draw_minimap
void	draw_line(t_game *game, double x1, double y1, double x2, double y2);
void 	draw_lines(t_game *game);
void	draw_rectangle(t_game *game, int x, int y, int color);
void	draw_rectangles(t_game *game);

//draw_player.c
void	draw_player(t_game *game);
void	render_player(t_game *game, int x, int y, int color);

 // validation.c
 t_bool	validation(t_game *game, int argc, char **argv);
 t_bool	print_error(char *error);

 // validate_map.c
 int	is_valid_map(char **map, char *file, t_game *game);

 void cast_all_rays(t_game *game);

#endif
