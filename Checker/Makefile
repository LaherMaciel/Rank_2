# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    MakeFile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/12 20:08:05 by lwencesl          #+#    #+#              #
#    Updated: 2023/03/12 20:08:05 by lwencesl         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRC = find ft_atoi ft_lstnew ft_lstsize ft_printf_utils ft_printf \
ft_strjoin ft_strlen main moviments moviments2 movs3 p_cont pa pb \
sort_conditions sort_conditions2 sort stack_work visualizer \

CC = cc
RM = rm -f
CFLAGS = -Wall -Werror -Wextra


all:$(NAME)

$(NAME): $(SRC:=.o)
			ar rc $(NAME) $(SRC:=.o)
bonus: $(B_SRCS:=.o)
			ar rc $(NAME) $(B_SRCS:=.o)
clean:
	$(RM)	$(SRC:=.o) $(B_SRCS:=.o)
fclean: clean
		$(RM)	$(NAME)
re:	fclean	$(NAME)