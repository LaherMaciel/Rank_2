/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_work.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 12:26:41 by lwencesl          #+#    #+#             */
/*   Updated: 2023/03/06 10:10:04 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack **stack, int content)
{
	t_stack	*new_node;

	new_node = (t_stack *) malloc(sizeof(t_stack));
	new_node->content = content;
	new_node->next = *stack;
	*stack = new_node;
}

int	pop(t_stack **head)
{
	int		content;
	t_stack	*temp;

	temp = *head;
	content = (*head)->content;
	*head = (*head)->next;
	free(temp);
	return (content);
}

void	print_stack(t_stack *head)
{
	t_stack	*current;

	current = head;
	while (current != NULL)
	{
		ft_printf ("%d ", current->content);
		current = current->next;
	}
	ft_printf ("\n");
}

// verifica todos os caracteres de cada string
/*
char	*store_integers_in_stack_cut2(t_stack **stack, int argc, char **val)
{	
	int		i;
	int		j;
	long	num;
	int		skip;

	skip = 2;
	i = ft_lstsize(*val);
	while (val[++i])
	{
		j = ft_strlen(val[i]) + 1;
		while (val[i][++j])
		{
			if (ft_isdigit(val[i][j] == 0))
				return (NULL);
			if (ft_isdigit(val[i][j]) || (((val[i][j] == '-'
			|| val[i][j] == '+') && i == 0)))
				skip = 0;
			else if (ft_isprint(val[i][j]) && skip == 0)
				return (NULL);
		}
	}
	if (skip == 0)
	{
		num = ft_atoi(argv[argc]);
		if (num > INT_MAX || num < INT_MIN)
			return (NULL);
		push(stack, num);
	}
	return ("ok");
}
*/

char	*store_integers_in_stack_cut(t_stack **stack, char **vals, char **commands)
{
	int		i;
	int		j;
	long	num;
	int		skip;
	char	*temp;

	skip = 0;
	i = -1;
	while (vals[i])
		i++;
	while (vals[--i] > 0)
	{
		commands_check_aux2(vals, 0);
		j = ft_strlen(vals[i]) + 1;
		while (--j > 0)
		{
			if (ft_isdigit(vals[i][j]) == 0 && (((vals[i][j] != '-'
			|| vals[i][j] != '+')))&& skip == 1)
				return (NULL);
			else if (ft_isdigit(vals[i][j] == 1) && (((vals[i][j] == '-'
			|| vals[i][j] == '+'))) && commands != NULL && skip == 0)
				return (NULL);
			else if (ft_isdigit(vals[i][j] == 1) && (((vals[i][j] == '-'
			|| vals[i][j] == '+'))))
				skip = 1;
		}
		if (skip == 1)
		{
			num = ft_atoi(vals[i]);
			if (num > INT_MAX || num < INT_MIN)
				return (NULL);
			push(stack, num);
		}
		else
		{
			if (commands == NULL)
				commands = ft_strjoin("  ", vals[i]);
			else
			{
				temp = ft_strjoin(vals[i], commands);
				free(commands);
				commands = ft_strjoin(temp, "  ");
				free(temp);
			}
		}
	}
	if	(commands != NULL)
		return ("str");
	return ("ok");
}

// Corre por todas as strings do argv
t_stack	*store_integers_in_stack(int argc, char *argv[], char **commands)
{
	t_stack *stack;
	char	**vals;
	int		i;

	stack = NULL;
	while (--argc > 0)
	{
		i = -1;
		vals = ft_split(argv[argc], ' ');
		if (store_integers_in_stack_cut(&stack, vals, commands) == NULL)
		{
			while (vals[++i])
				free(vals[i]);
			free(vals);
			return (NULL);
		}
		while (vals[++i])
			free(vals[i]);
		free(vals);
	}
	return (stack);
}
