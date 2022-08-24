#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include "../libraries/mlx-linux/mlx.h"
# include "../libraries/libft/libft.h"

# define SPRITE_SIZE 32

# define FILE_WALL "textures/bart_wall.xpm"
# define FILE_EMPTY "textures/bart_space.xpm"
# define FILE_COLLECTIBLE "textures/bart_collectible.xpm"
# define FILE_EXIT "textures/bart_exit.xpm"
# define FILE_PLAYER_U "textures/bart_up.xpm"
# define FILE_PLAYER_D "textures/bart_down.xpm"
# define FILE_PLAYER_L "textures/bart_left.xpm"
# define FILE_PLAYER_R "textures/bart_right.xpm"


typedef struct	s_game
{
	void	*mlx;
	void	*image;
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

}				t_game;

typedef struct	s_map
{
	int		map_row_size;
	int		map_col_size;
	int		player;
	int		collectible;
	int		space;
}				t_map;


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

#endif
