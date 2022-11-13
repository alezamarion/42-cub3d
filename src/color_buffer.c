/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_buffer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 21:53:39 by azamario          #+#    #+#             */
/*   Updated: 2022/11/12 22:33:42 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/*
    3D projection will be created using a color buffer
    A color buffer is a representation of every pixel that we have in our 
        display - everything that will be rendered in the next frame, I have
        this represantion in memory
    It's a long array of pixel colors, alocated in memory
    We are going to use this declaration: Uint32 *color_buffer
    color_buffer is an address in memory ot Uint32 type of data
    Uint32: unsigned integer 32 bits - it tells the compiler we want exactly
        32 bits per unsigned integer
    It will be an hexadecimal number, example: 0xFFEE7E31 - you split it in pairs
    First pair -    FF: how much transparency
    Second pair -   EE: how much red
    Third pair -    7E: how much green
    Fourth pair -   31: how much blue
    Each pixel will have a color: a display with 1440 x 900 resolution will have
        1.296.000 pixels - that's the elements number of this array 
    So, we render this array in the display

    Important: a color buffer is not a matrixL it's an 1 dimension array

    Uint32* colorBuffer = NULL;
    // allocate the total amount of bytes in memory to hold our colorbuffer
    colorBuffer = (Uint32*)malloc(sizeof(Uint32) * WINDOW_WIDTH * WINDOW_HEIGHT);

    void clearColorBuffer(Uint32 color)
    {
        for (int x = 0; x < WINDOW_WIDTH; x++)
            for (int y = 0; y < WINDOW_HEIGHT; y++)
                colorBuffer[(WINDOW_WIDTH * y) + x] = color;
    }

    Inside brackets: index of each pixel
    WINDOW_WIDTH * y => how many rows times window width 
    + x (to shift in horizontal)
*/

