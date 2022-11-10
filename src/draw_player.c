

#include "../includes/cub3d.h"

void	render_player(t_game *game, int x, int y, int color)
{
	int i;
	int j;

	x *= TILE_SIZE;
	y *= TILE_SIZE;
	i = 0;
	while (i < TILE_SIZE)
	{
		j = 0;
		while (j < TILE_SIZE)
		{
			game->img.data[(y + i) * game->map.col * TILE_SIZE + x + j] = color;
			j++;
		}
		i++;
	}
}

void	draw_player(t_game *game)
{
	int		i;
	int		j;

	i = 0;
	while (i < game->map.row)
	{
		j = 0;
		while (j < game->map.col)
		{
			if (game->map.file[i][j] == 'N')
				render_player(game, j, i, 0x8FCE00);
			j++;
		}
		i++;
	}
}