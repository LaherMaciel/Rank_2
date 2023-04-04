/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 14:05:00 by lwencesl          #+#    #+#             */
/*   Updated: 2023/04/04 15:51:24 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	contains_duplicate_values(t_stack *head)
{
	t_stack	*stack1;
	t_stack	*stack2;
	int		num;

	if (head == NULL)
		return (0);
	stack1 = head;
	while (stack1->next != NULL)
	{
		num = stack1->content;
		stack2 = stack1->next;
		while (stack2)
		{
			if (num == stack2->content)
				return (0);
			stack2 = stack2->next;
		}
		stack1 = stack1->next;
	}
	return (1);
}

int	check_vals(int argc, char *argv[])
{
	int	i;
	int	j;
	int	val;

	i = 0;
	while (++i < argc)
	{
		j = 0;
		val = ft_atoi(argv[i]);
		while (++j < argc)
			if (val == ft_atoi(argv[j]) && i != j)
				return (0);
	}
	return (1);
}

int	check_stack(t_stack *stack)
{
	t_stack	*current;
	int		cont;

	current = stack;
	cont = 0;
	while (current)
	{
		if (current->content > current->next->content)
			return (cont);
		cont++;
		current = current->next;
	}
	return (0);
}

/*
//check if the input is correct or valid
void	command_input_error(void)
{}

//check if the numbers are bigger then INT_MAX or smaller then INT_MIN
void	max_int_error(void)
{}
*/