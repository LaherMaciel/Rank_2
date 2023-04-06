/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 21:16:17 by lwencesl          #+#    #+#             */
/*   Updated: 2023/04/06 10:02:33 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	user_sort(t_stack **stack_a, t_stack **stack_b, char *command)
{
	int	i;

	i = -1;
	while (command[i] != '\0')
	{
		if (stack_a == NULL && command[i] == 'a'
			&& command[0] != 'p')
			ft_printf("Can't do this movement, stack_a empty.\n");
		if (stack_b == NULL && command[i] == 'b'
			&& command[0] != 'p')
			ft_printf("Can't do this movement, stack_b empty.\n");
	}
	sorting(stack_a, stack_b, command);
	else if (commands_check(command) == 0)
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

