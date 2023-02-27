/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 12:58:43 by lwencesl          #+#    #+#             */
/*   Updated: 2023/02/25 13:56:12 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*pb_decisions(t_stack *stack_a, t_stack *stack_b, int pos_1, int pos_2)
{
	if ((pos_1 == 0 && pos_2 == 0) || (stack_b == NULL))
		return ("pb");
	else if (pos_1 <= pos_2 && (pos_1 != 0 || pos_1 != ft_lstsize(stack_a)))
	{
		if ()
	}
	else if (pos_1 < 0 && pos_2 < 0)
		return ("rr");
	else if (pos_1 > 0 && pos_2 > 0)
		return ("rrr");
	else if (pos_1 < 0)
		return ("ra");
	else if (pos_1 > 0)
		return ("rra");
	if (pos_2 < 0)
		return ("rb");
	else if (pos_2 > 0)
		return ("rrb");
	else if (pos_1 == 0 && pos_2 == 0)
		return ("pb");
	return (NULL);
}

