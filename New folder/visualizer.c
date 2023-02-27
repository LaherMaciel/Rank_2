/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualizer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 13:02:12 by lwencesl          #+#    #+#             */
/*   Updated: 2023/02/24 20:29:16 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_tab(t_stack *stack_a, t_stack *stack_b)
{
	ft_printf("\n------------------------\n");
	ft_printf("|      A        B      |\n");
	while ((stack_a) != NULL && (stack_b) != NULL)
	{
		ft_printf("|      %d        %d      |\n", (stack_a)->content,
			(stack_b)->content);
		stack_a = stack_a->next;
		stack_b = stack_b->next;
	}
	while ((stack_a != NULL))
	{
		ft_printf("|      %d               |\n", (stack_a)->content);
		stack_a = stack_a->next;
	}
	while ((stack_b != NULL))
	{
		ft_printf("|               %d      |\n", (stack_b)->content);
		stack_b = stack_b->next;
	}
	ft_printf("|                      |\n");
	ft_printf("------------------------\n");
}

void	visualizer(t_stack **stack_a, t_stack **stack_b)
{
	char	input[4];
	int		cont;

	input[0] = 's';
	cont = 0;
	print_tab(*stack_a, *stack_b);
	while (input[0] == 'p' || input[0] == 's' || input[0] == 'r')
	{
		ft_printf("next  mov: ");
		scanf("%s", input);
		if (input[0] == 'p')
			p_movs(stack_a, stack_b, input);
		else if (input[0] == 's')
			ss_movs(stack_a, stack_b, input);
		else if (input[0] == 'r' && input[2] != '\0')
			rrr_movs(stack_a, stack_b, input);
		else if (input[0] == 'r')
			rr_movs(stack_a, stack_b, input);
		cont++;
		print_tab(*stack_a, *stack_b);
		ft_printf("%i\n", cont);
	}
	ft_printf("ERRO, FIM DO PROGRAMA!\n");
}
