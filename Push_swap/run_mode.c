/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_mode.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 21:01:28 by lwencesl          #+#    #+#             */
/*   Updated: 2023/04/10 15:20:18 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	user_sort(t_stack **stack_a, t_stack **stack_b, char *command)
{
	int	i;

	i = -1;
	while (command[++i] != '\0')
	{
		if (ft_strncmp(command, "pa", 2) == 0 && stack_a == NULL)
			ft_printf("Can't do this movement, stack_a empty.\n");
		if (ft_strncmp(command, "pb", 2) == 0 && stack_b == NULL)
			ft_printf("Can't do this movement, stack_b empty.\n");
	}
	sorting(stack_a, stack_b, command);
	if (commands_check(command) == 0)
		ft_printf("ERROR: VALID INPUTS -> 'numbers', ss," \
				" sa, sb, rr, ra, rb, rrr, rra," \
				" rrb, pa, pb or exit\n");
}

// if the user dont introduz nothing | main
void	proxy(t_stack **stack_a, t_stack **stack_b, int *cont)
{
	char	command[100];
	int		val;

	command[0] = 'a';
	val = 0;
	ft_printf("Introduz numbers to store them in the first stack,\
 or command to swap the numbers or 'exit' to end the program.\n");
	while (ft_strncmp(command, "exit", 4) != 0)
	{
		ft_printf("\n>");
		scanf("%s", command);
		if (ft_isdigit(command[0]) == 1)
		{
			//val = ft_split(, ' ');
			val = ft_atoi(command);
			push(stack_a, val);
		}
		else if (stack_a != NULL)
		{
			user_sort(stack_a, stack_b, command);
			cont++;
		}
		//print_stack(*stack_a);
		//print_stack(*stack_b);
	}
}

// if the user introduz the numbers and the commands | main
void	inputed_commands(t_stack **stack_a,
		t_stack **stack_b, char *command_list, int *cont)
{
	char	**commands;
	int		i;

	commands = ft_split(command_list, ' ');
	i = -1;
	while (commands[++i] != NULL)
	{
		user_sort(stack_a, stack_b, commands[i]);
		cont++;
	}
}

// if the user introduz just the numbers | main
void	auto_sort(t_stack **stack_a, t_stack **stack_b, int *cont)
{
	int	smallest;

	sort(stack_a, stack_b, cont);
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
}

