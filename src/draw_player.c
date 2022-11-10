

#include "../includes/cub3d.h"

void	draw_player(t_game *game)
{
	int i;
	int j;

	int x;
	int y;

	x = (int)game->player.posX - 8; //TILE_SIZE * TILE_SIZE;
	y = (int)game->player.posY - 8; /// TILE_SIZE * TILE_SIZE;

	// printf("\nposX: %f, posY: %f\n", game->player.posX, game->player.posY);
	// printf("x: %d, y: %d\n\n", x, y);


	i = 0;
	while (i < 16)
	{
		j = 0;
		while (j < 16)
		{
			game->img.data[(y + i) * game->map.col * TILE_SIZE + x + j] = 0x8FCE00;
			// int result = ((y + i) * game->map.col * TILE_SIZE + x + j);
			// printf("RESULT: %d", result);

			j++;
		}
		i++;
	}
}



/*
void	render_player(t_game *game, int x, int y, int color)
{
	int i;
	int j;

	x *= TILE_SIZE;
	y *= TILE_SIZE;
	i = 0;

	printf("\nx: %d, y: %d\n\n", x, y);

	while (i < TILE_SIZE)
	{
		j = 0;
		while (j < TILE_SIZE)
		{
			game->img.data[(y + i) * game->map.col * TILE_SIZE + x + j] = color;
			int result = ((y + i) * game->map.col * TILE_SIZE + x + j);
			printf("RESULT: %d", result);
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
*/