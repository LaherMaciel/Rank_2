/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laher_maciel <laher_maciel@student.42.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 14:05:00 by lwencesl          #+#    #+#             */
/*   Updated: 2023/04/21 14:03:11 by laher_maciel     ###   ########.fr       */
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

char	**valid_strings(void)
{
	char	**commands;

	commands = (char **) malloc(11* sizeof(char *));
	if (!commands)
		return (NULL);
	commands[0] = "ss";
	commands[1] = "sa";
	commands[2] = "sb";
	commands[3] = "pa";
	commands[4] = "pb";
	commands[5] = "rr";
	commands[6] = "ra";
	commands[7] = "rb";
	commands[8] = "rrr";
	commands[9] = "rra";
	commands[10] = "rrb";
	return (commands);
}

/*
//check if the input is correct or valid
void	command_input_error(void)
{}

//check if the numbers are bigger then INT_MAX or smaller then INT_MIN
void	max_int_error(void)
{}
*/
