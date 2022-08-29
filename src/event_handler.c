/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 15:14:37 by azamario          #+#    #+#             */
/*   Updated: 2022/08/29 12:52:12 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void    event_handler(t_game *game)
{
    mlx_hook(game->window, X_EVENT_KEY_PRESS, 1l << 0, &key_press, game);
}