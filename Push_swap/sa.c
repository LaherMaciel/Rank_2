/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 12:58:31 by lwencesl          #+#    #+#             */
/*   Updated: 2023/02/25 17:15:50 by lwencesl         ###   ########.fr       */
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

char	*sa_decisions(t_stack *stack, int pos_1, int pos_2, int id)
{
	if (pos_2 > 0 && pos_1 == 0 && pos_2 != ft_lstsize(stack))
		return ("rra");
	else if (pos_2 < 0 && pos_1 == 0 && pos_2 != -1)
		return ("sa");
	else if (pos_2 > 0 && pos_1 == -1)
		return ("sa");
	else if ((pos_1 == 0 && pos_2 == -1) && (find_val(stack, pos_1) > find_val(stack, pos_2)))
		return ("sa");
	else if ((pos_1 == 0 && pos_2 == 1) && (find_val(stack, pos_1) < find_val(stack, pos_2)))
		return ("rra+sa");
	else if (pos_1 < 0)
		return ("ra");
	else if (pos_1 > 0)
		return ("rra");
	return (NULL);
}
