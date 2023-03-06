/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 19:16:34 by lwencesl          #+#    #+#             */
/*   Updated: 2023/03/06 10:00:27 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_1(t_stack **stack_1, t_stack **stack_2, int *pb)
{
	char	*id_1;

	if (!stack_2)
		return ;
	id_1 = pb_decisions(*stack_1, *stack_2, pb[1], pb[2]);
	if (id_1[0] == 'r' && id_1[1] == 'r'
		&& id_1[2] == 'r' && ft_strlen(id_1) == 3)
		ft_reverse_rotate_rotate(stack_1, stack_2);
	else if (id_1[0] == 'r' && id_1[1] == 'r' && ft_strlen(id_1) == 3)
		ft_reverse_rotate(stack_1, id_1[2]);
	else if (id_1[0] == 'r' && id_1[1] == 'r')
		ft_rotate_rotate(stack_1, stack_2);
	else if (id_1[0] == 'r' && ft_strlen(id_1) == 2)
		ft_rotate(stack_1, id_1[1]);
	else if (id_1[0] == 's')
		ft_swap(stack_1, id_1[1]);
	else if (id_1[0] == 'p' || id_1[0] == 'p')
		ft_pass_to(stack_1, stack_2, id_1[1]);
}

void	sort_p(t_stack **stack_1, t_stack **stack_2)
{
	int		pb[4];

	if (!stack_2)
		return ;
	pb[0] = INT_MAX;
	best_stack_p_mov(*stack_1, *stack_2, pb);
	ft_printf("BEST pb[ %i | pos1 -> %i val1 -> %i | "\
		"pos2 -> %i val2 -> %i ];\n", pb[0], pb[1],
		find_val(*stack_1, pb[1]), pb[2], find_val(*stack_2, pb[2]));
	sort_1(stack_1, stack_2, pb);
}

void	sort_s_3(t_stack **stack, char id)
{
	int	out;

	out = 0;
	if (!stack)
		return ;
	while (out != 1)
	{
		if ((*stack)->content > (*stack)->next->content
			&& (*stack)->content > (*stack)->next->next->content)
			ft_reverse_rotate(stack, id);
		else if ((*stack)->content > (*stack)->next->content)
			ft_swap(stack, id);
		else if ((*stack)->content > (*stack)->next->next->content)
			ft_rotate(stack, id);
		else if ((*stack)->next->content > (*stack)->next->next->content)
			ft_rotate(stack, id);
		else
			out = 1;
	}
}

int	sort(t_stack **stack_a, t_stack **stack_b)
{
	int	sa_ord;
	int	done;
	int	cont;

	sa_ord = 0;
	done = 0;
	cont = 0;
	while (done == 0 || stack_b)
	{
		if (ft_lstsize(*stack_a) <= 3 && sa_ord == 0)
		{
			sort_s_3(stack_a, 'a');
			sa_ord = 1;
		}
		else if (sa_ord == 0)
			sort_p(stack_a, stack_b);
		else
		{
			sort_p(stack_b, stack_a);
			done = 1;
		}
		cont++;
		ft_printf("cont -> %i\n", cont);
	}
	return (done);
}
