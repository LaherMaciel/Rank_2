# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/18 15:36:42 by lwencesl          #+#    #+#              #
#    Updated: 2023/05/27 23:20:59 by lwencesl         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
TEXTURE_C = 
ANIMATION_C = test1.c
MAP_PARSING_C = map_parser.c
MOVEMENT_C =
WINDOW_C = window.c

LIBFT_DIRECTORY = libft/
LIBFT_HEADER = $(LIBFT_DIRECTORY)libft.h
LIBFT = $(LIBFT_DIRECTORY)libft.a

MLX_DIRECTORY = minilibx-linux/
MLX_HEADER = $(MLX_DIRECTORY)mlx.h
MLX = $(MLX_DIRECTORY)libmlx.a

HEADERS_LIST = so_long.h
HEADER_DIRECTORY = includes/
HEADERS =$(addprefix $(HEADER_DIRECTORY), $(HEADERS_LIST))

TEXTURES_LIST = $(TEXTURE_C)
TEXTURES_DIRECTORY = textures/
TEXTURES = $(addprefix $(TEXTURES_DIRECTORY), $(TEXTURES_LIST))

MAP_PARSING_LIST = $(MAP_PARSING_C)
MAP_PARSING_DIRECTORY = map_parsing/
MAP_PARSING = $(addprefix $(MAP_PARSING_DIRECTORY), $(MAP_PARSING_LIST))

MOVEMENT_LIST = $(MOVEMENT_C)
MOVEMENT_DIRECTORY = movement/
MOVEMENT = $(addprefix $(MOVEMENT_DIRECTORY), $(MOVEMENT_LIST))

ANIMATION_LIST = $(ANIMATION_C)
ANIMATION_DIRECTORY = animation/
ANIMATION = $(addprefix $(ANIMATION_DIRECTORY), $(ANIMATION_LIST))

WINDOW_LIST = $(WINDOW_C)
WINDOW_DIRECTORY = window/
WINDOW = $(addprefix $(WINDOW_DIRECTORY), $(WINDOW_LIST))

SRCS_LIST = $(MOVEMENT) $(MAP_PARSING) $(TEXTURES) $(ANIMATION) $(WINDOW) main.c read_file.c
SRCS_DIRECTORY = srcs/
SRCS = $(addprefix $(SRCS_DIRECTORY), $(SRCS_LIST))

OBJECT_LIST = $(SRCS_LIST:.c=.o)
OBJECTS_DIRECTORY = objects/
OBJECTS = $(addprefix $(OBJECTS_DIRECTORY), $(OBJECT_LIST))

CC = cc
CFLAGS = -g -Wall -Werror -Wextra 

LIBS = -L$(LIBFT_DIRECTORY) -lft $(MLX) -Imlx_linux -lX11 -lXext -lm -lz
INCLUDES = -I.$(HEADERS) -I.$(LIBFT_HEADER) -I.$(MLX_HEADER)

$(NAME): $(LIBFT) $(MLX) $(OBJECTS_DIRECTORY) $(OBJECTS)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJECTS) $(LIBS) -o $(NAME)

$(OBJECTS_DIRECTORY):
	mkdir -p $(OBJECTS_DIRECTORY)
	mkdir -p $(OBJECTS_DIRECTORY)$(TEXTURES_DIRECTORY)
	mkdir -p $(OBJECTS_DIRECTORY)$(MOVEMENT_DIRECTORY)
	mkdir -p $(OBJECTS_DIRECTORY)$(MAP_PARSING_DIRECTORY)
	mkdir -p $(OBJECTS_DIRECTORY)$(ANIMATION_DIRECTORY)
	mkdir -p $(OBJECTS_DIRECTORY)$(WINDOW_DIRECTORY)

$(OBJECTS_DIRECTORY)%.o : $(SRCS_DIRECTORY)%.c
	$(CC) $(CFLAGS) -c $(INCLUDES) $< -o $@

$(LIBFT):
	make -sC $(LIBFT_DIRECTORY) #--no-print-directory

$(MLX):
	cd $(MLX_DIRECTORY) && ./configure

clean: 
	rm -rf $(OBJECTS_DIRECTORY)
	make -sC $(LIBFT_DIRECTORY) clean #--no-print-directory

fclean: clean
	rm -rf $(NAME)
	make -sC $(LIBFT_DIRECTORY) fclean #--no-print-directory
	rm -rf $(MLX)

re: fclean
	clear && make

.PHONY: all clean fclean re
