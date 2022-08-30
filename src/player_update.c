/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_update.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 21:44:31 by azamario          #+#    #+#             */
/*   Updated: 2022/08/29 21:54:19 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void    player_update(int keycode, t_game *game)
{
    if (keycode == KEY_W || keycode == KEY_UP)
    {
        handle_situation(game, game->x - 1, game->y);
        game->player_direction = 'u';
    }
    if (keycode == KEY_S || keycode == KEY_DOWN)
    {
        handle_situation(game, game->x + 1, game->y);
        game->player_direction = 'd';
    }
    if (keycode == KEY_A || keycode == KEY_LEFT)
    {
        handle_situation(game, game->x, game->y - 1);
        game->player_direction = 'l';
    }
    if (keycode == KEY_D || keycode == KEY_RIGHT)
    {
        handle_situation(game, game->x, game->y + 1);
        game->player_direction = 'r';
    }
}