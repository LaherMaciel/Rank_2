/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_mode.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laher_maciel <laher_maciel@student.42.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 21:01:28 by lwencesl          #+#    #+#             */
/*   Updated: 2023/04/20 18:10:04 by laher_maciel     ###   ########.fr       */
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
