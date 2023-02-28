/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_conditions2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 21:55:56 by lwencesl          #+#    #+#             */
/*   Updated: 2023/02/28 21:57:58 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	best_stack_sa_mov(t_stack *stack, int best_movs[3])
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
		movs = total_movs_s(stack, find_pos(stack, (pos_1)),
				find_pos(stack, (pos_2)));
		if (movs < best_movs[0] && pos_2 != smallest && movs != 0)
		{
			best_movs[0] = movs;
			best_movs[1] = find_pos(stack, (pos_1));
			best_movs[2] = find_pos(stack, (pos_2));
		}
	}
}

void	best_stack_p_mov(t_stack *src,
		t_stack *dst, int best_movs[3])
{
	int	smallest;
	int	movs;
	int	pos_1;
	int	pos_2;

	movs = 0;
	pos_2 = 0;
	pos_1 = find_biggest(src);
	smallest = find_smallest(src);
	while (pos_1 != smallest)
	{
		pos_2 = find_smaller_then(dst, pos_1);
		movs = total_movs_p(src, dst, find_pos(src,
					(pos_1)), find_pos(dst, (pos_2)));
		if (movs < best_movs[0] && pos_2 != smallest && movs != 0)
		{
			best_movs[0] = movs;
			best_movs[1] = find_pos(src, (pos_1));
			best_movs[2] = find_pos(dst, (pos_2));
		}
		pos_1 = find_smaller_then(src, pos_1);
	}
}
