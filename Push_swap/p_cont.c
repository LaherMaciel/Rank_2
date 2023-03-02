/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_cont.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 15:23:57 by lwencesl          #+#    #+#             */
/*   Updated: 2023/03/02 21:56:31 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	p_decisions_cont(int val_1, int val_2, int pos_1, int pos_2)
{
	ft_printf("p_decisions_cont in\n");
	//ft_printf("val_1 -> %i, val_2 -> %i, pos_1 -> %i, pos_2 -> %i\n", val_1, val_2, pos_1, pos_2);
	int	mov;
	int	cont;
	int	final_pos_2;

	cont = 0;
	mov = 0;
	if (val_1 < val_2)
		final_pos_2 = 1;
	else
		final_pos_2 = 0;
	while (mov == 0)
	{
		if (pos_1 == 0 && pos_2 == final_pos_2)
			mov = 1;
		p_decisison_cont_aux(&pos_1, &pos_2, final_pos_2);
		cont++;
		//ft_printf("pos_1->%i | pos_2->%i\ncont->%i", pos_1, pos_2, cont);
	}
	//ft_printf("val_1 -> %i, val_2 -> %i, pos_1 -> %i, pos_2 -> %i\n", val_1, val_2, pos_1, pos_2);
	ft_printf("p_decisions_cont out\n");
	return (cont);
}

int	media(t_stack *stack)
{
	t_stack	*current;
	int		val;
	int		cont;

	if (stack == NULL)
		return (0);
	current = stack;
	val = 0;
	cont = 0;
	while (stack)
	{
		val += current->content;
		current = current->next;
		cont++;
	}
	return (val/cont);
}
