/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa_cont.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 12:58:31 by lwencesl          #+#    #+#             */
/*   Updated: 2023/03/02 00:46:05 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	aux_3(int *pos_1, int *pos_2)
{
	if (*pos_1 < 0)
	{
		(*pos_1)++;
		(*pos_2)++;
	}
	else if (*pos_1 > 0)
	{
		(*pos_1)--;
		(*pos_2)--;
	}
}

void	aux_2(int *pos_1, int *pos_2, int out)
{
	if ((*pos_1 == 0 || *pos_1 == -1)
		&& (*pos_2 == 0 || *pos_2 == -1))
	{
		if ((*pos_1 < *pos_2) && out == 1)
		{
			(*pos_1)++;
			(*pos_2)--;
		}
		else if ((*pos_1 > *pos_2) && out == 2)
		{
			(*pos_1)--;
			(*pos_2)++;
		}
	}
	else
		aux_3(pos_1, pos_2);
}

void	aux_1(int *pos_1, int *pos_2, int *cont, int out)
{
	if (*pos_2 > 0 && *pos_1 == 0 && *pos_2 != 1)
	{
		(*pos_1)--;
		(*pos_2)--;
	}
	else if (*pos_2 < 0 && *pos_1 == 0 && *pos_2 != -1)
		(*pos_1)--;
	else if (*pos_2 > 0 && *pos_1 == -1)
		(*pos_1)++;
	else if (*pos_2 == 1 && *pos_1 == 0 && out == 1)
	{
		(*pos_1)++;
		(*pos_2)--;
		(*cont)++;
	}
	else
		aux_2(pos_1, pos_2, out);
}

int	s_decisions_cont(t_stack *stack, int pos_1, int pos_2)
{
	int	out;
	int	cont;
	int	turn;

	cont = 0;
	out = 0;
	turn = 0;
	if (find_val(stack, pos_1) < find_val(stack, pos_2))
		out = 1;
	else
		out = 2;
	while (out != 3)
	{
		aux_1(&pos_1, &pos_2, &cont, out);
		if (pos_2 > (ft_lstsize(stack) / 2) && turn == 0)
		{
			pos_2 = - (ft_lstsize(stack) / 2);
			turn++;
		}
		else if (pos_2 * (-1) > (ft_lstsize(stack) / 2) && turn == 0)
		{
			pos_2 = (ft_lstsize(stack) / 2) - 1;
			turn++;
		}
		cont++;
		if (((pos_1 - 1) == pos_2) && out == 1)
			out = 3;
		else if (((pos_1 + 1) == pos_2) && out == 2)
			out = 3;
	}
	return (cont);
}
