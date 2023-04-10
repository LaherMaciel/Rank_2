/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 09:36:32 by lwencesl          #+#    #+#             */
/*   Updated: 2023/04/10 06:38:54 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sorting(t_stack **stack_a, t_stack **stack_b, char *id_1)
{
	if (ft_strncmp(id_1, "pa", 2) == 0)
		ft_pass_to(stack_b, stack_a, 'a');
	if (ft_strncmp(id_1, "pb", 2) == 0)
		ft_pass_to(stack_a, stack_b, 'b');
	if (ft_strncmp(id_1, "ss", 2) == 0)
		ft_swap_swap(stack_a, stack_b);
	if (ft_strncmp(id_1, "sa", 2) == 0)
		ft_swap(stack_a, 'a');
	if (ft_strncmp(id_1, "sb", 2) == 0)
		ft_swap(stack_a, 'b');
	if (ft_strncmp(id_1, "rr", 2) == 0)
		ft_rotate_rotate(stack_a, stack_b);
	if (ft_strncmp(id_1, "ra", 2) == 0)
		ft_rotate(stack_a, 'a');
	if (ft_strncmp(id_1, "rb", 2) == 0)
		ft_rotate(stack_b, 'b');
	if (ft_strncmp(id_1, "rrr", 3) == 0)
		ft_reverse_rotate_rotate(stack_a, stack_b);
	if (ft_strncmp(id_1, "rra", 3) == 0)
		ft_reverse_rotate(stack_a, 'a');
	if (ft_strncmp(id_1, "rrb", 3) == 0)
		ft_reverse_rotate(stack_b, 'b');
}

void	sort_s_3(t_stack **stack, char id, int *cont)
{
	int	out;

	out = 0;
	if (!stack)
		return ;
	while (out != 1)
	{
		if ((*stack)->content > (*stack)->next->content
			&& (*stack)->next->content > (*stack)->next->next->content)
			ft_rotate(stack, id);
		else if (((*stack)->content < (*stack)->next->content)
			&& ((*stack)->content > (*stack)->next->next->content))
			ft_reverse_rotate(stack, id);
		else if (((*stack)->content > (*stack)->next->content)
			&& ((*stack)->content > (*stack)->next->next->content))
			ft_rotate(stack, id);
		else if (((*stack)->content < (*stack)->next->content)
			&& ((*stack)->next->content > (*stack)->next->next->content))
			ft_reverse_rotate(stack, id);
		else if (((*stack)->content > (*stack)->next->content))
			ft_swap(stack, id);
		else
			out = 1;
		cont++;
	}
}

void	sort_p(t_stack **stack_a, t_stack **stack_b, int fase)
{
	int		pb[4];
	char	*id;

	if (*stack_a == NULL)
		return ;
	pb[0] = INT_MAX;
	if (fase == 0)
	{
		best_stack_pb_mov(*stack_a, *stack_b, pb);
		id = p_decisions(*stack_a, *stack_b, pb[1], pb[2]);
	}
	else
	{
		best_stack_pa_mov(*stack_a, *stack_b, pb);
		if (ft_lstsize(*stack_a) == 1 && ft_lstsize(*stack_b) > 3 && pb[1] == 1)
			pb[1] = 0;
		id = p_decisions(*stack_b, *stack_a, pb[1], pb[2]);
	}
	sorting(stack_a, stack_b, id);
}

int	sort_cut(t_stack **stack_a, t_stack **stack_b, int *sa_ord, int *cont)
{
	int	nr;

	nr = 0;
	if (ft_lstsize(*stack_a) <= 3 && sa_ord == 0)
	{
		sort_s_3(stack_a, 'a', cont);
		*sa_ord = 1;
	}
	else if (sa_ord == 0)
	{
		nr = find_above_media(*stack_a, 0, 0);
		if (nr > 0)
			ft_reverse_rotate(stack_a, 'a');
		else if (nr < 0)
			ft_rotate(stack_a, 'a');
		else
			ft_pass_to(stack_a, stack_b, 'b');
	}
	return (nr);
}

void	sort_s_3(t_stack **stack, char id, int *cont)
{
	int	out;

	out = 0;
	if (!stack)
		return ;
	while (out != 1)
	{
		if ((*stack)->content > (*stack)->next->content
			&& (*stack)->next->content > (*stack)->next->next->content)
			ft_rotate(stack, id);
		else if (((*stack)->content < (*stack)->next->content)
			&& ((*stack)->content > (*stack)->next->next->content))
			ft_reverse_rotate(stack, id);
		else if (((*stack)->content > (*stack)->next->content)
			&& ((*stack)->content > (*stack)->next->next->content))
			ft_rotate(stack, id);
		else if (((*stack)->content < (*stack)->next->content)
			&& ((*stack)->next->content > (*stack)->next->next->content))
			ft_reverse_rotate(stack, id);
		else if (((*stack)->content > (*stack)->next->content))
			ft_swap(stack, id);
		else
			out = 1;
		cont++;
	}
}

void	sort(t_stack **stack_a, t_stack **stack_b, int *cont)
{
	int	sa_ord;
	int	done;
	int	stop;
	int	nr;

	stop = ft_lstsize(*stack_a) * 5;
	done = 0;
	sa_ord = 0;
	while (done == 0 || *stack_b)
	{
		if ((*cont > stop - 10) || (stop < 10)
			|| *cont < 10 || (ft_lstsize(*stack_a) <= 3))
		{
			print_tab(*stack_a, *stack_b);
			ft_printf("\ncont -> %i\n", *cont);
		}
		nr = sort_cut(stack_a, stack_b, &sa_ord, cont);
		if (ft_lstsize(*stack_a) > 3 && sa_ord != 0)
		{
			sort_p(stack_b, stack_a, sa_ord);
			done = 1;
		}
		*cont = *cont + 1;
	}
}
