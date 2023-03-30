/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 20:39:02 by lwencesl          #+#    #+#             */
/*   Updated: 2023/03/30 22:54:31 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	error_check(int argc, char *argv[], t_stack *stack)
{
	int		i;
	char	**val;

	i = 1;
	if (stack == NULL || (contains_duplicate_values(stack) != 1))
		i = -1;
	if (commands_check(argc, argv, ft_lstsize(stack)) == -1)
		i = -1;
	if (i == -1)
	{
		ft_printf("Error");
		return (i);
	}
	return (i);
}

char	**variable_commands(void)
{
	char	commands[11][3];
	char	c;
	int		i;
	int		j;

	i = -1;
	while (commands[i] != NULL)
	{
		j = -1;
		if (i < 3)
			c = 's';
		else if (i < 5)
			c = 'p';
		else
			c = 'r';
		while (++j < 3)
		{
			if (j == 0)
				commands[c]['a'];
			else if (j == 1)
				commands[c]['b'];
			else if (j == 2 && c != 'p')
				commands[c][c];
		}
	}
	return (commands);
}

int	commands_check_aux(char *val[])
{
	char	**commands;
	int		i;
	int		j;
	int		ok;

	i = -1;
	ok = 0;
	*commands = {"sa", "sb", "ss", "pa", "pb", "ra", \
	"rb", "rr", "rra", "rrb", "rrr"};
	while (val[++i] != NULL)
	{
		j = -1;
		while (commands[++j] != NULL)
			if (commands[j] == val[i])
				ok = 1;
		if (ok == 0)
			return (-1);
	}
}

int	commands_check(int argc, char *argv[], int stacksize)
{
	char	**val;

	if (stacksize < argc)
	{
		while (argv[++stacksize] != NULL)
		{
			val = ft_split(argv[stacksize], ' ');
			if (commands_check_aux(val) == -1)
				return (-1);
		}
	}
	return (0);
}
