# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lwencesl <laherwpayotmaciel@gmail.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/18 02:29:21 by lwencesl          #+#    #+#              #
#    Updated: 2023/01/03 17:10:29 by lwencesl         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= ftprintf.a
SRC		= ${wildcard *.c}
OBJ		= $(SRC:.c=.o)
AR		= ar rc
CC		= cc
RM		= rm -f
CFLAGS	= -g -Wall -Werror -Wextra -I./

all:$(NAME)

$(NAME): $(OBJ)
		$(AR) $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM)	$(OBJ)

fclean: clean
	$(RM) $(NAME)

re:	fclean
	@clear && make

.PHONY: all clean fclean re