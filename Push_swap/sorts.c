/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorts.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 14:10:07 by lwencesl          #+#    #+#             */
/*   Updated: 2023/02/09 21:33:07 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

t_stack	*sort3(t_stack *stack, char id)
{
	int	out;

	out = 0;
	while (out != 1)
	{
		if (stack->content > stack->next->content && stack > stack->next->next->content)
			ft_reverse_rotate(stack, id);
		else if (stack->content > stack->next->content)
			ft_swap(stack, id);
		else if (stack->content > stack->next->next->content)
			ft_rotate(stack, id);
		else if (stack->next->content > stack->next->next->content)
			ft_rotate(stack, id);
		else
			out = 1;
	}
	return	(stack);
}

t_stack	*sort_4_to_6(t_stack **stack_1, t_stack **stack_2)
{
	t_stack	*last_1;
	t_stack	*last_2;
	int		smallest;
	int		biggest_1;

	while (!stack_1->next->next->next)
	{	
		ft_pass_to(stack_1, stack_2, 'b');
		stack_1 = stack_1->next;
	}
	sort3(stack_1, 'a');
	sort3(stack_2, 'b');
	last_1 = ft_lstlast(stack_1);
	last_2 = ft_lstlast(stack_2);
	biggest_1 = last_1->content;
	if (stack_1->content < stack_2->content)
		smallest = stack_1->content;
	else
		smallest = stack_2->content;
	merge(stack_1, stack_2, biggest_1);
	return	(stack);
}

void	merge(t_stack **stack_1, t_stack **stack_2, int biggest_1)
{
	int	out;

	out = 0;
	while (out != 2 && !stack_2)
	{
		if (stack_1->content  > stack_2->content)
			ft_pass_to(stack_2, stack_1, 'a');
		else if (stack_1->content  < stack_2->content && biggest_1 > stack_2->content)
			rotate_up_or_down(stack_1, stack_2, 'a');
		else if (biggest_1 < stack_2->content)
			rotate_up_or_down_biggest(stack_1, stack_2, 'a', biggest_1);
		else
			out++;
	}
	ft_smallest_on_top(stack_1, smallest, 'a');
}
