/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movimentos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 03:09:38 by lwencesl          #+#    #+#             */
/*   Updated: 2023/02/09 03:09:38 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Swap the first 2 elements at the top of stack. 
// Do nothing if there is only one or no elements.
void	ft_swap(t_stack *stack, char id)
{
	t_stack	*tmp;

	if (!stack || !stack->next)
		return ;
	if (id == 'a' || id == 'b')
		ft_printf("s%c", id);
	tmp = stack->content;
	stack->content = stack->next->content;
	stack->next->content = tmp;
}

// ss -> sa and sb at the same time.
void	ft_swap_swap(t_stack *stack_a, t_stack *stack_b)
{
	ft_swap(stack_a, 'A');
	ft_swap(stack_b, 'B');
	ft_printf("ss");
}

// Take the first element at the top of the stack_2 and put it at the
// top of the stack_1. Do nothing if stack_2 is empty.
// pa = stack b -> stack a ||  pb = stack a -> stack b
void	ft_pass_to(t_stack **stack_1, t_stack **stack_2, char id)
{
	t_stack	*tmp;
	int		val;

	if (!*stack_2 || !(*stack_2))
		return ;
	if (id == 'a' || id == 'b')
		ft_printf("p%c", id);
	tmp = *stack_2;
	*stack_2 = (*stack_2)->next;
	tmp->next = *stack_1;
	*stack_1 = tmp;
}

// Shift up all elements of the stack by 1. 
// The first element becomes the last one.
void	ft_rotate(t_stack **stack, char id)
{
	t_stack	*new_last;
	t_stack	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	if (id == 'a' || id == 'b')
		ft_printf("r%c", id);
	new_last = *stack;
	*stack = (*stack)->next;
	last = ft_lstlast(stack);
	last->next = new_last;
	new_last->next = NULL;
}

// rr -> ra and rb at the same time
void	ft_rotate_rotate(t_stack *stack_1, t_stack *stack_2)
{
	ft_rotate(stack_1, 'A');
	ft_rotate(stack_2, 'B');
	ft_printf("rr");
}
