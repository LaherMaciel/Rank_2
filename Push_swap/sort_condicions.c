/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_condicions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 18:41:30 by lwencesl          #+#    #+#             */
/*   Updated: 2023/02/09 18:41:30 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	nr_movs(int pos, int stack_size)
{
	int	needed_movs;

	if (pos < 0)
		pos = stack_size + pos;
	else if (pos >= stack_size)
		pos = pos - stack_size;
	if (pos > (stack_size / 2))
		needed_movs = (stack_size + 1) - pos;
	else
		needed_movs = (pos) * (-1);
	return (needed_movs);
}

int	total_movs(int needed_movs1, int needed_movs2)
{
	int	sign1;
	int	sign2;

	sign1 = 1;
	sign2 = 1;
	if (needed_movs1 < 0)
	{
		needed_movs1 = needed_movs1 * (-1);
		sign1 = -1;
	}
	if (needed_movs2 < 0)
	{
		needed_movs2 = needed_movs2 * (-1);
		sign2 = -1;
	}
	if (needed_movs1 < needed_movs2)
		return (needed_movs1 * (sign1));
	return (needed_movs2 * (sign2));
}

int	total_movs_s(t_stack stack, int pos_1, int pos_2)
{
	int	nr_movs;

	pos_1 = nr_movs(pos_1, ft_lstsize(stack)));
	pos_2 = nr_movs(pos_2, ft_lstsize(stack));
	if (pos_1 == total_movs(pos_1, pos_2))
		nr_movs = s_decisions_cont(stack, pos_1, pos_2);	
	else
		nr_movs = s_decisions_cont(stack, pos_2, pos_1);
	return (nr_movs);
}

int	total_movs_p(t_stack src, t_stack dst, int pos_1, int pos_2)
{
	int	nr_movs;

	pos_1 = nr_movs(pos_1, ft_lstsize(src)));
	pos_2 = nr_movs(pos_2, ft_lstsize(dst));
	nr_movs = p_decisions_cont(find_val(srs, pos_1), find_val(dst, pos_2), pos_1, pos_2);
	return (nr_movs);
}

void	best_stack_s_mov(t_stack *stack, int (*best_movs)[3])
{
	int	smallest;
	int	movs;
	int	pos_1;
	int	pos_2;

	movs = 0;
	pos_1 = 0;
	pos_2 = find_biggest(stack);
	smallest = find_smallest(stack);
	while (pos_2 != smallest)
	{
		pos_1 = pos_2;
		pos_2 = find_smaller_then(stack, pos_1);
		movs = total_movs_s(stack, find_pos(stack, (pos_1)), find_pos(stack, (pos_2)));
		if (movs < *best_movs[0] && pos_2 != smallest && movs != 0)
		{
			(*best_movs)[0] = movs;
			(*best_movs)[1] = find_pos(stack, (pos_1));
			(*best_movs)[2] = find_pos(stack, (pos_2));
		}
	}
}

void	best_stack_p1p2_mov(t_stack *src,
		t_stack *dst, int (*best_movs)[3])
{
	int	smallest;
	int	movs;
	int	pos1;
	int	pos2;

	movs = 0;
	pos2 = 0;
	pos1 = find_biggest(src);
	smallest = find_smallest(src);
	while (pos1 != smallest)
	{
		pos2 = find_smaller_then(dst, pos1);
		movs = total_movs_p( src, dst, find_pos(stack, (pos_1)), find_pos(stack, (pos_2)))
		if (movs < best_movs[0][0] && pos2 != smallest)
		{
			(*best_movs)[0] = movs;
			(*best_movs)[1] = find_pos(stack, (pos_1));
			(*best_movs)[2] = find_pos(stack, (pos_2));
		}
		pos1 = find_smaller_then(src, pos1);
	}
}
