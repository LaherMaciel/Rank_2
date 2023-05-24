# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/31 18:07:37 by lwencesl          #+#    #+#              #
#    Updated: 2022/11/18 01:00:28 by lwencesl         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a
SRC		= ${wildcard *.c}
OBJ		= $(SRC:.c=.o)
AR		= ar rc
CC		= cc
RM		= rm -f
CFLAGS	= -g -Wall -Werror -Wextra
GNL		= libget_next_line.a/includes
PRINTF	= libft_prinft.a/includes
LIBS = -Lget_next_line -lget_next_line -Lft_prinft -lft_prinft

all:$(NAME)

$(NAME): rungnl $(OBJ)
		$(AR) $(NAME) $(OBJ) $(LIBS) -o $(NAME)
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
	@clear && make
rungnl:
	make -C get_next_line
	make -C ft_printf