/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_run_modes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 21:01:28 by lwencesl          #+#    #+#             */
/*   Updated: 2023/05/18 14:50:42 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

//check if the order of the list is ok
void	end_code(t_stack **stack_a, t_stack **stack_b, char *commands)
{
	if (commands != NULL && (check_order_ok(*stack_a) == 1) && *stack_b == NULL)
		ft_printf("\nOK\n");
	else if (commands != NULL)
		ft_printf("\nKO\n");
}

//	Verify if the command is ok. If its ok it 
//executes it, if its not, return a error message.
int	user_sort(t_stack **stack_a, t_stack **stack_b, char *command)
{
	int		i;

	i = -1;
	while (command[++i])
	{
		if (ft_strncmp(command, "pa", 2) == 0 && stack_a == NULL)
			ft_printf("\n");
		if (ft_strncmp(command, "pb", 2) == 0 && stack_b == NULL)
			ft_printf("\n");
	}
	sorting(stack_a, stack_b, command);
	if (commands_check(command) == 0 && ft_strncmp(command, "exit", 4) != 0)
	{
		ft_printf("Error\n");
		return (0);
	}
	if (ft_strncmp(command, "exit", 4) == 0)
		return (2);
	return (1);
}

// if the user introduz the numbers and the commands | main
void	proxy(t_stack **stack_a,
		t_stack **stack_b)
{
	char	commands[100];
	char	**vals;
	int		i;

	commands[0] = '\0';
	while (ft_strncmp(commands, "exit", 4) != 0)
	{
		scanf("%s", commands);
		vals = ft_split(commands, ' ');
		i = -1;
		while (vals[++i] != NULL)
		{
			vals[i] = commands_check_aux2(&vals[i], 0);
			user_sort(stack_a, stack_b, vals[i]);
			free(vals[i]);
		}
		free(vals);
		if (*stack_b == NULL && check_order_ok(*stack_a) == 1)
			break ;
	}
	end_code(stack_a, stack_b, commands);
}

// if the user introduz the numbers and the commands | main
void	inputed_commands(t_stack **stack_a,
		t_stack **stack_b, char *command_list)
{
	char	**commands;
	int		returned;
	int		i;

	commands = ft_split(command_list, ' ');
	i = -1;
	while (commands[++i] != NULL)
	{
		returned = user_sort(stack_a, stack_b, commands[i]);
		free(commands[i]);
		if (returned == 2)
		{
			free(commands);
			return ;
		}
	}
	end_code(stack_a, stack_b, *commands);
	free(commands);
}
