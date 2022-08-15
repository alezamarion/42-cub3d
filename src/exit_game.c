/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 22:01:50 by azamario          #+#    #+#             */
/*   Updated: 2022/08/15 22:08:27 by azamario         ###   ########.fr       */
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
