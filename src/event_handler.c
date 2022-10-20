/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 15:14:37 by azamario          #+#    #+#             */
/*   Updated: 2022/10/19 21:11:18 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"


static int click_close(t_game *game)
{
    exit_game(game);
    return (0);
}

void    swap_positions(char *curr_p, char *next_p, char curr_value, char next_value)
{
    *curr_p = next_value;
    *next_p = curr_value;
}

void    handle_0(t_game *game, int x, int y)
{
    int i;
    int j;

    i = game->x;
    j = game->y;
    swap_positions(&game->map[i][j], &game->map[x][y], 'N', '0');
    game->x = x;
    game->y = y;
}

void    handle_situation(t_game *game, int x, int y)
{
    printf("\nhandle situation x: %d, y: %d", x, y);
    if (game->map[x][y] != '1')
    {
        if (game->map[x][y] == '0')
            handle_0(game, x, y);
    }
}

void	player_update(int keycode, t_game *game)
{
	if (keycode == KEY_W || keycode == KEY_UP)
    {
        printf("\nplayer_update: game->x: %d, game->y: %d\n", game->x, game->y);
        handle_situation(game, game->x - 1, game->y);
    }
	if (keycode == KEY_S || keycode == KEY_DOWN)
    	handle_situation(game, game->x + 1, game->y);
	if (keycode == KEY_A || keycode == KEY_LEFT)
		handle_situation(game, game->x, game->y - 1);
	if (keycode == KEY_D || keycode == KEY_RIGHT)
    	handle_situation(game, game->x, game->y + 1);
}


int	key_press(int keycode, t_game *game)
{
    if (keycode == KEY_UP || keycode == KEY_DOWN || keycode == KEY_LEFT || keycode == KEY_RIGHT)
	    player_update(keycode, game);
	if (keycode == XK_Escape)
        exit_game(game);
	if (game->end_game)
		return (0);
	mlx_loop_hook(game->mlx, &render_map, &game);
	return (0);
}

void    event_handler(t_game *game)
{
    mlx_hook(game->window, X_EVENT_KEY_PRESS, 1l << 0, &key_press, game);
    mlx_hook(game->window, X_EVENT_KEY_EXIT, 0, &click_close, game);
}