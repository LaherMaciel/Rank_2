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

t_stack	*store_integers_in_stack(int argc, char *argv[])
{
	t_stack	*stack;
	char	**val;
	int		num;

	stack = NULL;
	num = 0;
	while (argc-- > 0)
	{
		if (num == 0 && argv[argc][0] != '0')
			continue ;
		push(&stack, num);
	}
	return (stack);
}

void	auxfasdk(int argc, char *argv)
{
	char	**val;
	size_t	i;
	int		isdig;
	int		isal;

	isdig = 0;
	isal = 0;
	while (argc-- > 0)
	{
		i = -1;
		val = ft_split(argv[argc], ' ');
		while (++i < ft_strlen(*val))
		{
			if (ft_isdigit(*val[i]))
				isdig = 1;
			if (ft_isalpha(*val[i]))
				isal = 1;
		}
		if (isal == 1 && isdig == 1)
			return (0);
		if (isdig == 1)
			
		if (isal == 1)
			
}

t_stack	*store_integers_in_stack2(int len, int min, int max)
{
	t_stack	*stack;
	int		num;

	stack = NULL;
	num = 0;
	while (ft_lstsize(stack) < len)
	{
		num = rand() % (max - min + 1) + min;
		if (double_number_error(stack, num) == 1)
			push(&stack, num);
	}
	return (stack);
}
