# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/05 19:22:56 by lwencesl          #+#    #+#              #
#    Updated: 2023/05/11 00:44:36 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = checker
SRC = error_management error_management_bonus errors_bonus ft_split\
	ft_atoi ft_isdigit ft_strjoin ft_substr bonus_run_modes\
	ft_isprint ft_lstnew ft_lstsize ft_printf ft_printf_utils\
	ft_strchr ft_strncmp ft_strlen  moviments moviments2 \
	sort stack_work ft_isalpha main visualizer\

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