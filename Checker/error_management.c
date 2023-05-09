/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <laherwpayotmaciel@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 20:39:02 by lwencesl          #+#    #+#             */
/*   Updated: 2023/05/05 19:39:42 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

//send an error message if the program recieves a number more then 1 time
int	contains_this_values(t_stack *head, int num)
{
	t_stack	*stack;

	stack = head;
	while (stack)
	{
		if (num == stack->content)
			return (0);
		stack = stack->next;
	}
	return (1);
}

// check if theres any duplicaded value.
int	contains_duplicate_values(t_stack *head)
{
	t_stack	*current1;
	t_stack	*current2;

	current1 = head;
	current2 = NULL;
	while (current1 != NULL)
	{
		current2 = current1->next;
		while (current2 != NULL)
		{
			if (current1->content == current2->content)
				return (0);
			current2 = current2->next;
		}
		current1 = current1->next;
	}
	return (1);
}

int	check_order_ok(t_stack *stack)
{
	if (stack == NULL)
	{
		return (0);
	}
	while (stack->next != NULL)
	{
		if (stack->content > stack->next->content)
		{
			return (0);
		}
		stack = stack->next;
	}
	return (1);
}

char	*error_check(t_stack *stack)
{
	if (stack == NULL || (contains_duplicate_values(stack) == 0))
	{
		ft_printf("Error\n");
		return (NULL);
	}
	return ("ko");
}
