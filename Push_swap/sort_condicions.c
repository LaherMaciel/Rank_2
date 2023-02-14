/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_condicions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 18:41:30 by lwencesl          #+#    #+#             */
/*   Updated: 2023/02/09 18:41:30 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_up_or_down(t_stack **stack_1, t_stack **stack_2, char id)
{
	int	bigger_pos;
	int	stack_size;
	int	i;

	i = -1;
	stack_size = ft_lstsize(stack_1) + 1;
	bigger_pos = find_bigger(stack_1, stack_2->content);
	if (bigger_pos > (stack_size / 2))
	{
		while (--stack_size >= bigger_pos)
			ft_reverse_rotate(stack_1, id);
	}
	else
	{
		while (++i >= bigger_pos)
			ft_rotate(stack_1, id);
	}
	ft_pass_to(stack_2, stack_1, id);
}

void	rotate_up_or_down_biggest(t_stack **stack_1,
t_stack **stack_2, char id, int val)
{
	int	bigger_pos;
	int	stack_size;
	int	i;

	i = -1;
	stack_size = ft_lstsize(stack_1) + 1;
	bigger_pos = find_val(stack_1, val);
	if (bigger_pos > (stack_size / 2))
	{
		while (--stack_size >= bigger_pos)
			ft_reverse_rotate(stack_1, id);
	}
	else
	{
		while (++i >= bigger_pos)
			ft_rotate(stack_1, id);
	}
	ft_pass_to(stack_2, stack_1, id);
}

void	ft_smallest_on_top(t_stack **stack_1, int smallest, char id)
{
	int	smallest_pos;
	int	stack_size;
	int	i;

	i = -1;
	stack_size = ft_lstsize(stack_1) + 1;
	smallest_pos = find_val(stack_1, smallest);
	if (smallest_pos > (stack_size / 2))
	{
		while (--stack_size >= smallest_pos)
			ft_reverse_rotate(stack_1, id);
	}
	else
	{
		while (++i >= smallest_pos)
			ft_rotate(stack_1, id);
	}
}


