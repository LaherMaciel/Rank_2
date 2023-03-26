/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualizer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 13:02:12 by lwencesl          #+#    #+#             */
/*   Updated: 2023/03/06 09:56:35 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_tab(t_stack *stack_a, t_stack *stack_b)
{
	int	cont;

	cont = 0;
	ft_printf("\n---------------------------------"\
	"--------------------------------\n");
	ft_printf("|	PS	|	NMA	A	|	NMB	B	|\n");
	ft_printf("|---------------|-------------"\
	"----------|-----------------------|\n");
	while (stack_a && stack_b)
	{
		if ((ft_lstsize(stack_a)) >= cont && (ft_lstsize(stack_b)) >= cont)
			ft_printf("|	%i	|	%i	%d	|	%i	%d	|\n", cont, (-cont),
				(stack_a)->content, (-cont), (stack_b)->content);
		if ((ft_lstsize(stack_a)) >= cont && (ft_lstsize(stack_b)) < cont)
			ft_printf("|	%i	|	%i	%d	|	%i	%d	|\n", cont, (-cont),
				(stack_a)->content, ft_lstsize(stack_b), (stack_b)->content);
		if ((ft_lstsize(stack_a)) < cont && (ft_lstsize(stack_b)) < cont)
			ft_printf("|	%i	|	%i	%d	|	%i	%d	|\n", cont,
				ft_lstsize(stack_a), (stack_a)->content, ft_lstsize(stack_b),
				(stack_b)->content);
		if ((ft_lstsize(stack_a)) < cont && (ft_lstsize(stack_b)) >= cont)
			ft_printf("|	%i	|	%i	%d	|	%i	%d	|\n", cont,
				ft_lstsize(stack_a), (stack_a)->content, (-cont),
				(stack_b)->content);
		stack_a = stack_a->next;
		stack_b = stack_b->next;
		cont++;
	}
	while (stack_a)
	{
		if (ft_lstsize(stack_a) >= cont)
			ft_printf("|	%i	|	%i	%d	|			|\n", cont,
				(-cont), (stack_a)->content);
		if (ft_lstsize(stack_a) < cont)
			ft_printf("|	%i	|	%i	%d	|			|\n", cont,
				ft_lstsize(stack_a), (stack_a)->content);
		cont++;
		stack_a = stack_a->next;
	}
	while (stack_b)
	{
		if (ft_lstsize(stack_b) >= cont)
			ft_printf("|	%i	|			|	%i	%d	|\n", cont,
				(-cont), (stack_b)->content);
		if (ft_lstsize(stack_b) < cont)
			ft_printf("|	%i	|			|	%i	%d	|\n", cont,
				ft_lstsize(stack_b), (stack_b)->content);
		cont++;
		stack_b = stack_b->next;
	}
	ft_printf("----------------------------------------"\
		"-------------------------\n");
}

/*
void	visualizer(t_stack **stack_a, t_stack **stack_b)
{
	char	input[5];
	int		cont;

	input[0] = 's';
	cont = 0;
	print_tab(*stack_a, *stack_b);
	while (input[0] != 'e')
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
		else if (input[0] != 'p' && input[0] != 's'
			&& input[0] != 'r' && input[0] != 'e')
			ft_printf("ERROR: VALID INPUT -> ss," \
					" sa, sb, rr, ra, rb, rrr, rra," \
					" rrb, pa, pb or exit\n");
		if (input[0] == 'p' || input[0] == 's'
			|| input[0] == 'r')
		{
			cont++;
			print_tab(*stack_a, *stack_b);
			ft_printf("%i\n", cont);
		}
	}
	ft_printf("FIM DO PROGRAMA!\n");
}
*/

void	visualizer2(t_stack **stack_a, t_stack **stack_b)
{
	int		cont;
	int		done;

	cont = 0;
	done = 0;
	ft_printf("visualizer2 in\n");
	print_tab(*stack_a, *stack_b);
	while (done == 0 && cont < 200)
	{
		done = sort(stack_a, stack_b);
		ft_printf("\ndone = %i\n\n", done);
		if (done == 0)
			cont++;
		print_tab(*stack_a, *stack_b);
		ft_printf("%i\n", cont);
	}
	ft_printf("visualizer2 out\n");
	ft_printf("FIM DO PROGRAMA!\n");
}