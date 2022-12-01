/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 22:11:09 by azamario          #+#    #+#             */
/*   Updated: 2022/11/27 21:33:18 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	draw_player(t_game *game)
{
	int	i;
	int	j;
	int	x;
	int	y;

	x = (int)game->player.pos_x - 8;
	y = (int)game->player.pos_y - 8;
	i = 0;
	while (i < 16)
	{
		j = 0;
		while (j < 16)
		{
			game->img.color_buffer[(y + i) * game->map.col * \
			TILE_SIZE + x + j] = YELLOW;
			j++;
		}
		i++;
	}
}

void	normalize_angle_move_player(double *angle)
{
	*angle = remainder(*angle, TWO_PI);
	if (*angle < 0)
		*angle = TWO_PI + *angle;
}

void	calculate_next_step(t_game *game, int move_step, int side_step)
{
	double	new_player_x;
	double	new_player_y;

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
