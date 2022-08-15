# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/11 20:05:50 by azamario          #+#    #+#              #
#    Updated: 2022/08/15 21:10:00 by azamario         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	cub3d

CC			=	clang

LIB			=	./libraries/libft/libft.a

FLAGS		=	-Wall -Werror -Wextra -g -fsanitize=address
INC			=	-I ./inc -I ./libft

SRC_DIR		=	./src
OBJ_DIR		=	./obj

FILES	=	cub3d.c
FILES	+=	get_next_line.c map_check.c read_map.c validate_map.c

SRC			=	$(addprefix $(SRC_DIR)/, $(FILES))
OBJ			=	$(addprefix $(OBJ_DIR)/, $(FILES:.c=.o))

all:		$(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p obj
	$(CC) $(FLAGS) $(INC) -c $< -o $@

$(NAME):	$(LIB) $(OBJ)
	@$(CC) $(FLAGS) $(OBJ) $(LIB) $(INC) -o $(NAME)
	@echo "Game created!"

$(LIB):
	make -C libraries/libft

run:
	./cub3d "assets/maps/map.ber"

clean:
	@make -C ./libraries/libft clean
	@rm -fr obj
	@echo "Objects files deleted."

fclean:		clean
	@rm -f $(NAME)
	@make -C ./libft fclean
	@echo "Executable deleted."

bonus:		$(NAME)

norm:
	norminette src inc libft

re:			fclean all

.PHONY: all, clean, fclean, bonus, re

