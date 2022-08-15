# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/11 20:05:50 by azamario          #+#    #+#              #
#    Updated: 2022/08/15 20:37:49 by azamario         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCES_FILES	=	cub3d.c
SOURCES_FILES	+=	get_next_line.c map_check.c read_map.c validate_map.c

SOURCES_DIR		=	src

OBJ_DIR			=	obj

HEADER			=	$(SOURCES_DIR)/cub3d.h

SOURCES			=	$(addprefix $(SOURCES_DIR)/, $(SOURCES_FILES))

OBJECTS			=	$(SOURCES:$(SOURCES_DIR)/%.c=$(OBJ_DIR)/%.o)

NAME			=	cub3d

CC				=	clang
RM				=	rm -rf

CFLAGS			=	-Wall -Wextra -Werror -g  -fsanitize=thread 

$(OBJ_DIR)/%.o:		$(SOURCES_DIR)/%.c $(HEADER)
					$(CC) $(CFLAGS) -c $< -o $@

all:				$(NAME)

$(NAME):			$(OBJ_DIR) $(OBJECTS) $(HEADER)
					$(CC) $(CFLAGS) $(OBJECTS) $(LDFLAGS) -o $(NAME)

$(OBJ_DIR):
					mkdir -p $(OBJ_DIR)

clean:
					$(RM) $(OBJ_DIR)

fclean:				clean
					$(RM) $(NAME)

re:					fclean all

.PHONY:				all clean fclean re bonus