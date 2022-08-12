# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/11 20:05:50 by azamario          #+#    #+#              #
#    Updated: 2022/08/12 03:45:35 by azamario         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

LIBFT_DIR = libraries/libft
LIBFT = $(LIBFT_DIR)/libft.a

#MLX_DIR = libraries/mlx_linux
#MLX = $(MLX_DIR)/libmlx.a

RM = rm -rf

#IMG_DIR = assets/img
SRC_DIR = src
OBJ_DIR = obj

INCLUDE_DIR = includes
HEADERS = $(INCLUDE_DIR)/cub3d.h

SRC_FILES = cub3d.c map_check.c read_map.c validate_map.c get_next_line.c

SRC = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

CC = clang
CFLAGS = -Wall -Wextra -Werror #-fsanitize=address
LIBFLAGS = -lft -lXext -lX11 -lmlx -lm

all: $(NAME)

$(NAME): $(OBJ_DIR) $(LIBFT) $(OBJ)
	$(CC) $(OBJ) -L$(LIBFT_DIR) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS)
	$(CC) $(CFLAGS) -c -I$(INCLUDE_DIR) -o $@ $<

$(LIBFT):
	make -C $(LIBFT_DIR)

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

run:
	./so_long "assets/maps/map.ber"

clean:
	$(RM) $(OBJ)
	
fclean: clean
	make -C $(LIBFT_DIR) fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean all re


