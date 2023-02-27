/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorts2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 06:33:41 by lwencesl          #+#    #+#             */
/*   Updated: 2023/02/25 15:42:25 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// receive the position and the stack and returns the number of
//  movements needed to send the value in that position to the star of the stack
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

int	if_dif_signs(int val_pos1, int val_pos2,
int stack_size1, int stack_size2 )
{
	int	sign1;
	int	sign2;
	int	needed_movs1;
	int	needed_movs2;

	sign1 = 1;
	sign2 = 1;
	needed_movs1 = nr_movs(val_pos1, stack_size1);
	needed_movs2 = nr_movs(val_pos2, stack_size2);
	if (needed_movs1 < 0)
	{
		needed_movs1 = needed_movs1 * (-1);
		sign1 = -1;
	}
	else if (needed_movs2 < 0)
	{
		needed_movs2 = needed_movs2 * (-1);
		sign2 = -1;
	}

	if (needed_movs1 < needed_movs2)
		return ((needed_movs1 * sign1) + nr_movs(val_pos2
				+ (needed_movs1 * sign1), stack_size2));
	return ((needed_movs2 * sign2) + (nr_movs(val_pos1
				+ (needed_movs2 * sign2), stack_size1)));
}

int	total_movs(int val_pos1, int val_pos2,
int stack_size1, int stack_size2)
{
	int	total_movs_need;
	int	needed_movs1;
	int	needed_movs2;

	needed_movs1 = nr_movs(val_pos1, stack_size1);
	needed_movs2 = nr_movs(val_pos2, stack_size2);
	if (needed_movs1 * needed_movs2 < 0)
		total_movs_need = if_dif_signs(val_pos1,
				val_pos2, stack_size1, stack_size2);
	else
	{
		if (needed_movs1 > needed_movs2)
			total_movs_need = needed_movs1 + (needed_movs1 - needed_movs2);
		else
			total_movs_need = needed_movs2 + (needed_movs2 - needed_movs1);
	}
	return (total_movs_need);
}

void	best_stack_ord_mov(t_stack *stack, int (*best_movs)[3])
{
	int	smallest;
	int	movs;
	int	pos1;
	int	pos2;
	int	stack_size;

	movs = 0;
	pos1 = 0;
	pos2 = find_biggest(stack);
	smallest = find_smallest(stack);
	stack_size = ft_lstsize(stack);
	while (pos2 != smallest)
	{
		pos1 = pos2;
		pos2 = find_smaller_then(stack, pos1);
		if ((find_pos(stack, pos1) - find_pos(stack, pos2)) != 1
			|| find_pos(stack, pos2) - find_pos(stack,
				find_smaller_then(stack, pos2)) != 1)
		{
			movs = total_movs(find_pos(stack, pos1),
					find_pos(stack, pos2), stack_size, stack_size);
			if (movs < *best_movs[0] && pos2 != smallest && (movs != 0 || movs != 1))
			{
				(*best_movs)[0] = movs;
				(*best_movs)[1] = pos1;
				(*best_movs)[2] = pos2;
			}
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
	pos1 = 0;
	pos2 = find_biggest(src);
	smallest = find_smallest(dst);
	while (pos2 != smallest)
	{
		pos1 = find_smaller_then(src, pos1);
		pos2 = find_smaller_then(dst, pos1);
		movs = total_movs(find_pos(src, pos1), find_pos(dst, pos2),
				ft_lstsize(src), ft_lstsize(dst));
		if (movs < best_movs[0][0] && pos2 != smallest)
		{
			(*best_movs)[0] = movs;
			(*best_movs)[1] = pos1;
			(*best_movs)[2] = pos2;
		}
	}
}
