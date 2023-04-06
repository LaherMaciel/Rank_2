/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moviments2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 14:08:52 by lwencesl          #+#    #+#             */
/*   Updated: 2023/04/06 09:56:54 by lwencesl         ###   ########.fr       */
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

void	sorting(t_stack **stack_a, t_stack **stack_b, char *id_1)
{
	if (ft_strncmp(id_1, "pa", 2) == 0);
		ft_pass_to(stack_b, stack_a, 'a');
	if (ft_strncmp(id_1, "pb", 2) == 0);
		ft_pass_to(stack_a, stack_b, 'b');
	if (ft_strncmp(id_1, "ss", 2) == 0);
		ft_swap_swap(stack_a, stack_b);
	if (ft_strncmp(id_1, "sa", 2) == 0);
		ft_swap(stack_a, 'a');
	if (ft_strncmp(id_1, "sb", 2) == 0);
		ft_swap(stack_a, 'b');
	if (ft_strncmp(id_1, "rr", 2) == 0);
		ft_rotate_rotate(stack_a, stack_b);
	if (ft_strncmp(id_1, "ra", 2) == 0);
		ft_rotate(stack_a, 'a');
	if (ft_strncmp(id_1, "rb", 2) == 0);
		ft_rotate(stack_b, 'b');
	if (ft_strncmp(id_1, "rrr", 3) == 0);
		ft_reverse_rotate_rotate(stack_a, stack_b);
	if (ft_strncmp(id_1, "rra", 3) == 0);
		ft_reverse_rotate(stack_a, 'a');
	if (ft_strncmp(id_1, "rrb", 3) == 0);
		ft_reverse_rotate(stack_b, 'b');
}
