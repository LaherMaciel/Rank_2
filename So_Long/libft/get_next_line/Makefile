# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/23 23:00:27 by lwencesl          #+#    #+#              #
#    Updated: 2023/05/23 23:00:27 by lwencesl         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= get_next_line.a
SRC		= ${wildcard *.c}
OBJ		= $(SRC:.c=.o)
AR		= ar rcs
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