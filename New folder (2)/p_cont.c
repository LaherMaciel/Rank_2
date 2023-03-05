/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_cont.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 15:23:57 by lwencesl          #+#    #+#             */
/*   Updated: 2023/03/03 23:09:35 by lwencesl         ###   ########.fr       */
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

int	p_decisions_cont(t_stack *src, t_stack *dst, int pos_1, int pos_2)
{
	//ft_printf("val_1 -> %i, val_2 -> %i, pos_1 -> %i, pos_2 -> %i\n", val_1, val_2, pos_1, pos_2);
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
	//ft_printf("in p_decisions_cont while pos_1 -> %i | pos_2 -> %i | final_pos_2 -> %i\n", pos_1, pos_2, final_pos_2);
	while (mov == 0)
	{
		//ft_printf("in p_decisions_cont while pos_1->%i | pos_2->%i | final_pos_2 -> %i\n", pos_1, pos_2, final_pos_2);
		if (pos_1 == 0 && pos_2 == final_pos_2)
			mov = 1;
		p_decisison_cont_aux(&pos_1, &pos_2, final_pos_2);
		cont++;
	}
	//ft_printf("print_out  pos_1->%i | pos_2->%i\ncont->%i\n", pos_1, pos_2, cont);
	//ft_printf("val_1 -> %i, val_2 -> %i, pos_1 -> %i, pos_2 -> %i\n", val_1, val_2, pos_1, pos_2);
	return (cont);
}

int	find_media(t_stack *stack)
{
	t_stack	*current;
	int		val;
	int		cont;

	if (stack == NULL)
		return (0);
	current = stack;
	val = 0;
	cont = 0;
	while (current)
	{
		val += current->content;
		current = current->next;
		cont++;
	}
	return (val/cont);
}
