# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/18 15:36:42 by lwencesl          #+#    #+#              #
#    Updated: 2023/05/18 15:40:00 by lwencesl         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
SRC = error_management find find2 ft_atoi ft_isdigit ft_split ft_strjoin\
ft_isprint ft_lstnew ft_lstsize ft_printf ft_printf_utils ft_substr\
ft_strchr ft_strncmp ft_strlen  moviments moviments2 p_decisions stack_work2\
sort_conditions sort stack_work main error_management_bonus errors_bonus\


CC = cc
RM = rm -f
CFLAGS = -g -Wall -Werror -Wextra\

all:$(NAME)

$(NAME): $(SRC:=.o)
				cc -o $(NAME) $(SRC:=.o)
$(NAME): $(OBJ)
	$(CC) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
clean:
	$(RM)	$(SRC:=.o)
fclean: clean
			$(RM)	$(NAME)
re: fclean	$(NAME)