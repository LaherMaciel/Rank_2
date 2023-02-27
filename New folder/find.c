/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 06:17:38 by lwencesl          #+#    #+#             */
/*   Updated: 2023/02/24 17:49:40 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	all_positive(int *sa, int *sb, int *pa, int *pb)
{
	if (sa < 0)
		*sa = *sa * (-1);
	if (*sb < 0)
		*sb = *sb * (-1);
	if (pa < 0)
		*pa = *pa * (-1);
	if (pb < 0)
		*pb = *pb * (-1);
}

int	find_snd_smallest(int sa, int sb, int pa, int pb)
{
	int	smallest;
	
	if (simple_compar(sa, sb) == 1)
		smallest = 1
}

int	simple_compar(int a, int b, int smallest)
{
	if (a == smallest || b == smallest)
		return (0);
	if (a < b)
		return (1);
	return (2);
}

int	find_smallest_intsack(t_stack *stack)
{
	int	val;

	val = stack->content;
	while (!stack->next)
	{
		if (val < stack->content)
			val = stack->content;
		stack = stack->next;
	}
	return (val);
}

int	find_smaller_then(t_stack *head, int val)
{
	t_stack	*current;
	int		next_smallest;

	current = head;
	next_smallest = current->content;
	while (!current->next)
	{
		if (current->content < next_smallest
			&& current->content > val)
			next_smallest = current->content;
		current = current->next;
	}
	return (next_smallest);
}

int	find_biggest(t_stack *head)
{
	t_stack	*current;
	int		val;

	current = head;
	val = current->content;
	while (!current)
	{
		if (current->content > val)
			val = current->content;
		current = current->next;
	}
	return (val);
}

int	find_pos(t_stack *head, int val)
{
	t_stack	*current;
	int		cont;

	cont = 0;
	current = head;
	while (!current->next)
	{
		if (val == current->content)
			break ;
		cont++;
	}
	return (cont);
}

int	find_val(t_stack *head, int pos)
{
	t_stack	*current;
	int		cont;

	cont = 0;
	current = head;
	while (cont < pos)
		current = current->next;
	return (current->content);
}

/*
int	find_smallest_mov(int sa, int sb, int pa, int pb)
{
	int	pos;
	int	smallest;

	pos = 1;
	smallest = sa;
	if (sb < smallest)
	{
		smallest = sb;
		pos = 2;
	}
	if (pa < smallest)
	{
		smallest = pa;
		pos = 3;
	}
	if (pb < smallest)
	{
		smallest = pb;
		pos = 4;
	}
	return (pos);
}
*/
