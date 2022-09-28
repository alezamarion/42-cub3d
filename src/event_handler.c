/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 15:14:37 by azamario          #+#    #+#             */
/*   Updated: 2022/09/28 18:31:11 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int key_esc(int keycode, t_game *game)
{
    if (keycode == KEY_ESC)
        exit_game(game);
    return (0);
}

static int click_close(t_game *game)
{
    exit_game(game);
    return (0);
}

void    event_handler(t_game *game)
{
    mlx_hook(game->window, X_EVENT_KEY_PRESS, 0, &key_esc, &game);
    mlx_hook(game->window, X_EVENT_KEY_EXIT, 0, &click_close, &game);
}