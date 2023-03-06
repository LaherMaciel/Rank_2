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

	if (check_vals(argc, argv) == 0)
	{
		ft_printf("ERROR: 1 OR MORE IQUAL NUMBERS");
		return (0);
	}
	stack_a = store_integers_in_stack(argc, argv);
	stack_b = NULL;
	sort(&stack_a, &stack_b);
	while (stack_a != NULL)
		pop(&stack_a);
	while (stack_b != NULL)
		pop(&stack_b);
	ft_printf("ok");
	return (0);
}

/*
visualizer2(&stack_a, &stack_b);

done = sort(&stack_a, &stack_b);
print_tab(stack_a, stack_a);
*/
