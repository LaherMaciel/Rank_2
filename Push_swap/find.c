/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 06:17:38 by lwencesl          #+#    #+#             */
/*   Updated: 2023/03/02 21:23:51 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// find and return the smallest value of the stack
int	find_smallest(t_stack *head)
{
	int	val;

	if (head == NULL)
		return (0);
	val = head->content;
	while (head)
	{
		if (head->content < val)
			val = head->content;
		head = head->next;
	}
	return (val);
}

// find and return the value smaller, closest to 'val'
int	find_smaller_then(t_stack *head, int val, int smallest)
{
	t_stack	*current;
	int		new_smaller;

	if (head == NULL)
		return (0);
	current = head;
	new_smaller = smallest;
	while (current)
	{
		if (current->content > new_smaller
			&& current->content < val)
			new_smaller = current->content;
		current = current->next;
	}
	return (new_smaller);
}

// find and return the value smaller, closest to 'val'
int	find__then(t_stack *head, int val, int biggest)
{
	t_stack	*current;
	int		new_bigger;

	if (head == NULL)
		return (0);
	current = head;
	new_bigger = biggest;
	while (current)
	{
		if (current->content < new_bigger
			&& current->content > val)
			new_bigger = current->content;
		current = current->next;
	}
	return (new_bigger);
}

// find and return the biggest value of the stack
int	find_biggest(t_stack *head)
{
	t_stack	*current;
	int		val;

	if (head == NULL)
		return (0);
	current = head;
	val = current->content;
	while (current)
	{
		if (current->content > val)
			val = current->content;
		current = current->next;
	}
	return (val);
}

// return the position of the 'val'
int	find_pos(t_stack *head, int val)
{
	t_stack	*current;
	int		cont;

	if (head == NULL)
		return (-1);
	cont = 0;
	current = head;
	while (current)
	{
		if (val == current->content)
			return (cont);
		cont++;
		current = current->next;
	}
	return (-1);
}

// return the val in the position 'pos'
int	find_val(t_stack *head, int pos)
{
	t_stack	*current;
	int		cont;

//	ft_printf("pos = %i\n", pos);
	if (head == NULL)
		return (0);
	if (pos < 0)
		pos = pos * (-1);
	else if (pos > 0)
		pos = ft_lstsize(head) - pos;
	cont = 0;
	current = head;
	while (cont < pos)
	{
		cont++;
		current = current->next;
	}
//	ft_printf("val = %i\n\n", current->content);
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
int	find_snd_smallest(int sa, int sb, int pa, int pb)
{
	int	smallest;
	
	if (simple_compar(sa, sb) == 1)
		smallest = 1
}
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
int	simple_compar(int a, int b, int smallest)
{
	if (a == smallest || b == smallest)
		return (0);
	if (a < b)
		return (1);
	return (2);
}
*/