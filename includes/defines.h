/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 11:41:29 by joeduard          #+#    #+#             */
/*   Updated: 2022/11/11 17:20:17 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# define XK_MISCELLANY

# define TILE_SIZE 32

# define WIN_WIDTH 1024
# define WIN_HEIGHT 768

# define MENU 0
# define GAME 1
# define OPTIONS 2

# define PI 3.14159265

# define SPRITE_SIZE	32

# define X_EVENT_KEY_EXIT 17
# define X_EVENT_KEY_PRESS	2
# define KEY_ESC 53
# define X_EVENT_DESTROY_NOTIFY	17
# define KEY_W	119
# define KEY_A	97
# define KEY_S	115
# define KEY_D	100

# define KEY_UP		65362
# define KEY_LEFT	65361
# define KEY_DOWN	65364
# define KEY_RIGHT	65363

# define PURPLE 0x4B0082
# define BLUE   0xF5FFA
# define YELLOW 0x8FCE00

# define KeyPress	2
# define KeyRelease	3


# define NUM_RAYS WIN_WIDTH
# define FOV_ANGLE (60 *(M_PI / 180))

# define FILE_WALL	"textures/1.xpm"
# define FILE_SPACE	"textures/0.xpm"
# define FILE_PLAYER_U	"textures/P_U.xpm"
# define FILE_PLAYER_D	"textures/P_D.xpm"
# define FILE_PLAYER_L	"textures/P_L.xpm"
# define FILE_PLAYER_R	"textures/P_R.xpm"



# define MLX_ERROR "MLX_ERROR: Could not initialize or create window"

#endif
