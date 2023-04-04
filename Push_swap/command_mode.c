/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_mode.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 21:08:33 by lwencesl          #+#    #+#             */
/*   Updated: 2023/04/04 21:52:17 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	user_sort(t_stack **stack_a, t_stack **stack_b, char command)
{
	if (command[0] == 'p')
		p_movs(stack_a, stack_b, command);
	else if (command[0] == 's')
		ss_movs(stack_a, stack_b, command);
	else if (command[0] == 'r' && command[2] != '\0')
		rrr_movs(stack_a, stack_b, input);
	else if (command[0] == 'r')
		rr_movs(stack_a, stack_b, input);
	else if (command[0] != 'p' && command[0] != 's'
		&& command[0] != 'r' && command[0] != 'e')
		ft_printf("ERROR: VALID INPUTS -> 'numbers', ss," \
				" sa, sb, rr, ra, rb, rrr, rra," \
				" rrb, pa, pb or exit\n");
}

void	p_movs(t_stack **stack_a, t_stack **stack_b, char *command)
{
	if (command[1] == 'a')
		ft_pass_to(stack_b, stack_a, 'a');
	if (command[1] == 'b')
		ft_pass_to(stack_a, stack_b, 'b');
}

void	ss_movs(t_stack **stack_a, t_stack **stack_b, char *command)
{
	if (command[1] == 's')
		ft_swap_swap(stack_a, stack_b);
	if (command[1] == 'a')
		ft_swap(stack_a, 'a');
	if (command[1] == 'b')
		ft_swap(stack_b, 'b');
}

void	rr_movs(t_stack **stack_a, t_stack **stack_b, char *command)
{
	if (command[1] == 'r')
		ft_rotate_rotate(stack_a, stack_b);
	if (command[1] == 'a')
		ft_rotate(stack_a, 'a');
	if (command[1] == 'b')
		ft_rotate(stack_b, 'b');
}

void	rrr_movs(t_stack **stack_a, t_stack **stack_b, char *command)
{
	if (command[2] == 'r')
		ft_reverse_rotate_rotate(stack_a, stack_b);
	if (command[2] == 'a')
		ft_reverse_rotate(stack_a, 'a');
	if (command[2] == 'b')
		ft_reverse_rotate(stack_b, 'b');
}

