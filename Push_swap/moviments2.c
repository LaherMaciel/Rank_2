/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moviments2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 14:08:52 by lwencesl          #+#    #+#             */
/*   Updated: 2023/04/06 11:05:55 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// ss -> sa and sb at the same time.
void	ft_swap_swap(t_stack **stack_a, t_stack **stack_b)
{
	ft_printf("ss\n");
	ft_swap(stack_a, 'A');
	ft_swap(stack_b, 'B');
}

// rr -> ra and rb at the same time
void	ft_rotate_rotate(t_stack **stack_a, t_stack **stack_b)
{
	ft_printf("rr\n");
	ft_rotate(stack_a, 'A');
	ft_rotate(stack_b, 'B');
}

// rrr -> rra and rrb at the same time.
void	ft_reverse_rotate_rotate(t_stack **stack_a, t_stack **stack_b)
{
	ft_printf("rrr\n");
	ft_reverse_rotate(stack_a, 'A');
	ft_reverse_rotate(stack_b, 'B');
}
