#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include "../libraries/mlx-linux/mlx.h"
# include "../libraries/libft/libft.h"

# define XK_MISCELLANY //porque esse define vem antes das libs abaixo?
# include <X11/keysymdef.h>
# include <X11/X.h>

//do novo repo:
# define KEY_ESC 53
# define TILE_SIZE 32
# define WIDTH 
# define TO_COORD(X, Y) ((int)floor(Y) * WIDTH + (int)floor(X))




# define X_EVENT_KEY_PRESS 2
# define X_EVENT_DESTROY_NOTIFY 17
# define KEY_W 199
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_UP 65362
# define KEY_LEFT 65361
# define KEY_DOWN 65364
# define KEY_RIGHT 65363

# define WINDOW_WIDTH 1024
# define WINDOW_HEIGHT 512

# define FILE_WALL "textures/bart_wall.xpm"
# define FILE_EMPTY "textures/bart_space.xpm"
# define FILE_COLLECTIBLE "textures/bart_collectible.xpm"
# define FILE_EXIT "textures/bart_exit.xpm"
# define FILE_PLAYER_U "textures/bart_up.xpm"
# define FILE_PLAYER_D "textures/bart_down.xpm"
# define FILE_PLAYER_L "textures/bart_left.xpm"
# define FILE_PLAYER_R "textures/bart_right.xpm"

# define SPRITE_SIZE 32

typedef struct	s_game
{
	void	*mlx;
//	void	*image;
	void	*window;
	void	*wall;
	void	*empty_space;
	void	*player_right;
	void	*player_left;
	void	*player_up;
	void	*player_down;
	char	**map;
	int		image_width;
	int		image_height;
	int		window_width;
	int		window_height;
	int		x;
	int		y;
	int		moves;
	int		player_direction;
	int		end_game;
	float	player_delta_x;
	float	player_delta_y;
	float	player_angle;

	t_image	image;		//do novo repo
	t_map	map;

}				t_game;

typedef struct	s_map
{
	int		map_row_size;
	int		map_col_size;
	int		player;
	int		collectible;
	int		space;
}				t_map;


//do novo repo:
typedef struct s_image
{
	void 	*image;
	int		*data;
	int		size_l;
	int		bits_per_pixel;
	int		endian;

}				t_image;

//read_map.c
char	**read_map(char *path_to_file);

//valid_map.c
int		is_valid_map(char **map, char *file);

//map_check.c
int		has_valid_walls(char **map, t_map *mp);
int		has_valid_chars(char **map);
int		has_minimum_chars(char **map, t_map *mp);
int		has_valid_extension(char *file);

//gnl
char	*get_next_line(int fd);

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

//game_utils.c
int 	key_press(int keycode, t_game *game);

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
int		main_loop(t_game *game)

#endif
