/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_mode.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 21:01:28 by lwencesl          #+#    #+#             */
/*   Updated: 2023/04/06 09:53:49 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

// if the user dont introduz nothing | main
void	proxy(t_stack **stack_a, t_stack **stack_b, int *cont)
{
	char	command[100];
	int		val;

	command[0] = a;
	val = 0;
	ft_printf("Introduz numbers to store them in the first stack,\
		or command to swap the numbers or 'exit' to end the program.\n");
	while (ft_strncmp(command, "exit", 4) != 0)
	{
		ft_printf("\n>");
		scanf(%s, command);
		if (is_digit(command[0]) == 1)
		{
			val = ft_atoi(command);
			push(stack_a, val);
		}
		else if (stack_a != NULL)
		{
			user_sort(stack_a, stack_b, command);
			cont++;
		}
	}
}

// if the user introduz the numbers and the commands | main
void	inputed_commands(t_stack **stack_a,
		t_stack **stack_b, char *command_list, int *cont)
{
	char	*commands;
	int		i;

	commands = ft_split(command_list, ' ');
	free(command_list);
	i = -1;
	while (commands[++i] != NULL)
	{
		user_sort(stack_a, stack_b, commands[i]);
		cont++;
	}
}

// if the user introduz just the numbers | main
int	auto_sort(t_stack **stack_a, t_stack **stack_b, int *cont)
{
	int	smallest;

	sort(stack_a, stack_b, &cont);
	smallest = nr_movs(find_pos(*stack_a,
				find_smallest(*stack_a)), ft_lstsize(*stack_a));
	print_tab(*stack_a, *stack_b);
	while (smallest != 0)
	{
		if (smallest > 0)
		{
			ft_reverse_rotate(stack_a, 'a');
			smallest--;
		}
		else if (smallest < 0)
		{
			ft_rotate(stack_a, 'a');
			smallest++;
		}
		cont++;
	}
	return (cont);
}
