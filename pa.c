/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 16:05:21 by lwencesl          #+#    #+#             */
/*   Updated: 2023/04/06 10:53:16 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*pa_decisions(t_stack *src, t_stack *dst, int pos_1, int pos_2)
{
	int	final_pos_2;

	if (dst != NULL && ft_lstsize(dst) <= 2)
			final_pos_2 = 1 - ft_lstsize(dst);
	else if (find_val(src, pos_1) > find_val(dst, pos_2))
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

void	pb_decisison_cont_aux(int *pos_1, int *pos_2, int final_pos_2)
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

int	pb_decisions_cont(t_stack *src, t_stack *dst, int pos_1, int pos_2)
{
	int	mov;
	int	cont;
	int	final_pos_2;

	cont = 0;
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
		pb_decisison_cont_aux(&pos_1, &pos_2, final_pos_2);
		cont++;
	}
	return (cont);
}
