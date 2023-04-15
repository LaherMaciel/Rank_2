/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_decisions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laher_maciel <laher_maciel@student.42.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 16:05:21 by lwencesl          #+#    #+#             */
/*   Updated: 2023/04/15 00:37:18 by laher_maciel     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
char	*p_decisions(t_stack *src, t_stack *dst, int pos_1, int pos_2)
{
	int	final_pos_2;

	if (dst != NULL && ft_lstsize(dst) <= 2)
			final_pos_2 = 1 - ft_lstsize(dst);
	else if (find_val(src, pos_1) < find_val(dst, pos_2))
		final_pos_2 = 1;
	else
		final_pos_2 = 0;
	if (pos_1 == 0 && pos_2 == final_pos_2)
		return ((char *) "pb");
	else if (pos_1 < 0 && pos_2 < final_pos_2)
		return ((char *) "rr");
	else if (pos_1 > 0 && pos_2 > final_pos_2)
		return ((char *) "rrr");
	else if (pos_1 < 0)
		return ((char *) "ra");
	else if (pos_1 > 0)
		return ((char *) "rra");
	else if (pos_2 < final_pos_2)
		return ((char *) "rb");
	else if (pos_2 > final_pos_2)
		return ((char *) "rrb");
	return (NULL);
}
*/

char	*pa_decisions(t_stack *stack_a, t_stack *stack_b, int pos_1, int pos_2)
{
	int	final_pos_2;

	if (stack_a != NULL && ft_lstsize(stack_a) <= 2)
			final_pos_2 = 1 - ft_lstsize(stack_a);
	else if (find_val(stack_b, pos_1) > find_val(stack_a, pos_2))
		final_pos_2 = 1;
	else
		final_pos_2 = 0;
	if (pos_1 == 0 && pos_2 == final_pos_2)
		return ((char *) "pa");
	else if (pos_1 < 0 && pos_2 < final_pos_2)
		return ((char *) "rr");
	else if (pos_1 > 0 && pos_2 > final_pos_2)
		return ((char *) "rrr");
	else if (pos_1 < 0)
		return ((char *) "rb");
	else if (pos_1 > 0)
		return ((char *) "rrb");
	else if (pos_2 < final_pos_2)
		return ((char *) "ra");
	else if (pos_2 > final_pos_2)
		return ((char *) "rra");
	return (NULL);
}

char	*pb_decisions(t_stack *stack_a, t_stack *stack_b, int pos_1, int pos_2)
{
	int	final_pos_2;

	if (stack_b != NULL && ft_lstsize(stack_b) <= 2)
			final_pos_2 = 1 - ft_lstsize(stack_b);
	else if (find_val(stack_a, pos_1) < find_val(stack_b, pos_2))
		final_pos_2 = 1;
	else
		final_pos_2 = 0;
	if (pos_1 == 0 && pos_2 == final_pos_2)
		return ((char *) "pb");
	else if (pos_1 < 0 && pos_2 < final_pos_2)
		return ((char *) "rr");
	else if (pos_1 > 0 && pos_2 > final_pos_2)
		return ((char *) "rrr");
	else if (pos_1 < 0)
		return ((char *) "ra");
	else if (pos_1 > 0)
		return ((char *) "rra");
	else if (pos_2 < final_pos_2)
		return ((char *) "rb");
	else if (pos_2 > final_pos_2)
		return ((char *) "rrb");
	return (NULL);
}

void	p_decisison_cont_aux(int *pos_1, int *pos_2, int final_pos_2)
{
	if (*pos_1 < 0 && *pos_2 < final_pos_2)
	{
		(*pos_1)++;
		(*pos_2)++;
	}
	else if (*pos_1 > 0 && *pos_2 > final_pos_2)
	{
		(*pos_1)--;
		(*pos_2)--;
	}
	else if (*pos_1 < 0)
		(*pos_1)++;
	else if (*pos_1 > 0)
		(*pos_1)--;
	else if (*pos_2 < final_pos_2)
		(*pos_2)++;
	else if (*pos_2 > final_pos_2)
		(*pos_2)--;
}

int	p_decisions_cont(t_stack *src, t_stack *dst, int pos_1, int pos_2)
{
	int	mov;
	int	cont;
	int	final_pos_2;

	cont = -1;
	mov = 0;
	if (ft_lstsize(dst) <= 2)
			final_pos_2 = 1 - ft_lstsize(dst);
	else if (find_val(src, pos_1) < find_val(dst, pos_2))
		final_pos_2 = 1;
	else
		final_pos_2 = 0;
	while (mov == 0)
	{
		if (pos_1 == 0 && pos_2 == final_pos_2)
			mov = 1;
		p_decisison_cont_aux(&pos_1, &pos_2, final_pos_2);
		cont++;
	}
	return (cont);
}

