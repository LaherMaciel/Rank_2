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

int	store_cut2(char *vals, char *commands, int skip, t_stack *stack)
{
	int	j;

	j = -1;
	while (vals[++j])
	{
		if (stack != NULL && ft_isdigit(vals[j]) == 0
			&& (((ft_strchr(vals, '-') == NULL
						&& ft_strchr(vals, '+') == NULL))))
			return (0);
		if (ft_isdigit(vals[j]) == 0 && (((ft_strchr(vals, '-') == NULL
						|| ft_strchr(vals, '+') == NULL))) && skip == 1)
			return (0);
		else if (ft_isdigit(vals[j]) == 1 && (((ft_strchr(vals, '-') != NULL
						|| ft_strchr(vals, '+') != NULL)))
			&& commands != NULL && skip == 2)
			return (0);
		else if (ft_isdigit(vals[j]) == 1 || (((ft_strchr(vals, '-') != NULL
						|| ft_strchr(vals, '+') != NULL))))
			skip = 1;
	}
	return (skip);
}

char	*store_cut(t_stack **stack, char **vals, char *commands)
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
		skip = store_cut2(vals[i], commands, 2, *stack);
		if (skip == 1)
		{
			if (ft_atoi(vals[i]) > INT_MAX || ft_atoi(vals[i]) < INT_MIN)
				return (NULL);
			push(stack, ft_atoi(vals[i]));
		}
		else if (skip == 2)
		{
			if (commands == NULL)
				commands = ft_strjoin("  ", vals[i]);
			else
			{
				temp = ft_strjoin(vals[i], commands);
				free(commands);
				commands = ft_strjoin("  ", temp);
				free(temp);
			}
		}
		else
			return (NULL);
	}
	if (commands == NULL)
		return ("ok");
	return (commands);
}

// Corre por todas as strings do argv
t_stack	*store_stack(int argc, char *argv[], char **commands, t_stack *stack)
{
	char	**vals;
	int		i;

	while (--argc > 0)
	{
		i = -1;
		vals = ft_split(argv[argc], ' ');
		*commands = store_cut(&stack, vals, *commands);
		if (*commands == NULL)
		{
			while (vals[++i])
				free(vals[i]);
			free(vals);
			while (stack != NULL)
				pop(&stack);
			return (NULL);
		}
		while (vals[++i])
			free(vals[i]);
		free(vals);
	}
	return (stack);
}
