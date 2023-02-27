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

void	sada(t_stack *stack_a, t_stack *stack_b, int *movs[][])
{
	int	pos_1;
	int	pos_2;

	if (total_movs_adv(movs[3][1], movs[3][2], ft_lstsize(stack_a), ft_lstsize(stack_a)) == movs[3][1])
	{
		pos_1 = movs[3][1];
		pos_2 = movs[3][2];
	}
	else
	{
		pos_1 = movs[3][2];
		pos_2 = movs[3][1];
	}
	if (movs[3][0] == movs[0][0])
	{
		s_decisions(stack_a, pos_1, pos_2);
	}
	else if (movs[3][0] == movs[1][0])
	{
		s_decisions(stack_b, pos_1, pos_2);
	}
	else if (movs[3][0] == movs[2][0])
	{
		pb_decisions(stack_a, stack_b, pos_1, pos_2);
	}
}

void	best_movs(int *movs[][])
{
	int	i;
	int	mov_tp;

	i = -1;
	while (++i < 3)
	{
		if (movs[i][0] < 0)
		{
			if ((movs[i][0] * (-1)) < movs[3][0])
				mov_tp = i;
		}
		else if (movs[i][0] < movs[3][0])
			mov_tp = i;
	}
	i = -1;
	while (++i < 3)
		movs[3][i] = movs[mov_tp][i];
	i = -1;
	while (++i < 3)
	{
		if ((movs[3][0]) * (movs[i][0]) > 0 && movs[i][0] != movs[3][0])
		{
			if (movs[i][0] < 0)
			{
				if (movs[i][0] < movs[4][0])
					mov_tp = i;
			}
			else if (movs[i][0] < movs[4][0])
				mov_tp = i;
		}
	}
}

void	sei_la(t_stack **stack_a, t_stack **stack_b)
{
	int	i;
	int	j;
	int	movs[5][3];

	i = -1;
	j = -1;
	while (++i < 5)
		while (++j < 3)
			movs[i][j] = INT_MAX;
	best_stack_ord_mov(*stack_a, &movs[0]);
	best_stack_ord_mov(*stack_b, &movs[0]);
	best_stack_p1p2_mov(*stack_a, *stack_b, &movs[0]);
	best_movs(&movs);
	best_movs(&movs);
}

/*
if ((best_sa * best_sb) < 0)
		return (0);
	if ((best_sa * best_pb) < 0)
		return (0);
	if ((best_sb * best_pa_mov) < 0)
		return (0);
	if ((best_pa * best_pb) < 0)
		return (0);
*/
