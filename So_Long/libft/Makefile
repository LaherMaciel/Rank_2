# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/31 18:07:37 by lwencesl          #+#    #+#              #
#    Updated: 2023/05/24 19:47:18 by lwencesl         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a
SRC		= ${wildcard *.c}
OBJ		= $(SRC:.c=.o)
AR		= ar rc
CC		= cc
RM		= rm -f
CFLAGS  = -g -Wall -Werror -Wextra -I./
GNL     = get_next_line/includes
PRINTF  = ft_printf/includes
LIBS    = -Lget_next_line -lget_next_line -Lft_printf -lftprintf

all:$(NAME)

$(NAME): rungnl $(OBJ)
		$(AR) $(NAME) $(OBJ) $(GNL) $(PRINTF) $(LIBS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM)	$(OBJ)
	make -C get_next_line clean
	make -C ft_printf clean

fclean: clean
	$(RM) $(NAME)
	make -C get_next_line fclean
	make -C ft_printf fclean

re:	fclean
	@clear && make all

rungnl:
	make -C get_next_line
	make -C ft_printf
.PHONY: all clean fclean re