/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 19:16:34 by lwencesl          #+#    #+#             */
/*   Updated: 2023/03/05 13:17:01 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_stack **stack_1, t_stack **stack_2, char *id_1)
{
	//ft_printf("sort_3 in\n");
	ft_printf("*id_1 -> %i\n", id_1);
	if (id_1[0] == 'r' && id_1[1] == 'r' && id_1[2] == 'r' && ft_strlen(id_1) == 3)
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
	//ft_printf("\nsort_3 out\n");
}

void	sort_1(t_stack **stack_1, t_stack **stack_2, int *pb)
{
	char *pb_id;

	pb_id = pb_decisions(*stack_1, *stack_2, pb[1], pb[2]);
	//ft_printf("sa_id -> %s	|	pb_id -> %s\n", sa_id, pb_id);
	//ft_printf("sort_1 in\n");
	//ft_printf("sa[0] = %i > nr_movs biggest = %i\n", sa[0], (nr_movs(find_pos(*stack_1, find_biggest(*stack_1)), ft_lstsize(*stack_1))));
	//ft_printf("BEST MOVS sa[0] = %i > pb[0] = %i\n", sa[0], pb[0]);
	//ft_printf("sort_1 second if in\n");
	//ft_printf("sa[0] = %i < pb[0] = %i\n", sa[0], pb[0]);
	sort_3(stack_1, stack_2, pb_id);
	//ft_printf("\nsort_1 out\n");
}

int	sort_p(t_stack **stack_1, t_stack **stack_2)
{
	int		pb[4];
	int		done;

	done = 0;
	pb[0] = INT_MAX;
	best_stack_p_mov(*stack_1, *stack_2, pb);
	ft_printf("BEST pb[ %i | pos1 -> %i val1 -> %i | pos2 -> %i val2 -> %i ];\n", pb[0], pb[1],
		find_val(*stack_1, pb[1]), pb[2], find_val(*stack_2, pb[2]));
	sort_1(stack_1, stack_2, pb);
}

void	sort_s_3(t_stack **stack, char id)
{
	int	out;

	out = 0;
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
		if (ft_lstsize(stack_a) <= 3 && sa_ord == 0)
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
}
