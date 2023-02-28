/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb_cont.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 15:23:57 by lwencesl          #+#    #+#             */
/*   Updated: 2023/02/28 17:41:13 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 12:58:43 by lwencesl          #+#    #+#             */
/*   Updated: 2023/02/26 13:31:18 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*p_decisions_cont(int val_1, int val_2, int pos_1, int pos_2)
{
	int	mov;
	int	cont;
	int	final_pos_2;

	cont = 0;
	mov = 0;
	if (val_1 < val_2)
		final_pos_2 = 1;
	else
		final_pos_1 = 0;
	while (mov == 0)
	{
		if ((stack_b == NULL) || ((pos_1 == 0 && pos_2 == final_pos_2)))
		{
			mov = 1;
			cont++;
		}
		else if (pos_1 < 0 && pos_2 < final_pos_2)
		{
			pos_1++;
			pos_2++
		}// rr
		else if (pos_1 > 0 && pos_2 > final_pos_2)
		{
			pos_1--;
			pos_2--;
		}// rrr
		else if (pos_1 < 0)
			pos_1++; // ra
		else if (pos_1 > 0)
			pos_1++; // rra
		else if (pos_2 < final_pos_2)
			pos_2++; // rb
		else if (pos_2 > final_pos_2)
			pos_2--; // rrb
		if (mov == 0)
			cont++;
	}
	return (cont);
}
