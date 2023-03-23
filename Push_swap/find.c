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

// find and return the value bigger, closest to 'val'
int	find_bigger_then(t_stack *head, int val, int biggest)
{
	t_stack	*current;
	int		new_bigger;

	if (head == NULL)
		return (0);
	current = head;
	new_bigger = biggest;
	while (current)
	{
		if (current->content > val && current->content < new_bigger)
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
	return (current->content);
}

int	find_media(t_stack *stack)
{
	t_stack	*current;
	int		val;
	int		cont;

	if (stack == NULL)
		return (0);
	current = stack;
	val = 0;
	cont = 0;
	while (current)
	{
		val += current->content;
		current = current->next;
		cont++;
	}
	return ((val / cont) + (val / (cont * 2)));
}

int	find_above_media(t_stack *stack)
{
	t_stack	*current;
	int		media;
	int		cont1;
	int		cont2;

	cont1 = 0;
	cont2 = 0;
	media = find_media(stack);
	current = stack;
	while (cont1 > (-ft_lstsize(stack) / 2))
	{
		if (find_val(stack, cont1) >= media)
			break ;
		current = current->next;
		cont1--;
	}
	while (cont2 < (ft_lstsize(stack) / 2))
	{
		if (find_val(stack, cont2) >= media)
			break ;
		current = current->next;
		cont2++;
	}
	if ((cont1 * (-1)) <= cont2)
		return (cont1);
	else if ((cont1 * (-1)) > cont2)
		return (cont2);
	return (0);
}
