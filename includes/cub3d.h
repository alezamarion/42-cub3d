#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
//# include "../libraries/mlx-linux/mlx.h"
# include "../libraries/libft/libft.h"

typedef struct	s_game
{
	char	**map;



}				t_game;

typedef struct	s_map
{
	int		map_row_size;
	int		map_col_size;
	int		player;
	int		exit;
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



#endif
