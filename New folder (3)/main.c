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

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		movs;

	if (argc > 0)
	{
		stack_a = store_integers_in_stack2(ft_atoi(argv[1]), ft_atoi(argv[2]), ft_atoi(argv[3]));
		stack_b = NULL;
		//ft_printf("stack size = %i\n", (ft_lstsize(stack_a) / 2));
		movs = order(&stack_a, &stack_b);
		ft_printf("\n\nMAIN FINAL PRINT\n");
		print_tab(stack_a, stack_b);
		ft_printf("NUMERO DE MOVIMENTOS FEITOS: %i\n", movs);
		while (stack_a != NULL)
			pop(&stack_a);
		while (stack_b != NULL)
			pop(&stack_b);
		ft_printf("ok");
	}
	return (0);
}


/*
int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		val;

	val = check_vals(argc, argv);
	if (val != 1)
	{
		ft_printf("ERROR: 1 OR MORE IQUAL NUMBERS (%i)\n", val);
		return (0);
	}
	stack_a = store_integers_in_stack(argc, argv);
	stack_b = NULL;
	//ft_printf("stack size = %i\n", (ft_lstsize(stack_a) / 2));
	val = order(&stack_a, &stack_b);
	ft_printf("\n\nMAIN FINAL PRINT\n");
	print_tab(stack_a, stack_b);
	ft_printf("NUMERO DE MOVIMENTOS FEITOS: %i\n", val);
	while (stack_a != NULL)
		pop(&stack_a);
	while (stack_b != NULL)
		pop(&stack_b);
	ft_printf("ok");
	return (0);
}
*/


/*
visualizer2(&stack_a, &stack_b);

done = sort(&stack_a, &stack_b);
print_tab(stack_a, stack_a);
*/
