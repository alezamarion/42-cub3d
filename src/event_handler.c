/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 15:14:37 by azamario          #+#    #+#             */
/*   Updated: 2022/11/27 21:58:50 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	has_wall(double x, double y, t_game *game)
{
	int	map_grid_index_x;
	int	map_grid_index_y;

	map_grid_index_x = (int)floor((x / TILE_SIZE));
	map_grid_index_y = (int)floor((y / TILE_SIZE));
	if (x < 0 || x > TILE_SIZE * game->map.col || y < 0 || y > TILE_SIZE * game->map.row)
		return (true);
	return (game->map.map[map_grid_index_y][map_grid_index_x] == '1');
}

int	key_down(int keycode, t_game *game)
{
	if (keycode == XK_Escape)
		exit_game(game);
	if (keycode == 'w')
		game->player.walk_direction = +1;
	if (keycode == 's')
		game->player.walk_direction = -1;
	if (keycode == 'a')
		game->player.side_direction = -1;
	if (keycode == 'd')
		game->player.side_direction = +1;
	if (keycode == KEY_RIGHT)
		game->player.turn_direction = +1;
	if (keycode == KEY_LEFT)
		game->player.turn_direction = -1;
	return (0);
}

int	key_up(int keycode, t_game *game)
{
	if (keycode == 'w')
		game->player.walk_direction = 0;
	if (keycode == 's')
		game->player.walk_direction = 0;
	if (keycode == 'a')
		game->player.side_direction = 0;
	if (keycode == 'd')
		game->player.side_direction = 0;
	if (keycode == KEY_RIGHT)
		game->player.turn_direction = 0;
	if (keycode == KEY_LEFT)
		game->player.turn_direction = 0;
	return (0);
}

void	event_handler(t_game *game)
{
	mlx_hook(game->window, 2, 1l << 0, &key_down, game);
	mlx_hook(game->window, 3, 1l << 1, &key_up, game);
	mlx_hook(game->window, X_EVENT_KEY_EXIT, 0, &click_close, game);
}
