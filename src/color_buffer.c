/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_buffer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 21:53:39 by azamario          #+#    #+#             */
/*   Updated: 2022/11/23 16:09:26 by joeduard         ###   ########.fr       */
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
    Each pixel will have a color: a display with 800 x 600 resolution will have
        540.000 pixels - that's the elements number of this array 
    So, we render this array in the display

    Important: a color buffer is not a matrix it's an 1 dimension array

    Uint32* colorBuffer = NULL;
    // allocate the total amount of bytes in memory to hold our colorbuffer
    colorBuffer = (Uint32*)malloc(sizeof(Uint32) * WIN_WIDTH * WIN_HEIGHT);

    void clearColorBuffer(Uint32 color)
    {
        for (int x = 0; x < WIN_WIDTH; x++)
            for (int y = 0; y < WIN_HEIGHT; y++)
                colorBuffer[(WIN_WIDTH * y) + x] = color;
    }

    Inside brackets: index of each pixel
    WIN_WIDTH * y => how many rows times window width 
    + x (to shift in horizontal)

    Using SDL, you display the content of color buffer to the screen
    You copy the color buffer to an SDL_Texture:

    SDL_texture *colorBufferTexture

    colorBufferTexture = SDL_CreateTexture(
        renderer,
        SDL_PIXELFORMAT_ARGB8888,
        SDL_TEXTUREACCESS_STREAMING,
        WIN_WIDTH,
        WIN_HEIGHT
    );

    After creating texture, for each one of the frames, I update color buffer

    void renderColorBuffer() {
        SDL_UpdateTexture(
            colorBufferTexture,
            NULL,
            colorBuffer,
            (int)(WIN_WIDTH * sizeof(Uint32))
        );
        SDL_RenderCopy(renderer, colorBufferTexture, NULL, NULL); //display
    }
*/


//inicializei e fiz o malloc do color_buffer no init game
//criei uma struct buffer

//buffer[(WIN_WIDTH * ROWS) + x (quanto para a direita tenho que andar)] 

// void clearColorBuffer(t_game *game, Uint32 color)
// {
//     for (int x = 0; x < WIN_WIDTH; x++)
//         for (int y = 0; y < WIN_HEIGHT; y++)
//             game->buffer.color_buffer[(WIN_WIDTH * y) + x] = color;
// }
/*
    1 - cria ponteiro para buffer
    2 - cria ponteiro para a textura ()
*/
//put_pixel_in_color_buffer

//render_color_buffer

