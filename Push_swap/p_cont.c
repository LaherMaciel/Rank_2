/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_cont.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 15:23:57 by lwencesl          #+#    #+#             */
/*   Updated: 2023/03/02 04:36:14 by lwencesl         ###   ########.fr       */
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
		ft_printf("pos_1->%i | pos_2->%i\ncont->%i", pos_1, pos_2, cont);
	}
	ft_printf("p_decisions_cont out\n");
	return (cont);
}
