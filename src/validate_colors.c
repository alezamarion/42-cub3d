/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_colors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 11:51:47 by azamario          #+#    #+#             */
/*   Updated: 2022/11/26 23:42:20 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"


// static int count_vectors(char **matrix)
// {
//     int i;

//     i = 0;
//     while (matrix[i])
//         i++;
//     return (i);
// }

int    validate_colors(char *color)
{
    printf("cor: %s\n", color);
    int comma;
    int i;

    i = 0;
    comma = 0;
    
    if (color == NULL)
    {
        printf("hello");
        return (0);

    }
    while (color[i])
    {
        if (color[i] == ',')
            comma++;
        i++;
    }
    printf("comma %d\n", comma);
    if (comma < 2)
        return (0);
    return (1);

}
