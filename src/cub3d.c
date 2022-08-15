/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 21:40:09 by azamario          #+#    #+#             */
/*   Updated: 2022/08/15 22:22:26 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc == 2)
	{
		game.map = read_map(argv[1]);
		if (is_valid_map(game.map, argv[1]))
		{
			printf("Map is valid\n");
			free_map(game.map);		
		}
		else
		{
			printf("Map is not valid\n");
			free_map(game.map);					
		}
	}
	else
	{
		printf("No map specified\n");
		exit (0);	
	}
	return (0);
}