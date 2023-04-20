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
	print_tab(*stack_a, *stack_b);
	ft_printf("cont -> %i\n", *cont);
}

void	end_code(t_stack **stack_a, t_stack **stack_b, int cont)
{
	if (stack_a != NULL)
	{
		ft_printf("\n\nMAIN FINAL PRINT\n");
		print_tab(*stack_a, *stack_b);
	}
	ft_printf("NUMERO DE MOVIMENTOS FEITOS: %i\n", cont);
	ft_printf("FIM DO PROGRAMA!\n");
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
		stack_a = store_integers_in_stack3(argc, argv);
		if (error_check(stack_a) != NULL && check_order_ok(stack_a) == 0)
		{
			auto_sort(&stack_a, &stack_b, &cont);
			end_code(&stack_a, &stack_b, cont);
			if (check_order_ok(stack_a) == 0 || stack_b != NULL)
				ft_printf("\nKO\n");
			else if (check_order_ok(stack_a) == 1)
				ft_printf("\nOK\n");
		}
	}
	while (stack_a != NULL)
		pop(&stack_a);
	while (stack_b != NULL)
		pop(&stack_b);
	return (0);
}
