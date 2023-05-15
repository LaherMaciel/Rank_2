/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_run_modes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laher_maciel <laher_maciel@student.42.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 21:01:28 by lwencesl          #+#    #+#             */
/*   Updated: 2023/05/12 19:55:52 by laher_maciel     ###   ########.fr       */
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
	int		i;

	i = -1;
	while (command[++i])
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

/*
// if the user dont introduz nothing | main
void	proxy(t_stack **stack_a, t_stack **stack_b)
{
	char	command[100];
	int		val;
	int		i;

	command[0] = '\0';
	val = 0;
	i = -1;
	while (ft_strncmp(command, "exit", 4) != 0)
	{
		ft_printf(">");
		scanf("%s", command);
		if (ft_isdigit(command[0]) == 1)
		{
			val = ft_atoi(command);
			if (contains_this_values(*stack_a, val) == 0)
				ft_printf("\nNumber already on the stack,\
				try another number:\n");
			else
				push(stack_a, val);
			print_stack(*stack_a);
		}
		else if (stack_a != NULL)
			user_sort(stack_a, stack_b, command);
		if ((check_order_ok(*stack_a) == 1
				&& *stack_b == NULL) || ft_strncmp(command, "exit", 4))
			return ;
	}
	end_code(stack_a, stack_b, command);
}
*/

char	*proxy_cut(t_stack **stack_a, t_stack **stack_b, char **vals, char *commands)
{
	int		i;
	int		skip;
	char	*temp;

	i = 0;
	while (vals[i])
		i++;
	while (--i >= 0)
	{
		commands_check_aux2(vals, i);
		skip = store_cut2(vals[i], commands, 2, *stack_a);
		if (skip == 1)
		{
			if (ft_atoi(vals[i]) > INT_MAX || ft_atoi(vals[i]) < INT_MIN)
				ft_printf("Error\n");
			else if (contains_duplicate_values(*stack_a) == 1 && contains_duplicate_values(*stack_b) == 1)
				push(stack_a, ft_atoi(vals[i]));
			else
				ft_printf("Error\n");
		}
		else if (ft_strncmp(vals[i], "exit", 4) == 0)
			return (NULL);
		else if (skip == 2 && stack_a != NULL)
			user_sort(stack_a, stack_b, vals[i]);
		else
		{
			if (commands != NULL && ft_strncmp(commands, "ok", 2) != 0)
				free(commands);
			return (NULL);
		}
	}
	if (commands == NULL)
		return ("ok");
	return (commands);
}

void	proxy(t_stack **stack_a, t_stack **stack_b)
{
	char	commands[100];
	char	**vals;
	int		i;

	commands[0] = '\0';
	while (ft_strncmp(commands, "exit", 4) != 0)
	{
		i = -1;
		scanf("%s", commands);
		vals = ft_split(commands, ' ');
		*commands = store_cut(&stack_a, vals, *commands);
		if (*commands == NULL)
		{
			while (vals[++i])
				free(vals[i]);
			free(vals);
			while (stack_a != NULL)
				pop(stack_a);
			return ;
		}
		while (vals[++i])
			free(vals[i]);
		free(vals);
	}
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
