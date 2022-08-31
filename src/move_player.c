/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 22:10:03 by azamario          #+#    #+#             */
/*   Updated: 2022/08/31 17:34:41 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	swap_positions(char *current_pos, char *next_pos,
                            char current_value, char next_value)
{
	*current_pos = next_value;
	*next_pos = current_value;
}

static void    handle_space(t_game *game, int x, int y)
{
	int	i;
	int	j;

	i = game->x;
	j = game->y;
	swap_positions(&game->map[i][j], &game->map[x][y], 'N', '0');
	game->moves++;
	game->x = x;
	game->y = y;
}

void    handle_situation(t_game *game, int x, int y)
{
    if (game->map[x][y] != '1')
    {
        if (game->map[x][y] == '0')
            handle_space(game, x, y);
    }
}

void    handle_angle(t_game *game, int x, int y)
{
    
}