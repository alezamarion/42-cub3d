/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 15:14:37 by azamario          #+#    #+#             */
/*   Updated: 2022/11/22 10:04:30 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	has_wall(float x, float y, t_game *game)
{
	int	map_grid_index_x;
	int	map_grid_index_y;

	map_grid_index_x = (int)floor((x / TILE_SIZE));
	map_grid_index_y = (int)floor((y / TILE_SIZE));
	if (x < 0 || x > WINDOW_WIDTH || y < 0 || y > WINDOW_HEIGHT)
		return (true);
	return (game->map.file[map_grid_index_y][map_grid_index_x] == '1');
}

void	normalize_angle_move_player(float *angle)
{
	*angle = remainder(*angle, TWO_PI);
	if (*angle < 0)
		*angle = TWO_PI + *angle;
}

void	calculate_next_step(t_game *game, int move_step, int side_step)
{
	float	new_player_x;
	float	new_player_y;

	new_player_x = (game->player.pos_x
			+ cos(game->player.rotation_angle) * move_step)
		+ (cos(game->player.rotation_angle + (PI / 2)) * side_step);
	new_player_y = (game->player.pos_y
			+ sin(game->player.rotation_angle) * move_step)
		+ (sin(game->player.rotation_angle + (PI / 2)) * side_step);
	if (!has_wall(new_player_x, new_player_y, game))
	{	
		game->player.pos_x = new_player_x;
		game->player.pos_y = new_player_y;
	}
}

void	move_player(t_game *game)
{
	int	move_step;
	int	side_step;

	if (game->player.turn_direction)
	{
		game->player.rotation_angle += game->player.turn_direction
			* game->player.turn_speed;
		normalize_angle_move_player(&game->player.rotation_angle);
	}
	if (game->player.side_direction || game->player.walk_direction)
	{
		move_step = game->player.walk_direction * game->player.walk_speed;
		side_step = game->player.side_direction * game->player.walk_speed;
		if (game->player.side_direction && game->player.walk_direction)
		{
			move_step /= 2;
			side_step /= 2;
		}
		calculate_next_step(game, move_step, side_step);
	}
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
