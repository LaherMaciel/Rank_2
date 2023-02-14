/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moviments2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 14:08:52 by lwencesl          #+#    #+#             */
/*   Updated: 2023/02/12 11:34:23 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

// ss -> sa and sb at the same time.
void	ft_swap_swap(t_stack *stack_a, t_stack *stack_b)
{
	ft_swap(stack_a, 'A');
	ft_swap(stack_b, 'B');
	ft_printf("ss");
}

// rr -> ra and rb at the same time
void	ft_rotate_rotate(t_stack *stack_1, t_stack *stack_2)
{
	ft_rotate(stack_1, 'A');
	ft_rotate(stack_2, 'B');
	ft_printf("rr");
}

// rrr -> rra and rrb at the same time.
void	ft_reverse_rotate_rotate(t_stack **stack_1, t_stack **stack_2)
{
	ft_reverse_rotate(stack_1, 'A');
	ft_reverse_rotate(stack_2, 'B');
	ft_printf("rrr");
}
