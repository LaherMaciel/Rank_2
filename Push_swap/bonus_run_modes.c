/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_run_modes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 21:01:28 by lwencesl          #+#    #+#             */
/*   Updated: 2023/04/25 12:50:03 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	user_sort(t_stack **stack_a, t_stack **stack_b, char *command)
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
	if (commands_check(command) == 0 && ft_strncmp(command, "exit", 4) != 0)
	{
		ft_printf("ERROR: VALID INPUTS -> 'numbers', ss," \
					" sa, sb, rr, ra, rb, rrr, rra," \
					" rrb, pa, pb or exit\n");
		return (0);
	}
	return (1);
}

void	proxy_cut(t_stack **stack_a, t_stack **stack_b, int cont, char *command)
{
	if (user_sort(stack_a, stack_b, command) == 1
		&& ft_strncmp(command, "exit", 4) != 0)
		cont++;
	ft_printf("Nr movs-> %i;\n", cont);
}

// if the user dont introduz nothing | main
void	proxy(t_stack **stack_a, t_stack **stack_b, int cont)
{
	char	command[100];
	int		val;

	command[0] = '\0';
	val = 0;
	ft_printf("Introduz numbers to store them in the first stack,\
 or command to swap the numbers or 'exit' to end the program.\n");
	while (ft_strncmp(command, "exit", 4) != 0)
	{
		ft_printf("\n>");
		scanf("%s", command);
		if (ft_isdigit(command[0]) == 1)
		{
			val = ft_atoi(command);
			if (contains_this_values(*stack_a, val) == 0)
				ft_printf("\nNumber already on the stack, try another number:\n");
			else
				push(stack_a, val);
			ft_printf("command2 = %s\n", command);
			print_stack(*stack_a);
		}
		else if (stack_a != NULL)
			proxy_cut(stack_a, stack_b, cont, command);
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
		free(commands[i]);
	}
	free(commands);
}
