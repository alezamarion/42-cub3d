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

# define XK_MISCELLANY //porque esse define vem antes das libs abaixo?
# include <X11/keysymdef.h>
# include <X11/keysym.h>
# include <X11/X.h>

# define MLX_ERROR "MLX_ERROR: Could not initialize or create window"

//----------------------------- do novo repo:


# define TILE_SIZE 32
# define ROWS 11
# define COLS 15
# define WIDTH COLS * TILE_SIZE
# define HEIGHT ROWS * TILE_SIZE

# define TO_COORD(X, Y) ((int)floor(Y) * WIDTH + (int)floor(X))

//-----------------------------

# define WINDOW_WIDTH 1024
# define WINDOW_HEIGHT 512

# define X_EVENT_KEY_EXIT 17
# define KEY_ESC 53

# define X_EVENT_KEY_PRESS 2
//# define X_EVENT_DESTROY_NOTIFY 17
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115 
# define KEY_D 100

# define KEY_UP 65362
# define KEY_LEFT 65361
# define KEY_DOWN 65364
# define KEY_RIGHT 65363



typedef struct	s_map
{
	int		row;
	int		col;
	int		player;
	int		space;
}				t_map;


//do novo repo:
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
	void	*mlx;
	void	*window;
	void	*wall;
	void	*empty_space;
	int		*player;
	char	**map;
	int		image_width;
	int		image_height;
	int		window_width;
	int		window_height;
	int		end_game;
	int		x;
	int		y;

	t_img	img;		//do novo repo
	t_map	map_attributes;

}				t_game;


//read_map.c
char	**read_map(char *path_to_file);

//valid_map.c
int		is_valid_map(char **map, char *file, t_game *game);

//map_check.c
int		has_valid_walls(char **map, t_game *game);
int		has_valid_chars(char **map);
int		has_minimum_chars(char **map, t_game *game);
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
int		render_map(t_game *game);

//hook_player
//void    hook_player(t_game *game, int x, int y);

#endif
