# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/11 20:05:50 by azamario          #+#    #+#              #
#    Updated: 2022/11/24 18:28:12 by azamario         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	cub3d

CC			=	gcc

XPM_DIR		=	textures

IMG_DIR		=	assets/img

LIB			=	./libraries/libft/libft.a
MLX			=	./libraries/mlx-linux/libmlx_Linux.a

FLAGS		=	-Wall -Werror -Wextra -g -fsanitize=address 
LINKS		=	-lbsd -lX11 -lXext -lm -ldl
INC			=	-I ./includes -I ./libft -I ./mlx-linux

SRC_DIR		=	./src
OBJ_DIR		=	./obj

FILES		=	cub3d.c
FILES		+=	exit_game.c init_game.c init_image.c init_window.c    
FILES		+=	read_map.c validate_map.c is_valid_map.c event_handler.c render_game.c
FILES		+=	map_utils.c draw_minimap.c draw_player.c cast_all_rays.c
FILES		+=	cast_ray_horizontal.c cast_ray_vertical.c cast_ray_find_distance.c validation.c

SRC			=	$(addprefix $(SRC_DIR)/, $(FILES))
OBJ			=	$(addprefix $(OBJ_DIR)/, $(FILES:.c=.o))

all:		$(NAME)

$(NAME):	$(LIB) $(OBJ) $(MLX)
	@$(CC) $(FLAGS) $(OBJ) $(LIB) $(MLX) $(LINKS) $(INC) -o $(NAME)
	@echo "Game created!"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p obj
	$(CC) $(FLAGS) $(INC) -c $< -o $@

$(LIB):
	make -C libraries/libft

$(MLX):
	@echo "Compiling Mlx [ .. ]"
	@make -C libraries/mlx-linux
	@echo "Mlx is ready! [ OK ]"

run:
	./cub3d "assets/maps/mandatory1.cub" "assets/maps/mandatory.cub"

resize:
	mogrify -resize 32X32 $(IMG_DIR)/*.png && make img

img:
	convert $(IMG_DIR)/*.png -set filename:base "%[basename]" "%[filename:base].xpm" && mv *.xpm $(XPM_DIR)

clean:
	@make -C ./libraries/libft clean
	@make -C ./libraries/mlx-linux clean
	@rm -rf obj
	@echo "Objects files deleted."

fclean:		clean
	@rm -f $(NAME) $(LIB) $(MLX)
	@echo "Executable deleted."

bonus:		$(NAME)

norm:
	norminette src inc libft

add: fclean
		git add .
		git status

re:			fclean all

.PHONY: all, clean, fclean, bonus, re

