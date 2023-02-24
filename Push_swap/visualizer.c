/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualizer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 13:02:12 by lwencesl          #+#    #+#             */
/*   Updated: 2023/02/24 14:34:21 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_tab(t_stack *stack_a, t_stack *stack_b)
{
	ft_printf("------------------------");
	ft_printf("|      A        B      |");
	while ((stack_a)->next != NULL && (stack_b)->next != NULL)
	{
		ft_printf("|      %d        %d      |", (stack_a)->content,
			(stack_b)->content);
		stack_a = stack_a->next;
		stack_b = stack_b->next;
	}
	while ((stack_a->next != NULL))
	{
		ft_printf("|      %d               |", (stack_a)->content);
		stack_a = stack_a->next;
	}
	while ((stack_b->next != NULL))
	{
		ft_printf("|               %d      |", (stack_b)->content);
		stack_b = stack_b->next;
	}
	ft_printf("|                      |");
	ft_printf("------------------------");
}

void	visualizer(t_stack **stack_a, t_stack **stack_b, int argc, char *argv[])
{
	char	input[4];

	input[0] = 's';
	while (input[0] == 'p' || input[0] == 's' || input[0] == 'r')
	{
		ft_printf("next  mov: ");
		scanf("%s", input);
		if (input[0] == 'p')
			p_movs(stack_a, stack_b, input);
		else if (input[0] == 's')
			ss_movs(stack_a, stack_b, input);
		else if (input[0] == 'r' && input[3] != '\0')
			rrr_movs(stack_a, stack_b, input);
		else if (input[0] == 'r')
			rr_movs(stack_a, stack_b, input);
		print_tab(*stack_a, *stack_b);
	}
}
