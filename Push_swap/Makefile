# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: laher_maciel <laher_maciel@student.42.fr>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/20 19:03:40 by laher_maciel      #+#    #+#              #
#    Updated: 2023/04/20 19:11:00 by laher_maciel     ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftpush_swap.a
SRC = error_management find find2 ft_atoi ft_isdigit\
ft_isprint ft_lstnew ft_lstsize ft_printf ft_printf_utils\
ft_strchr ft_strncmp main moviments moviments2 p_decisions\
sort_conditions sort stack_work\

CC = cc
RM = rm -f
CFLAGS = -Wall -Werror -Wextra

all:$(NAME)

$(NAME): $(SRC:=.o)
				ar rc $(NAME) $(SRC:=.o)
clean:
	$(RM)	$(SRC:=.o)
fclean: clean
			$(RM)	$(NAME)
re: fclean	$(NAME)