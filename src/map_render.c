/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 13:58:20 by azamario          #+#    #+#             */
/*   Updated: 2022/08/31 16:16:48 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void    draw_image(t_game *game, void *image, int x, int y)
{
    mlx_put_image_to_window(game->mlx, game->window, image, y * SPRITE_SIZE, x * SPRITE_SIZE);
}

void	map_render(char **map, t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '1')
				draw_image(game, game->wall, i, j);
			else if (map[i][j] == '0')
				draw_image(game, game->empty_space, i, j);
			else if (map[i][j] == 'N')
				hook_player(game, i, j);
			j++;
		}
		i++;
	}
}