

#include "../includes/cub3d.h"

void	draw_player(t_game *game)
{
	int i;
	int j;

	int x;
	int y;

	x = (int)game->player.posX - 8;
	y = (int)game->player.posY - 8;

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
