/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_run_modes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laher_maciel <laher_maciel@student.42.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 21:01:28 by lwencesl          #+#    #+#             */
/*   Updated: 2023/05/11 01:35:03 by laher_maciel     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	end_code(t_stack **stack_a, t_stack **stack_b, char *commands)
{
	if (commands != NULL && (check_order_ok(*stack_a) == 1) && *stack_b == NULL)
		ft_printf("\nOK\n");
	else if (commands != NULL)
		ft_printf("\nKO\n");
}

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

// if the user dont introduz nothing | main
void	proxy(t_stack **stack_a, t_stack **stack_b)
{
	char	command[100];
	int		val;

	command[0] = '\0';
	val = 0;
	while (ft_strncmp(command, "exit", 4) != 0)
	{
		ft_printf(">");
		scanf("%s", command);
		//command ================================================
		if (ft_isdigit(command[0]) == 1)
		{
			val = ft_atoi(command);
			if (contains_this_values(*stack_a, val) == 0)
				ft_printf("\nNumber already on the stack, try another number:\n");
			else
				push(stack_a, val);
			print_stack(*stack_a);
		}
		else if (stack_a != NULL)
			user_sort(stack_a, stack_b, command);
		if (check_order_ok(*stack_a) == 1 && *stack_b == NULL)
			break ;
	}
	end_code(stack_a, stack_b, command);
}

// if the user introduz the numbers and the commands | main
void	inputed_commands(t_stack **stack_a,
		t_stack **stack_b, char *command_list)
{
	char	**commands;
	int		i;

	commands = ft_split(command_list, ' ');
	i = -1;
	while (commands[++i] != NULL)
	{
		user_sort(stack_a, stack_b, commands[i]);
		free(commands[i]);
	}
	end_code(stack_a, stack_b, *commands);
	free(commands);
}
