# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/11 20:05:50 by azamario          #+#    #+#              #
#    Updated: 2022/08/13 03:55:29 by azamario         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	cub3d
INCL	=	./include
SRC		=	src/cube3d.c src/get_next_line.c \
			src/map_check.c src/read_map.c src/validate_map
OBJ		=	./obj

# Compiler, Linker Defines
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror -g -fsanitize=address #-lpthread
RM		=	rm -rf

# libft
LIBFT_DIR = ./libraries/libft
LIBFT = $(LIBFT_DIR)/libft.a

all:	libfilo bin

libfilo:
	$(CC) -c src/get_next_line.c -I $(INCL) -o $(OBJ)/get_next_line.o
	$(CC) -c src/map_check.c -I $(INCL) -o $(OBJ)/map_check.o
	$(CC) -c src/read_map.c -I $(INCL) -o $(OBJ)/read_map.o
	$(CC) -c src/validate_map.c -I $(INCL) -o $(OBJ)/validate_map.o

bin:
	$(CC) src/cub3d.c $(OBJ)/*.o -I$(INCL) -L$(LIBFT) -o cub3d


# Compile and Assemble C Source Files into Object Files


# Link all Object Files with external Libraries into Binaries


# Clean Up Objects, Exectuables, Dumps out of source directory
clean: 
	$(RM) $(OBJ)/*.o philosophers

re: clean all

.PHONY: all clean fclean re bonus

#make --debug=b

#$@ relaciona-se com o alvo e $^ relaciona-se com todos pŕe-requisitos.

#target	:	prerequisites
#	recipe
# target: nome da ação que deseja executar ou usualmente o nome do arquivo que se queira produzir
# prerequisitos são os arquivos que são usados como input para criar o target
# receita é a ação que o comando make realiza - o TAB antes da receita é interpretado pelo make como 
#	indicação de começo de comando a ser executado