/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 20:39:02 by lwencesl          #+#    #+#             */
/*   Updated: 2023/04/06 09:54:30 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	commands_check_aux2(char **val, int i)
{
	if ((ft_strchr(val[i], '[') || ft_strchr(val[i], ','))
		&& ft_strchr(val[i], ']'))
		val[i] = ft_substr(val[i], 1, ft_strlen(val[i]) - 2);
	else if (ft_strchr(val[i], '[') || ft_strchr(val[i], ','))
		val[i] = ft_substr(val[i], 1, ft_strlen(val[i]) - 1);
	else if (ft_strchr(val[i], ']'))
		val[i] = ft_substr(val[i], 0, ft_strlen(val[i]) - 1);
}

int	commands_check_aux(char *str)
{
	int			i;
	const char	**valid_commands;

	valid_commands = valid_strings();
	i = -1;
	while (valid_strings[++i] != NULL)
		if (ft_strncmp(str, valid_strings[i], ft_strlen(str)))
			return (1);
	return (0);
}

char	*commands_check(int argc, char *argv[], int stacksize)
{
	char	**val;
	char	*commands;
	int		i;

	if (stacksize < argc)
	{
		commands = NULL;
		while (argv[++stacksize] != NULL)
		{
			val = ft_split(argv[stacksize], ' ');
			i = -1;
			while (val[++i] != NULL)
			{
				commands_check_aux2(val, i);
				if (commands_check_aux(val[i]) == 0)
				{
					free(commands);
					return (NULL);
				}
			}
			commands = ft_strjoin(commands, ' ');
			commands = ft_strjoin(commands, **val);
		}
		return (commands);
	}
	return ("ko");
}

char	*error_check(int argc, char *argv[], t_stack *stack)
{
	char	*commands;
	int		i;

	i = 1;
	if (stack == NULL || (contains_duplicate_values(stack) == 0))
		i = 0;
	commands = commands_check(argc, argv, ft_lstsize(stack));
	if (commands == NULL)
		i = 0;
	if (i == 0)
	{
		ft_printf("Error");
		return (NULL);
	}
	if (commands[0] == 'k' && commands[1] == 'o')
		return ("ko");
	return (commands);
}

