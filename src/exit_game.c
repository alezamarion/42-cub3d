/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 22:01:50 by azamario          #+#    #+#             */
/*   Updated: 2022/10/20 18:32:55 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void    free_map(char **map)
{
    int    i;

    if (!map)
        return ;
    i = 0;
    while (map[i])
    {
        ft_super_free((void *)&map[i]);
        i++;
    }
    ft_super_free((void *)&map);
}

static void free_game(t_game *game)
{
	mlx_destroy_window(game->mlx, game->window);
	mlx_destroy_display(game->mlx);
	ft_super_free(&game->mlx);     
}

int exit_game(t_game *game)
{
    free_map(game->map.file);
    free_game(game);
    exit (0);
    return (0);
}