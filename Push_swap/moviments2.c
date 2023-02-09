/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moviments2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 14:08:52 by lwencesl          #+#    #+#             */
/*   Updated: 2023/02/09 14:09:25 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_push_swap.h"

// Shift down all elements of the stack by 1. 
// The last element becomes the first one.
void	ft_reverse_rotate(t_stack **stack, char id)
{
	t_stack	*new_last;
	t_stack	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	if (id == 'a' || id == 'b')
		ft_printf("rr%c", id);
	new_last = *stack;
	while (new_last->next->next != NULL)
		new_last = new_last->next;
	last = new_last->next;
	last->next = *stack;
	*stack = last;
	new_last->next = NULL;
}

// rrr -> rra and rrb at the same time.
void	ft_reverrse_rotate_rotate(t_stack stack_1, t_stack stack_2)
{
	ft_reverrse_rotate(stack_1, 'A');
	ft_reverrse_rotate(stack_2, 'B');
	ft_printf("rrr");
}
