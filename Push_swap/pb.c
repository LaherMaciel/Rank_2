/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 19:45:42 by lwencesl          #+#    #+#             */
/*   Updated: 2023/02/28 22:33:05 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*pb_decisions(int val_1, int val_2, int pos_1, int pos_2)
{
	int	final_pos_2;

	if (val_1 < val_2)
		final_pos_2 = 1;
	else
		final_pos_2 = 0;
	if (pos_1 == 0 && pos_2 == final_pos_2)
		return ("pb");
	else if (pos_1 < 0 && pos_2 < final_pos_2)
		return ("rr");
	else if (pos_1 > 0 && pos_2 > final_pos_2)
		return ("rrr");
	else if (pos_1 < 0)
		return ("ra");
	else if (pos_1 > 0)
		return ("rra");
	else if (pos_2 < final_pos_2)
		return ("rb");
	else if (pos_2 > final_pos_2)
		return ("rrb");
	return (NULL);
}

/*
char	*pb_decisions(t_stack *stack_a, t_stack *stack_b, int pos_1, int pos_2)
{
	if ((pos_1 == 0 && pos_2 == 0) || (stack_b == NULL))
		return ("pb");
	else if (pos_1 <= pos_2 && (pos_1 != 0 || pos_1 != ft_lstsize(stack_a)))
	{
		if ()
	}
	else if (pos_1 < 0 && pos_2 < 0)
		return ("rr"); // (pos_1 & pos_2) + 1
	else if (pos_1 > 0 && pos_2 > 0)
		return ("rrr"); // (pos_1 & pos_2) - 1
	else if (pos_1 < 0)
		return ("ra"); // (pos_1) + 1
	else if (pos_1 > 0)
		return ("rra"); // (pos_1) - 1
	if (pos_2 < 0)
		return ("rb"); // (pos_2) + 1
	else if (pos_2 > 0)
		return ("rrb"); // (pos_2) - 1
	else if (pos_1 == 0 && pos_2 == 0)
		return ("pb"); // (pos_1) -> stack_b -> 0
	return (NULL);
}

*/
