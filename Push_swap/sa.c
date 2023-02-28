/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 12:58:31 by lwencesl          #+#    #+#             */
/*   Updated: 2023/02/28 17:55:18 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*s_decisions_cont(t_stack *stack, int pos_1, int pos_2, int id)
{
	if (pos_2 > 0 && pos_1 == 0 && pos_2 != ft_lstsize(stack))
		return (ft_strjoin("rr", id));// rra or rrb
	else if (pos_2 < 0 && pos_1 == 0 && pos_2 != -1)
		return (ft_strjoin("s", id));// sa or sb
	else if (pos_2 > 0 && pos_1 == -1)
		return (ft_strjoin("s", id));// sa or sb
	else if (pos_2 == 1 && pos_1 == 0 && (find_val(stack, pos_1)
		< find_val(stack, pos_2)))
		return (ft_strjoin(ft_strjoin("rr", id),
			ft_strjoin("s", id)));// rra + sa or rrb + sb
	else if ((pos_1 == 0 || pos_1 == -1)
			&& (pos_2 == 0 || pos_2 == -1))
	{
		if (((pos_1 < pos_2) && (find_val(stack, pos_1) < find_val(stack, pos_2)))
			return (ft_strjoin("s", id));// sa or sb
		else if (((pos_1 > pos_2) && (find_val(stack, pos_1) > find_val(stack, pos_2)))
			return (ft_strjoin("s", id));// sa or sb
	}
	else if (pos_1 < 0)
		return (ft_strjoin("r", id));// ra or rb
	else if (pos_1 > 0)
		return (ft_strjoin("rr", id));// rra  or rrb
	return (NULL);
}

/*
	char	*aux_1(int *pos_1, int *pos_2, int *cont, t_stack stack)
{
	if (pos_2 > 0 && pos_1 == 0 && pos_2 != ft_lstsize(stack))
		return (ft_strjoin("rr", id));// rra or rrb
	else if (pos_2 < 0 && pos_1 == 0 && pos_2 != -1)
		return (ft_strjoin("s", id));// sa or sb
	else if (pos_2 > 0 && pos_1 == -1)
		return (ft_strjoin("s", id));// sa or sb
	else if (pos_2 == 1 && pos_1 == 0 && (find_val(stack, pos_1)
		< find_val(stack, pos_2)))
		return (ft_strjoin(ft_strjoin("rr", id),
			ft_strjoin("s", id)));// rra + sa or rrb + sb
	return (NULL);
}

char	*aux_2(int *pos_1, int *pos_2, t_stack stack)
{
	if ((pos_1 == 0 || pos_1 == -1)
			&& (pos_2 == 0 || pos_2 == -1))
	{
		if (((pos_1 < pos_2) && (find_val(stack, pos_1) < find_val(stack, pos_2)))
			return (ft_strjoin("s", id));// sa or sb
		else if (((pos_1 > pos_2) && (find_val(stack, pos_1) > find_val(stack, pos_2)))
			return (ft_strjoin("s", id));// sa or sb
	}
	else if (pos_1 < 0)
		return (ft_strjoin("r", id));// ra or rb
	else if (pos_1 > 0)
		return (ft_strjoin("rr", id));// rra  or rrb
	return (NULL);
}

	return (aux_1(&pos_1, &pos_2, &cont, stack));
	return (aux_2(&pos_1, &pos_2, stack));
*/
