# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/20 19:03:40 by laher_macie       #+#    #+#              #
#    Updated: 2023/05/06 18:21:13 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
SRC = error_management find find2 ft_atoi ft_isdigit\
ft_isprint ft_lstnew ft_lstsize ft_printf ft_printf_utils\
ft_strchr ft_strncmp ft_strlen  moviments moviments2 p_decisions\
sort_conditions sort stack_work main\


CC = cc
RM = rm -f
CFLAGS = -g -Wall -Werror -Wextra\

all:$(NAME)

$(NAME): $(SRC:=.o)
				cc -o $(NAME) $(SRC:=.o)
clean:
	$(RM)	$(SRC:=.o)
fclean: clean
			$(RM)	$(NAME)
re: fclean	$(NAME)
