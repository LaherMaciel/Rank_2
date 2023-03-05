/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 19:45:42 by lwencesl          #+#    #+#             */
/*   Updated: 2023/03/03 23:09:50 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char *pb_decisions(t_stack *src, t_stack *dst, int pos_1, int pos_2)
{
	int	final_pos_2;

	if (dst != NULL && ft_lstsize(dst) <= 2)
			final_pos_2 = 1 - ft_lstsize(dst);
	else if (find_val(src, pos_1) < find_val(dst, pos_2))
		final_pos_2 = 1;
	else
		final_pos_2 = 0;
	//ft_printf("in pb_decisions pos_1 -> %i | pos_2 -> %i | final_pos_2 -> %i\n", pos_1, pos_2, final_pos_2);
	//ft_printf("media -> %i\n", find_media(src));
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
