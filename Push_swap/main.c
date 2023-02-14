/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 12:41:11 by lwencesl          #+#    #+#             */
/*   Updated: 2023/02/09 12:41:11 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*print_stack;

	stack_a = create_stack(argc, argv);
	print_stack = stack_a;
	while (print_stack != NULL)
	{
		printf("%d\n", *((int *) stack_a->content));
		stack_a = stack_a->next;
	}
	free(print_stack);
	free(stack_a);
	return (0);
}
