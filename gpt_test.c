/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gpt_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 11:30:29 by lwencesl          #+#    #+#             */
/*   Updated: 2023/02/15 12:29:30 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

typedef struct t_stack {
	int				data;
	struct t_stack	*next;
}					t_stack;

int	main(int argc, char *argv[])
{
	t_stack	*stack;

	stack = store_integers_in_stack(argc, argv);
	print_list (stack);
	while (stack->next)
		pop(&stack);
    return 0;
}
