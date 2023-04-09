/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 20:39:02 by lwencesl          #+#    #+#             */
/*   Updated: 2023/04/09 14:56:36 by lwencesl         ###   ########.fr       */
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

int	commands_check(char *str)
{
	int		i;
	char	**valid_commands;

	valid_commands = valid_strings();
	i = -1;
	while (valid_commands[++i] != NULL)
		if (ft_strncmp(str, valid_commands[i], ft_strlen(str)) == 0)
			return (1);
	return (0);
}

char	*shortining_code(char **val, char **commands, int i)
{
	while (val[++i] != NULL)
	{
		commands_check_aux2(val, i);
		if (commands_check(val[i]) == 0)
		{
			free(commands);
			return (NULL);
		}
	}
	return ("ok");
}

char	*check_commands(int argc, char *argv[], int stacksize)
{
	char	**val;
	char	*commands;
	int		i;

	if (stacksize < argc)
	{
		commands = "  ";
		while (argv[++stacksize] != NULL)
		{
			val = ft_split(argv[stacksize], ' ');
			i = -1;
			if (shortining_code(val, &commands, i) == NULL)
				return (NULL);
			else
			{
				commands = ft_strjoin(commands, *val);
				commands = ft_strjoin(commands, "  ");
			}
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
	commands = check_commands(argc, argv, ft_lstsize(stack));
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
