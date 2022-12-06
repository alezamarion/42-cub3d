# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/11 20:05:50 by azamario          #+#    #+#              #
#    Updated: 2022/12/06 10:25:06 by azamario         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	cub3d

CC				=	gcc

XPM_DIR			=	textures

IMG_DIR			=	assets/img

LIB				=	./libraries/libft/libft.a
MLX				=	./libraries/mlx-linux/libmlx_Linux.a

FLAGS			=	-Wall -Werror -Wextra -g -fsanitize=address 
LINKS			=	-lbsd -lX11 -lXext -lm -ldl
INC				=	-I ./includes -I ./libft -I ./mlx-linux

SRC_DIR			=	./src
OBJ_DIR			=	./obj

CORE			=	cub3d.c
EVENT_HANDLER	=	event_handler.c
INIT_GAME		=	exit_game.c init_game.c init_image.c init_window.c map_counter.c
RENDER_GAME		=	cast_all_rays.c choose_smallest_distance.c draw_minimap.c find_horizontal_intersection.c \
					find_vertical_intersection.c move_player.c render_game.c
VALIDATION		=	read_file.c validation.c save_file_info.c save_file_info1.c map_info_validate.c \
					is_map_playable.c is_map_playable1.c

FILES			=	$(addprefix core/, $(CORE)) \
					$(addprefix event_handler/, $(EVENT_HANDLER)) \
					$(addprefix init_game/, $(INIT_GAME)) \
					$(addprefix render_game/, $(RENDER_GAME)) \
					$(addprefix validation/, $(VALIDATION))

SRC				=	$(addprefix $(SRC_DIR)/, $(FILES))
OBJ				=	$(subst $(SRC_DIR)/, $(OBJ_DIR)/, $(SRC:.c=.o))

all:		$(NAME)

$(NAME):	$(LIB) $(OBJ) $(MLX)
	@$(CC) $(FLAGS) $(OBJ) $(LIB) $(MLX) $(LINKS) $(INC) -o $(NAME)
	@echo ""
	@echo "|		Game created!		|"
	@echo ""

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p obj
	@mkdir -p obj/core
	@mkdir -p obj/event_handler
	@mkdir -p obj/init_game
	@mkdir -p obj/render_game
	@mkdir -p obj/validation
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

