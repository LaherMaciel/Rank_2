/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa_cont.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 12:58:31 by lwencesl          #+#    #+#             */
/*   Updated: 2023/02/28 18:26:21 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	aux_1(int *pos_1, int *pos_2, int *cont, t_stack stack)
{
	if (pos_2 > 0 && pos_1 == 0 && pos_2 != ft_lstsize(stack))
	{
		pos_1--;
		pos_2--;	
	} // rra or rrb
	else if (pos_2 < 0 && pos_1 == 0 && pos_2 != -1)
		pos_1--;// sa or sb
	else if (pos_2 > 0 && pos_1 == -1)
		pos_1++;// sa or sb
	else if (pos_2 == 1 && pos_1 == 0 && (find_val(stack, pos_1) < find_val(stack, pos_2)))
	{
		pos_2--;
		cont++;	
	}// rra + sa or rrb + sb
}

void	aux_2(int *pos_1, int *pos_2, t_stack stack)
{
	else if ((pos_1 == 0 || pos_1 == -1)
			&& (pos_2 == 0 || pos_2 == -1))
	{
		if (((pos_1 < pos_2) && (find_val(stack, pos_1) < find_val(stack, pos_2)))
		{
			pos_1++;
			pos_2--;
		}// sa or sb
		else if (((pos_1 > pos_2) && (find_val(stack, pos_1) > find_val(stack, pos_2)))
		{
			pos_1--;
			pos_2++;
		}// sa or sb
	}
	else if (pos_1 < 0)
	{
		pos_1++;
		pos_2++;
	}// ra or rb
	else if (pos_1 > 0)
	{
		pos_1--;
		pos_2--;
	}// rra  or rrb
}

char	s_decisions_cont(t_stack *stack, int pos_1, int pos_2)
{
	int	out;
	int	cont;

	cont = 0;
	out = 0;
	while (out == 0)
	{
		aux_1(&pos_1, &pos_2, &cont, stack);
		aux_2(&pos_1, &pos_2, stack);
		if (((pos_1 - 1) == pos_2)
			&& (find_val(stack, pos_1) < find_val(stack, pos_2)))
			out == 1;
		else if (((pos_1 + 1) == pos_2)
			&& (find_val(stack, pos_1) > find_val(stack, pos_2)))
			out == 1;
		else
			cont++;
	}
	return (cont);
}
