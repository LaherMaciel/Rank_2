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

	half = ft_lstsize(src) / 2;
	if (half == 0)
		half = 1;
	if (*cont <= half)
		*pos_1 = *cont * (-1);
	else
		*pos_1 = ft_lstsize(src) - *cont;
	*cont = *cont + 1;
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
		if (movs < best_movs[0])
		{
			best_movs[0] = movs;
			best_movs[1] = pos_1;
			best_movs[2] = pos_2;
		}
	}
	return (best_movs);
}
