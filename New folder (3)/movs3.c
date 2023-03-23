/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movs3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 14:23:00 by lwencesl          #+#    #+#             */
/*   Updated: 2023/02/24 14:23:18 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	p_movs(t_stack **stack_a, t_stack **stack_b, char *input)
{
	if (input[1] == 'a')
		ft_pass_to(stack_b, stack_a, 'a');
	if (input[1] == 'b')
		ft_pass_to(stack_a, stack_b, 'b');
}

void	ss_movs(t_stack **stack_a, t_stack **stack_b, char *input)
{
	if (input[1] == 's')
		ft_swap_swap(stack_a, stack_b);
	if (input[1] == 'a')
		ft_swap(stack_a, 'a');
	if (input[1] == 'b')
		ft_swap(stack_b, 'b');
}

void	rr_movs(t_stack **stack_a, t_stack **stack_b, char *input)
{
	if (input[1] == 'r')
		ft_rotate_rotate(stack_a, stack_b);
	if (input[1] == 'a')
		ft_rotate(stack_a, 'a');
	if (input[1] == 'b')
		ft_rotate(stack_b, 'b');
}

void	rrr_movs(t_stack **stack_a, t_stack **stack_b, char *input)
{
	if (input[2] == 'r')
		ft_reverse_rotate_rotate(stack_a, stack_b);
	if (input[2] == 'a')
		ft_reverse_rotate(stack_a, 'a');
	if (input[2] == 'b')
		ft_reverse_rotate(stack_b, 'b');
}
