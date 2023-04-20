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

	if (pos == 0)
		return (pos);
	if (pos < 0)
		pos = stack_size + pos;
	else if (pos >= stack_size)
		pos = pos - stack_size;
	if (pos > (stack_size / 2))
		needed_movs = stack_size - pos;
	else
		needed_movs = (pos) * (-1);
	return (needed_movs);
}

int	total_movs_p(t_stack *src, t_stack *dst, int pos_1, int pos_2)
{
	int	nr_mov;

	nr_mov = p_decisions_cont(src, dst, pos_1, pos_2);
	return (nr_mov);
}
