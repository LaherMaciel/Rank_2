/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 14:05:00 by lwencesl          #+#    #+#             */
/*   Updated: 2023/05/16 15:35:20 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	check_vals(int argc, char *argv[])
{
	int	i;
	int	j;
	int	val;

	i = 0;
	while (++i < argc)
	{
		j = 0;
		val = ft_atoi(argv[i]);
		while (++j < argc)
			if (val == ft_atoi(argv[j]) && i != j)
				return (0);
	}
	return (1);
}

int	check_stack(t_stack *stack)
{
	t_stack	*current;
	int		cont;

	current = stack;
	cont = 0;
	while (current)
	{
		if (current->content > current->next->content)
			return (cont);
		cont++;
		current = current->next;
	}
	return (0);
}

char	**valid_strings(void)
{
	char	**commands;

	commands = (char **) malloc(11 * sizeof(char *));
	if (!commands)
		return (NULL);
	commands[0] = "ss";
	commands[1] = "sa";
	commands[2] = "sb";
	commands[3] = "pa";
	commands[4] = "pb";
	commands[5] = "rr";
	commands[6] = "ra";
	commands[7] = "rb";
	commands[8] = "rrr";
	commands[9] = "rra";
	commands[10] = "rrb";
	return (commands);
}

char	*commands_check_aux2(char **val, int i)
{
	char	*temp;

	temp = val[i];
	if (ft_strchr(temp, '[')
		&& (ft_strchr(temp, ']') || ft_strchr(temp, ',')))
		val[i] = ft_substr(temp, 1, ft_strlen(temp) - 2);
	else if (ft_strchr(temp, ']') || ft_strchr(temp, ','))
		val[i] = ft_substr(temp, 0, ft_strlen(temp) - 1);
	else if (ft_strchr(temp, '[') || ft_strchr(temp, ','))
		val[i] = ft_substr(temp, 1, ft_strlen(temp) - 1);
	else if (temp[0] == '"' && temp[ft_strlen(temp)] == '"')
		val[i] = ft_substr(temp, 1, ft_strlen(temp) - 2);
	else if (temp[0] == '"')
		val[i] = ft_substr(temp, 1, ft_strlen(temp) - 1);
	else if (temp[ft_strlen(temp) - 1] == '"')
		val[i] = ft_substr(temp, 0, ft_strlen(temp) - 1);
	if (ft_strncmp(temp, val[i], ft_strlen(temp)) != 0)
		free(temp);
	return (val[i]);
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
			free(valid_commands);
			return (1);
		}
	}
	i = -1;
	free(valid_commands);
	return (0);
}
