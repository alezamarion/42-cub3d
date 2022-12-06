/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 22:01:50 by azamario          #+#    #+#             */
/*   Updated: 2022/11/28 05:47:02 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	free_map(char **map)
{
	int	i;

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

static void	free_game(t_game *game)
{
	if (game->window)
		mlx_destroy_window(game->mlx, game->window);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		ft_super_free(&game->mlx);
	}
}

int	exit_game(t_game *game)
{
	free_game(game);
	exit (0);
	return (0);
}

int	click_close(t_game *game)
{
	exit_game(game);
	return (0);
}

t_bool	print_error(char *error, t_game *game)
{
	ft_putstr_fd(error, 2);
	exit_game(game);
	return (false);
}
