# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/11 20:05:50 by azamario          #+#    #+#              #
#    Updated: 2022/08/29 22:22:47 by azamario         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	cub3d

CC			=	clang

LIB			=	./libraries/libft/libft.a
MLX			=	./libraries/mlx-linux/libmlx_Linux.a

FLAGS		=	-Wall -Werror -Wextra -g -fsanitize=address
LINKS		=	-lbsd -lX11 -lXext
INC			=	-I ./includes -I ./libft -I ./mlx-linux

SRC_DIR		=	./src
OBJ_DIR		=	./obj

FILES		=	cub3d.c
FILES		+=	exit_game.c get_next_line.c init_game.c init_image.c init_window.c map_check.c    
FILES		+=	read_map.c validate_map.c map_utils.c event_handler.c game_utils.c player_update.c
FILES		+=	move_player.c

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
	./cub3d "assets/maps/mandatory.cub"

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

re:			fclean all

.PHONY: all, clean, fclean, bonus, re

