/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 20:39:02 by lwencesl          #+#    #+#             */
/*   Updated: 2023/04/10 14:55:51 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
void	commands_check_aux2(char **val, int i)
{
	if (ft_isalpha(val[i][0]) == 0
	&& (ft_isalpha(val[i][ft_strlen(val[i]) - 1] == 0)
	|| ft_isalpha(val[i][ft_strlen(val[i])] == 0)) 
		val[i] = ft_substr(val[i], 1, ft_strlen(val[i]) - 2);
	else if (ft_strchr(val[i], ']') || ft_strchr(val[i], ','))
		val[i] = ft_substr(val[i], 0, ft_strlen(val[i]) - 1);
	else if (ft_strchr(val[i], '[') || )
		val[i] = ft_substr(val[i], 1, ft_strlen(val[i]) - 1);
}
*/

void	commands_check_aux2(char **val, int i)
{
	if (ft_strchr(val[i], '[')
		&& (ft_strchr(val[i], ']') || ft_strchr(val[i], ',')))
		val[i] = ft_substr(val[i], 1, ft_strlen(val[i]) - 2);
	else if (ft_strchr(val[i], ']') || ft_strchr(val[i], ','))
		val[i] = ft_substr(val[i], 0, ft_strlen(val[i]) - 1);
	else if (ft_strchr(val[i], '[') || ft_strchr(val[i], ','))
		val[i] = ft_substr(val[i], 1, ft_strlen(val[i]) - 1);
}

int	commands_check(char *str)
{
	int		i;
	char	**valid_commands;

	valid_commands = valid_strings();
	i = -1;
	while (++i < 11)
	{
		if (ft_strlen(str) < 2)
			break ;
		else if (ft_strncmp(str, valid_commands[i], ft_strlen(str)) == 0)
		{
			//free(valid_commands);
			return (1);
		}
	}
	free(valid_commands);
	return (0);
}

char	*check_commands_cut(char **val)
{
	int	i;

	i = -1;
	while (val[++i] != NULL)
	{
		commands_check_aux2(val, i);
		if (commands_check(val[i]) == 0)
			return (NULL);
		//ft_printf("check_commands_cut = %s\n", val[i]);
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
			if (check_commands_cut(val) == NULL)
			{
				free(val);
				return (NULL);
			}
			i = -1;
			while (val[++i])
			{
				commands = ft_strjoin(commands, val[i]);
				commands = ft_strjoin(commands, "  ");
			}
		}
		free(val);
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
