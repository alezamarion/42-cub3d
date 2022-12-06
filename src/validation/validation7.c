/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_colors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 11:51:47 by azamario          #+#    #+#             */
/*   Updated: 2022/11/28 06:32:45 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	validate_colors(char *color)
{
	int	comma;

	comma = 0;
	if (!*color)
		return (0);
	while (*color)
	{
		if (*color == ',')
			comma++;
		color++;
	}
	if (comma < 2 || comma > 2)
		return (0);
	return (1);
}
