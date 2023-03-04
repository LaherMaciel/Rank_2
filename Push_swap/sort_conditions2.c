/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_conditions2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 21:55:56 by lwencesl          #+#    #+#             */
/*   Updated: 2023/03/04 01:10:04 by lwencesl         ###   ########.fr       */
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
		if ((nr_movs(find_pos(stack, find_bigger_then(stack, pos_1,
			find_biggest(stack))) - 1, ft_lstsize(stack))
				== nr_movs(find_pos(stack, pos_1), ft_lstsize(stack)))
				|| (nr_movs(find_pos(stack, find_bigger_then(stack, pos_1,
			find_biggest(stack))) - 1, ft_lstsize(stack))
				== nr_movs(find_pos(stack, pos_1), ft_lstsize(stack))))
			movs = total_movs_s(stack, find_pos(stack, pos_2),
				find_pos(stack, pos_1));
		else
		movs = total_movs_s(stack, find_pos(stack, pos_1),
				find_pos(stack, pos_2));
		if (movs < best_movs[0] && movs != 0)
		{
			//ft_printf("pos_1 -> %i	| pos_2 -> %i\n", nr_movs(find_pos(stack,
			//	find_bigger_then(stack, pos_1, find_biggest(stack))) - 1, ft_lstsize(stack)), nr_movs(find_pos(stack, pos_1), ft_lstsize(stack)));
			best_movs[0] = movs;
			best_movs[1] = nr_movs(find_pos(stack, (pos_1)), ft_lstsize(stack));
			best_movs[2] = nr_movs(find_pos(stack, (pos_2)), ft_lstsize(stack));
			//ft_printf("best_sa[ %i | pos1 -> %i val1 -> %i | pos2 -> %i val2 -> %i ];\n", best_movs[0], best_movs[1],
			//find_val(stack, best_movs[1]), best_movs[2], find_val(stack, best_movs[2]));
		}
	}
	return (best_movs);
}

int	*best_stack_p_mov(t_stack *src,
		t_stack *dst, int *best_movs)
{
	int	smallest;
	int	movs;
	int	pos_1;
	int	pos_2;
	int	cont;

	cont = 0;
	movs = 0;
	pos_1 = 0;
	pos_2 = 0;
	smallest = find_smallest(src);
	while (pos_1 != 1)
	{
		if (cont < (ft_lstsize(src) / 2))
			pos_1 = cont * (-1);
		else
			pos_1 = ft_lstsize(src) - cont;
		if (find_val(src, pos_1) >= find_media(src))
		{
			//ft_printf("find_val(src, pos_1) -> %i >= find_media(src) -> %i\n", find_val(src, pos_1), find_media(src));
			if (dst == NULL)
			{
				movs = pos_1;
				if (movs < 0)
					movs = movs * (-1); 
			}
			else
			{
				if (find_val(src, pos_1) > find_biggest(dst))
					pos_2 = nr_movs(find_pos(dst, find_biggest(dst)), ft_lstsize(dst));
				else
					pos_2 = nr_movs(find_pos(dst, find_bigger_then(dst, find_val(src, pos_1), find_biggest(dst))), ft_lstsize(dst));
				//ft_printf("%i is bigger then -> %i\n", find_bigger_then(dst, find_val(src, pos_1), find_biggest(dst)), find_val(src, pos_1));
				movs = total_movs_p(src, dst, pos_1, pos_2);
			}
			if (movs < best_movs[0] && (movs != 0 || (movs == 0 && dst == NULL)) && pos_1 != smallest)
			{
				best_movs[0] = movs;
				best_movs[1] = pos_1;
				best_movs[2] = pos_2;
				//ft_printf("best_pb[ %i | pos1 -> %i val1 -> %i | pos2 -> %i val2 -> %i ];\n", best_movs[0], best_movs[1],
				//find_val(src, best_movs[1]), best_movs[2], find_val(dst, best_movs[2]));
			}
		}
		cont++;
	}
	return (best_movs);
}
/*
ft_printf("bigger then (pos_1 - 1) -> %i	|	the pos_1 -> %i\n", nr_movs(find_pos(stack, find_bigger_then(stack, pos_1,
				find_biggest(stack) + 1)), nr_movs(find_pos(stack, pos_1), ft_lstsize(stack))));

if ((pos_1 < 0 && find_val(stack, find_pos(stack, pos_1)) == find_smaller_then(stack,
				find_pos(stack, pos_1 + 1), smallest)) || (pos_1 > 0 && find_val(stack,
					find_pos(stack, pos_1)) == find_smaller_then(stack,
						find_pos(stack, pos_1 - 1), smallest)))

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
	smallest = find_smallest(src);
	while (pos_1 > 0)
	{
		if (cont < (ft_lstsize(src) / 2))
			pos_1 = cont * (-1);
		else
			pos_1 = ft_lstsize(src) - cont;
		pos_2 = nr_movs(find_pos(dst, find__then(dst, pos_1, find_biggest(dst))), ft_lstsize(dst));
		movs = total_movs_p(src, dst, pos_1, pos_2);
		if (movs < best_movs[0] && movs != 0 && pos_1 != smallest && find_val(src, pos_1) >= find_media(src))
		{
			best_movs[0] = movs;
			best_movs[1] = pos_1;
			best_movs[2] = pos_2;
			ft_printf("best_sa[ %i | pos1 -> %i val1 -> %i | pos2 -> %i val2 -> %i ];\n", best_movs[0], best_movs[1],
			find_val(src, best_movs[1]), best_movs[2], find_val(dst, best_movs[2]));
		}
		cont++;
		src = src->next;
	}
	ft_printf("cont = %i\n", cont);
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
	while (pos_1 != find_smaller_then(src, find_smallest(dst), smallest))
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