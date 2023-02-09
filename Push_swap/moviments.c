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

#include "push_swap.h"

// Swap the first 2 elements at the top of stack. 
// Do nothing if there is only one or no elements.
void	ft_swap(t_list *stack, char id)
{
	t_list	*tmp;

	if (!stack || !stack->next)
		return ;
	if (id == 'a' || id == 'b')
		ft_printf("s%c", id);
	tmp = stack->content;
	stack->content = stack->next->content;
	stack->next->content = tmp; 
}

// ss -> sa and sb at the same time.
void	ft_swap_swap(t_list *stack_a, t_list *stack_b)
{
	ft_swap(stack_a, 'A');
	ft_swap(stack_b, 'B');
	ft_printf("ss"); 
}

// Take the first element at the top of the stack_2 and put it at the
// top of the stack_1. Do nothing if stack_2 is empty.
// pa = stack b -> stack a ||  pb = stack a -> stack b
void	ft_pass_to(t_list **stack_1, t_list **stack_2, char id)
{
	t_list	*tmp;
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
void	ft_rotate(t_list **stack, char id)
{
	t_list	*new_last;
	t_list	*last;
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
void	ft_rotate_rotate(t_list *stack_1, t_list *stack_2)
{
	ft_rotate(stack_1, 'A');
	ft_rotate(stack_2, 'B');
	ft_printf("rr");
}

// Shift down all elements of the stack by 1. 
// The last element becomes the first one.
void	ft_reverse_rotate(t_list **stack, char id)
{
	t_list	*new_last;
	t_list	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	if (id == 'a' || id == 'b')
		ft_printf("rr%c", id);
	new_last = *stack;
	while(new_last->next->next != NULL)
		new_last = new_last->next;
	last = new_last->next;
	last->next = *stack;
	*stack = last;
	new_last->next = NULL;
}

// rrr -> rra and rrb at the same time.
void	ft_reverrse_rotate_rotate(t_list stack_1, t_list stack_2)
{
	ft_reverrse_rotate(stack_1, 'A');
	ft_reverrse_rotate(stack_2, 'B');
	ft_printf("rrr");
}
