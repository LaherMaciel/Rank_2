/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 12:43:29 by lwencesl          #+#    #+#             */
/*   Updated: 2023/03/06 10:12:47 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// if the user introduz just the numbers | main
void	auto_sort(t_stack **stack_a, t_stack **stack_b, int *cont)
{
	int		smallest;

	sort(stack_a, stack_b, cont);
	smallest = nr_movs(find_pos(*stack_a,
				find_smallest(*stack_a)), ft_lstsize(*stack_a));
	while (smallest != 0)
	{
		if (smallest > 0)
		{
			ft_reverse_rotate(stack_a, 'a');
			smallest--;
		}
		else if (smallest < 0)
		{
			ft_rotate(stack_a, 'a');
			smallest++;
		}
		*cont = *cont + 1;
	}
}

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		cont;

	cont = 0;
	stack_a = NULL;
	stack_b = NULL;
	if (argc > 2)
	{
		stack_a = store_integers_in_stack(argc, argv);
<<<<<<< HEAD
		if (error_check(stack_a, argv) != NULL && check_order_ok(stack_a) == 0)
=======
		if (error_check(stack_a) != NULL && check_order_ok(stack_a) == 0)
>>>>>>> f1f5c4aa36db2b2f137c201c0d9175b7edf83a49
			auto_sort(&stack_a, &stack_b, &cont);
	}
	if (argc == 2 && ft_isdigit(argv[1][0]) == 0)
		ft_printf("Error\n");
	while (stack_a != NULL)
		pop(&stack_a);
	while (stack_b != NULL)
		pop(&stack_b);
	return (0);
}
