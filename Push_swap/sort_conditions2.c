/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_conditions2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 21:55:56 by lwencesl          #+#    #+#             */
/*   Updated: 2023/03/02 05:08:46 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*best_stack_sa_mov(t_stack *stack, int *best_movs)
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
		pos_2 = find_smaller_then(stack, pos_1, smallest);
		movs = total_movs_s(stack, find_pos(stack, (pos_1)),
				find_pos(stack, (pos_2)));
		if (movs < best_movs[0] && movs != 0)
		{
			best_movs[0] = movs;
			best_movs[1] = nr_movs(find_pos(stack, (pos_1)), ft_lstsize(stack));
			best_movs[2] = nr_movs(find_pos(stack, (pos_2)), ft_lstsize(stack));
	//		ft_printf("best_sa[ %i | pos1 -> %i val1 -> %i | pos2 -> %i val2 -> %i ];\n", best_movs[0], best_movs[1],
	//		find_val(stack, best_movs[1]), best_movs[2], find_val(stack, best_movs[2]));
		}
	}
	return (best_movs);
}

int	*best_stack_p_mov(t_stack *src,
		t_stack *dst, int *best_movs)
{
	ft_printf("best_stack_p_mov in\n");
	int	smallest;
	int	movs;
	int	pos_1;
	int	pos_2;
	int	cont;

	cont = 0;
	movs = 0;
	pos_1 = find_biggest(dst);
	pos_2 = find_biggest(dst);
	smallest = find_smallest(src);
	while (pos_1 != smallest)
	{
		pos_1 = find_smaller_then(src, pos_2, smallest);
		ft_printf("pos_1->%i | pos_2->%i;\n", pos_1, pos_2);
			movs = total_movs_p(src, dst, find_pos(src,
				(pos_1)), find_pos(dst, (pos_2)));
		ft_printf("movs->%i\n\n", movs);
		if (movs < best_movs[0] && movs != 0 && pos_1 != smallest)
		{
			best_movs[0] = movs;
			best_movs[1] = nr_movs(find_pos(src, (pos_1)), ft_lstsize(src));
			best_movs[2] = nr_movs(find_pos(dst, (pos_2)), ft_lstsize(dst));
		}
		cont++;
		pos_2 = find_smaller_then(dst, pos_2, find_smallest(dst));
	}
	ft_printf("cont = %i\n", cont);
	return (best_movs);
}
/*
int	*best_stack_p_mov(t_stack *src,
		t_stack *dst, int *best_movs)
{
	ft_printf("best_stack_p_mov in\n");
	int	smallest;
	int	movs;
	int	pos_1;
	int	pos_2;
	int	cont;

	cont = 0;
	movs = 0;
	pos_1 = find_biggest(dst);
	pos_2 = find_biggest(dst);
	smallest = find_smallest(src);
	while (pos_1 != smallest)
	{
		if (pos_2 != find_smallest(dst))
			pos_1 = find_smaller_then(src, pos_2, smallest);
		else
			pos_1 = find_smaller_then(src, pos_1, smallest);
		ft_printf("pos_1->%i | pos_2->%i;\n", pos_1, pos_2);
		if (pos_2 == find_smallest(dst) && dst->next == NULL
			&& pos_1 < find_smaller_then(src, pos_2, smallest))
			movs = total_movs_p(src, dst, find_pos(src,
				(pos_1)), find_pos(dst, (pos_2)));
		ft_printf("movs->%i\n\n", movs);
		if (movs < best_movs[0] && movs != 0 && pos_1 != smallest)
		{
			best_movs[0] = movs;
			best_movs[1] = nr_movs(find_pos(src, (pos_1)), ft_lstsize(src));
			best_movs[2] = nr_movs(find_pos(dst, (pos_2)), ft_lstsize(dst));
		}
		cont++;
		pos_2 = find_smaller_then(dst, pos_2, find_smallest(dst));
	}
	ft_printf("cont = %i\n", cont);
	return (best_movs);
}

	ft_printf("best_pb[ %i | pos1 -> %i val1 -> %i | pos2 -> %i val2 -> %i ];\n", best_movs[0], best_movs[1],
		find_val(src, best_movs[1]), best_movs[2], find_val(dst, best_movs[2]));
*/