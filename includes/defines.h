/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 11:41:29 by joeduard          #+#    #+#             */
/*   Updated: 2022/11/28 08:11:06 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# define XK_MISCELLANY 
# define MLX_ERROR "MLX_ERROR: Could not initialize or create window"

# define TILE_SIZE 32
# define WIN_WIDTH 800
# define WIN_HEIGHT 600

# define NUM_RAYS WIN_WIDTH

# define X_EVENT_KEY_EXIT 17
# define KEY_ESC 53

# define X_EVENT_KEY_PRESS 2
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115 
# define KEY_D 100

# define KEY_UP 65362
# define KEY_LEFT 65361
# define KEY_DOWN 65364
# define KEY_RIGHT 65363

//movement
# define PI 3.141592
# define TWO_PI 6.283185
# define HALF_PI 1.570796
# define PI_PLUS_HALF_PI 4.712388

//rays
# define NUM_RAYS WIN_WIDTH
# define FOV_ANGLE 1.0471975511965977461542144610932

# define PURPLE 0x4B0082
# define BLUE   0xF5FFA
# define YELLOW 0x8FCE00
# define WHITE  0xFFFFFFFF
# define GREY   0xFF333333
# define RED    0x770C0C
# define TEXT_HEIGHT 32
# define TEXT_WIDTH 32
# define NUMBER_OF_TEXTURES 2

#endif