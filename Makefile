# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/11 20:05:50 by azamario          #+#    #+#              #
#    Updated: 2022/12/01 15:36:07 by azamario         ###   ########.fr        #
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
FILES		+=	read_file.c event_handler.c render_game.c
FILES		+=	init_game1.c draw_minimap.c render_game1.c render_game2.c
FILES		+=	render_game3.c render_game4.c validation2.c render_game5.c validation.c
FILES		+=	validation7.c validation4.c validation5.c validation6.c
FILES		+=	validation1.c validation3.c

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
	./cub3d "assets/maps/map0.cub"

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

