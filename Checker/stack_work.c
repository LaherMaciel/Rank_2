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

/*t_stack	*store_integers_in_stack(int argc, char *argv[])
{
	t_stack	*stack;
	int		num;

	stack = NULL;
	num = 0;
	while (argc-- > 0)
	{
		num = ft_atoi(argv[argc]);
		if (num == 0 && argv[argc][0] != '0')
			continue ;
		push(&stack, num);
	}
	return (stack);
}*/

// verifica todos os caracteres de cada string
char	*store_integers_in_stack3_cut(t_stack **stack, int argc, char *argv[])
{	
	int		i;
	long	num;
	int		skip;

	//ft_printf("argv[argc] = %s\n", argv[argc]);
	skip = 2;
	i = -1;
	while (argv[argc][++i] != '\0')
	{
		if (ft_isdigit(argv[argc][i]) || (((argv[argc][i] == '-'
		|| argv[argc][i] == '+') && i == 0)))
		{
			//ft_printf("%i", argv[argc][i] - 48);
			skip = 0;
		}
		else if (ft_isprint(argv[argc][i]) && skip == 0)
		{
			//ft_printf("isprint = %s\n", argv[argc][i]);
			return (NULL);
		}
	}
	//ft_printf("\n");
	if (skip == 0)
	{
		num = ft_atoi(argv[argc]);
		//ft_printf("num = %i\n", num);
		if (num > INT_MAX || num < INT_MIN)
			return (NULL);
		push(stack, num);
	}
	return ("ok");
}

// Corre por todas as strings do argv
t_stack	*store_integers_in_stack3(int argc, char *argv[])
{
	t_stack	*stack;

	stack = NULL;
	while (--argc > 0)
	{
		if (store_integers_in_stack3_cut(&stack, argc, argv) == NULL)
			return (NULL);
		//ft_printf("\n");
	}
	return (stack);
}

/*t_stack	*store_integers_in_stack2(int len, int min, int max)
{
	int		num;
	t_stack	*stack;

	stack = NULL;
	num = 0;
	while (ft_lstsize(stack) < len)
	{
		num = rand() % (max - min + 1) + min;
		if (double_number_error(stack, num) == 1)
			push(&stack, num);
	}
	return (stack);
}*/
