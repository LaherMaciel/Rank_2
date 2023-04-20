/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_conditions2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 21:55:56 by lwencesl          #+#    #+#             */
/*   Updated: 2023/03/06 09:53:56 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_pos_1(t_stack *src, int *pos_1, int *cont)
{
	int	half;
	int	src_size;

	src_size = ft_lstsize(src);
	half = src_size / 2;
	if (half == 0)
		half = 1;
	if (*cont <= half)
		*pos_1 = *cont * (-1);
	else
		*pos_1 = ft_lstsize(src) - *cont;
	*cont = *cont + 1;
}

/*
void	find_pos_1(t_stack *src, int *pos_1, int *cont)
{
	int	half;
	int	src_size;

	src_size = ft_lstsize(src);
	half = src_size / 2;
	if (*cont < half && *pos_1 == -1)
		*pos_1 = *pos_1;
	else if (*cont < half && *pos_1 != -1)
		*pos_1 = *cont * (-1);
	else
		*pos_1 = ft_lstsize(src) - *cont;
	*cont = *cont + 1;
}

if (ft_lstsize(src) == 1 && *cont == 0)
		*cont = *cont + 1;
	else 
*/

int	best_stack_pb_mov_aux(t_stack *src, t_stack *dst, int *pos_1, int *pos_2)
{
	int	movs;

	if (dst == NULL)
	{
		movs = *pos_1;
		if (movs < 0)
			movs = movs * (-1);
	}
	else
	{
		if (find_val(src, *pos_1) > find_biggest(dst))
			*pos_2 = 0;
		else
			*pos_2 = 0;
		movs = total_movs_p(src, dst, *pos_1, *pos_2);
	}
	return (movs);
}

int	*best_stack_pb_mov(t_stack *src,
		t_stack *dst, int *best_movs)
{
	int	movs;
	int	pos_1;
	int	pos_2;
	int	cont;

	cont = 0;
	pos_1 = 1;
	pos_2 = 0;
	while (pos_1 != 0)
	{
		find_pos_1(src, &pos_1, &cont);
		movs = best_stack_pa_mov_aux(src, dst, &pos_1, &pos_2);
		if (find_val(src, pos_1) <= find_media(src))
		{
			if (movs < best_movs[0] && (movs != 0
					|| (movs == 0 && dst == NULL)))
			{
				best_movs[0] = movs;
				best_movs[1] = pos_1;
				best_movs[2] = pos_2;
			}
		}
	}
	return (best_movs);
}

int	best_stack_pa_mov_aux(t_stack *src, t_stack *dst, int *pos_1b, int *pos_2a)
{
	int	movs;

	if (dst == NULL)
	{
		movs = *pos_1b;
		if (movs < 0)
			movs = movs * (-1);
	}
	else
	{
		if (find_val(src, *pos_1b) > find_biggest(dst))
			*pos_2a = nr_movs(find_pos(dst, find_biggest(dst)),
					ft_lstsize(dst));
		else
			*pos_2a = nr_movs(find_pos(dst, find_bigger_then(dst,
							find_val(src, *pos_1b), find_biggest(dst))),
					ft_lstsize(dst));
		movs = total_movs_p(src, dst, *pos_1b, *pos_2a);
	}
	return (movs);
}

/*void	pa_end(t_stack **stack_a, t_stack **stack_b)
{
	int	smaller_pos;
	int	bigger_pos;

	smaller_pos = 0;
	bigger_pos = 0;
	if (find_smaller_then(*stack_a, (*stack_b)->content, INT_MAX) != (*stack_b)->content)
		smaller_pos = find_smaller_then(*stack_b, (*stack_b)->content, INT_MAX);
	else if (find_bigger_then(*stack_a, (*stack_b)->content, INT_MAX) != (*stack_b)->content)
		bigger_pos = find_bigger_then(*stack_b, (*stack_b)->content, INT_MAX);
	if (smaller_pos == 0 && bigger_pos != 0)
		return (find_pos(*stack_a, bigger_pos));
	else (smaller_pos != 0 && bigger_pos == 0)
		return (find_pos(*stack_a, smaller_pos));
	if (bigger_pos)
	{
		return (0);
	}
}*/

/*int	*best_stack_pa_mov(t_stack *stack_b,
		t_stack *stack_a, int *best_movs)
{
	int	movs;
	int	pos_1b;
	int	pos_2a;
	int	cont;

	cont = 1;
	pos_1b = INT_MAX;
	pos_2a = 0;
	while (pos_1b != 0)
	{
		find_pos_1(stack_b, &pos_1b, &cont);
		movs = best_stack_pa_mov_aux(stack_b, stack_a, &pos_1b, &pos_2a);
		if (find_val(stack_b, pos_1b) <= find_media(stack_b))
		{
			if (movs < best_movs[0] && (movs != 0
					|| (movs == 0 && stack_a == NULL)))
			{
				best_movs[0] = movs;
				best_movs[1] = pos_1b;
				best_movs[2] = pos_2a;
			}
		}
	}
	return (best_movs);
}*/

int	*best_stack_pa_mov(t_stack *src,
		t_stack *dst, int *best_movs)
{
	int	movs;
	int	pos_1;
	int	pos_2;
	int	cont;

	cont = 0;
	pos_1 = -1;
	pos_2 = 0;
	while (cont < ft_lstsize(src))
	{
		find_pos_1(src, &pos_1, &cont);
		movs = best_stack_pa_mov_aux(src, dst, &pos_1, &pos_2);
		if (find_val(src, pos_1) <= find_media(src))
		{
			if (movs < best_movs[0] && (movs != 0
					|| (movs == 0 && dst == NULL)))
			{
				best_movs[0] = movs;
				best_movs[1] = pos_1;
				best_movs[2] = pos_2;
			}
		}
	}
	return (best_movs);
}
