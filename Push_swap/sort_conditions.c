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
		needed_movs = stack_size - pos;
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

int	total_movs_s(t_stack *stack, int pos_1, int pos_2)
{
	//ft_printf("total_movs_s in\n");
	int	nr_mov;

	pos_1 = nr_movs(pos_1, ft_lstsize(stack));
	pos_2 = nr_movs(pos_2, ft_lstsize(stack));
	if (pos_1 == total_movs(pos_1, pos_2))
		nr_mov = s_decisions_cont(stack, pos_1, pos_2);
	else
		nr_mov = s_decisions_cont(stack, pos_2, pos_1);
	//ft_printf("total_movs_s out\n\n");
	return (nr_mov);
}

int	total_movs_p(t_stack *src, t_stack *dst, int pos_1, int pos_2)
{
	ft_printf("\ntotal_movs_P in\n");
	int	nr_mov;

	pos_1 = nr_movs(pos_1, ft_lstsize(src));
	pos_2 = nr_movs(pos_2, ft_lstsize(dst));
	if ((dst)->next == NULL)
		nr_mov = p_decisions_cont(find_val(src, pos_1),
			INT_MIN, pos_1, 0);
	else
		nr_mov = p_decisions_cont(find_val(src, pos_1),
			find_val(dst, pos_2), pos_1, pos_2);
	ft_printf("nr_movs->%i\n", nr_mov);
	ft_printf("\ntotal_movs_P out\n");
	return (nr_mov);
}
