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

void	sort_1(t_stack **stack_1, t_stack **stack_2, char *id_1)
{
	if (!stack_2)
		return ;
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

void	sort_p(t_stack **stack_1, t_stack **stack_2, int fase)
{
	int		pb[4];
	char	*id;

	if (*stack_1 == NULL)
		return ;
	pb[0] = INT_MAX;
	if (fase == 0)
	{
		best_stack_pb_mov(*stack_1, *stack_2, pb);
		id = pb_decisions(*stack_1, *stack_2, pb[1], pb[2]);
	}
	else
	{
		best_stack_pa_mov(*stack_1, *stack_2, pb);
		if (ft_lstsize(*stack_1) == 1 && ft_lstsize(*stack_2) > 3 && pb[1] == 1)
			pb[1] = 0;
		id = pa_decisions(*stack_1, *stack_2, pb[1], pb[2]);
	}
	if ((id[0] == 'r' && id[1] == 'b') || (id[0] == 'r'
			&& id[1] == 'r' && id[2] == 'b') || (id[0] == 'p' && id[0] == 'a'))
		sort_1(stack_2, stack_1, id);
	else
		sort_1(stack_1, stack_2, id);
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

int	sort_cut(t_stack **stack_a, t_stack **stack_b, int *nr, int *cont)
{
	int	sa_ord;

	sa_ord = 0;
	if (ft_lstsize(*stack_a) <= 3 && sa_ord == 0)
	{
		sort_s_3(stack_a, 'a', cont);
		sa_ord = 1;
	}
	else if (sa_ord == 0)
	{
		*nr = find_above_media(*stack_a, 0, 0);
		if (*nr > 0)
			ft_reverse_rotate(stack_a, 'a');
		else if (*nr < 0)
			ft_rotate(stack_a, 'a');
		else
			ft_pass_to(stack_a, stack_b, 'b');
	}
	return (sa_ord);
}

void	sort(t_stack **stack_a, t_stack **stack_b, int *cont)
{
	int	sa_ord;
	int	done;
	int	stop;
	int	nr;

	stop = ft_lstsize(*stack_a) * 5;
	sa_ord = 0;
	done = 0;
	while ((done == 0 || *stack_b))
	{
		if ((*cont > stop - 10) || (stop < 10)
			|| *cont < 10 || (ft_lstsize(*stack_a) <= 3))
		{
			print_tab(*stack_a, *stack_b);
			ft_printf("\ncont -> %i\n", *cont);
		}
		sa_ord = sort_cut(stack_a, stack_b, &nr, cont);
		if (ft_lstsize(*stack_a) > 3 && sa_ord == 1)
		{
			sort_p(stack_b, stack_a, sa_ord);
			done = 1;
		}
		*cont = *cont + 1;
	}
}