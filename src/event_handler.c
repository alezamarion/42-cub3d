/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 15:14:37 by azamario          #+#    #+#             */
/*   Updated: 2022/10/28 14:24:37 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"


static int click_close(t_game *game)
{
    exit_game(game);
    return (0);
}

// void    swap_positions(char *curr_p, char *next_p, char curr_value, char next_value)
// {
//     *curr_p = next_value;
//     *next_p = curr_value;
// }

// void    handle_0(t_game *game, int x, int y)
// {
//     int i;
//     int j;

//     i = game->player.posX;
//     j = game->player.posY;
//     swap_positions(&game->map.file[i][j], &game->map.file[x][y], 'N', '0');
//     game->player.posX = x;
//     game->player.posY = y;
// }

// void    handle_situation(t_game *game, int x, int y)
// {
//     printf("handle situation x: %d, y: %d\n", x, y);
//     if (game->map.file[x][y] != '1')
//     {
//         if (game->map.file[x][y] == '0')
//             handle_0(game, x, y);
//     }
// }

// static void	render_playerI(t_game *game, float x, float y, int color)
// {
// 	float i;
// 	float j;

// 	x *= TILE_SIZE;
// 	y *= TILE_SIZE;
// 	i = 0;
// 	while (i < TILE_SIZE)
// 	{
// 		j = 0;
// 		while (j < TILE_SIZE)
// 		{
// 			game->img.data[(y + i) * game->map.col * TILE_SIZE + x + j] = color;
// 			j++;
// 		}
// 		i++;
// 	}
// }



void    move_player(t_game *game)
{
    printf("move_player\n\n");
    float move_step;
    float new_player_x;
    float new_player_y; 
    
    game->player.rotation_angle += game->player.turn_direction * game->player.turn_speed;
    move_step = game->player.walk_direction * game->player.walk_speed;
 
    new_player_x = game->player.posX + cos(game->player.rotation_angle) * move_step;
    new_player_y = game->player.posY + sin(game->player.rotation_angle) * move_step;

    printf("player.posX %f, player.posY %f\n\n", game->player.posX, game->player.posY);
    printf("new_player_x: %f, new_player_y: %f\n\n", new_player_x, new_player_y);

    game->player.posX = new_player_x;
    game->player.posY = new_player_y;

   // game->map.file[game->player.posX][game->player.posY] = 'N';

    //render_playerI(game,game->player.posX, game->player.posY, 0xFF0000);
}



void	key_down(int keycode, t_game *game)
{
        printf("keydown keycode: %d\n\n", keycode);

	if (keycode == KEY_W || keycode == KEY_UP)
    {
        game->player.walk_direction = +1;
        move_player(game);
    }
	if (keycode == KEY_S || keycode == KEY_DOWN)
    {
        game->player.walk_direction = -1;
        move_player(game);
    }
	if (keycode == KEY_A || keycode == KEY_LEFT)
    {
        game->player.turn_direction = +1;
        move_player(game);
    }
	if (keycode == KEY_D || keycode == KEY_RIGHT)
    {
        game->player.turn_direction = -1;
        move_player(game);
    }
}

void	key_up(int keycode, t_game *game)
{
        printf("keyup: %d\n\n", keycode);

	if (keycode == KEY_W || keycode == KEY_UP)
        game->player.walk_direction = 0;
	if (keycode == KEY_S || keycode == KEY_DOWN)
         game->player.walk_direction = 0;
	if (keycode == KEY_A || keycode == KEY_LEFT)
        game->player.turn_direction = 0;
	if (keycode == KEY_D || keycode == KEY_RIGHT)
        game->player.turn_direction = 0;
}

int	key_press(int keycode, t_game *game)
{
    printf("keycode: %d\n\n", keycode);
    if (KeyPress)
    {
        if (keycode == KEY_UP || keycode == KEY_DOWN || keycode == KEY_LEFT || keycode == KEY_RIGHT)
	        key_down(keycode, game);
    	if (keycode == XK_Escape)
            exit_game(game);
    	if (game->end_game)
	    	return (0);
    }
    if (KeyRelease)
    {
            printf("keyrelease\n\n");

        if (keycode == KEY_UP || keycode == KEY_DOWN || keycode == KEY_LEFT || keycode == KEY_RIGHT)
	        key_up(keycode, game);
    }
	return (0);
}

void    event_handler(t_game *game)
{
    mlx_hook(game->window, X_EVENT_KEY_PRESS, 1l << 0, &key_press, game);
    mlx_hook(game->window, X_EVENT_KEY_EXIT, 0, &click_close, game);
}