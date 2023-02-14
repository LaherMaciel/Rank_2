/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 06:17:38 by lwencesl          #+#    #+#             */
/*   Updated: 2023/02/12 12:03:40 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*find_smallest(t_stack *stack)
{
	int	*val;

	val = (int *) stack->content;
	while (!stack->next)
	{
		if (val < (int *) stack->content)
			val = (int *) stack->content;
		stack = stack->next;
	}
	return (val);
}

int	*find_smaller_then(t_stack *stack, int val)
{
	int	*next_smallest;

	next_smallest = (int *) stack->content;
	while (!stack->next)
	{
		if (next_smallest > (int *) stack->content
			&& val < (int *) stack->content)
			next_smallest = (int *) stack->content;
		stack = stack->next;
	}
	return (next_smallest);
}

int	*find_biggest(t_stack *stack)
{
	int	*val;

	val = (int) stack->content;
	while (!stack->next)
	{
		if (val > (int *) stack->content)
			val = (int *) stack->content;
		stack = stack->next;
	}
	return (val);
}

int	find_val(t_stack stack, int val)
{
	int	cont;

	cont = 0;
	while (!stack->next)
	{
		if (val == stack->content)
			break ;
		cont++;
	}
	return (cont);
}
