/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creating_lists.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 05:24:36 by lwencesl          #+#    #+#             */
/*   Updated: 2023/02/09 05:24:36 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*create_stack(int argc, char **argv)
{
	t_stack	*head;
	t_stack	*stack;
	int		val;
	int		i;

	if (argc <= 1)
		return (NULL);
	val = (int) ft_atoi(argv[1]);
	head = ft_lstnew(&val);
	stack = head;
	i = 2;
	while (argv[i] != NULL)
	{
		val = (int) ft_atoi(argv[i]);
		stack->next = ft_lstnew(&val);
		stack = stack->next;
		i++;
	}
	return (head);
}

/*
//recursive version just beacuse ;) 
t_stack	*create_stack(int argc, char **argv, int i)
{
	t_stack	*stack;

	if (argc <= 1 || i >= argc)
		return (NULL);
	stack = ft_lstnew(argv[i]);
	stack->next = create_stack(argc, argv, (i + 1));
	return (stack);
}
*/
