# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lwencesl <laherwpayotmaciel@gmail.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/20 19:03:40 by laher_maciel      #+#    #+#              #
#    Updated: 2023/04/24 16:57:36 by lwencesl         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
SRC = error_management find find2 ft_atoi ft_isdigit\
ft_isprint ft_lstnew ft_lstsize ft_printf ft_printf_utils\
ft_strchr ft_strncmp ft_strlen  moviments moviments2 p_decisions\
sort_conditions sort stack_work main\

SRC_BONUS = error_management_bonus errors_bonus ft_split\
ft_strjoin ft_substr ft_isalpha main_bonus\

CC = cc
RM = rm -f
CFLAGS = -g -Wall -Werror -Wextra -fsanitize=address\
-fsanitize-address-use-after-scope\

all:$(NAME)

$(NAME): $(SRC:=.o)
				cc -o $(NAME) $(SRC:=.o)
clean:
	$(RM)	$(SRC:=.o)
fclean: clean
			$(RM)	$(NAME)
re: fclean	$(NAME)
