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

#include "/Users/Laher/OneDrive/Documents/INFORMATICA/42 Lisboa/My_Projectos/Rank_0/Libft/libft.h"

t_stack	*criar_stack(int c, char *v)
{
	t_stack *head;
	t_stack	*stack;
	int		i;

	if (c <= 1)
		return (NULL);
	head = ft_lstnew(v[1]);
	stack = head;
	i = 2;
	while (!v[i])
	{
		stack->next = ft_lstnew(v[i]);
		stack = stack->next;
		i++;
	}
	return (head);
}

/*
//recursive version just beacuse ;) 
t_stack	*criar_stack(int c, char *v, int i)
{
	t_stack	*stack;

	if (c <= 1 || i >= c)
		return (NULL);
	stack = ft_lstnew(v[i]);
	stack->next = criar_stack(c, v, (i + 1));
	return (stack);
}*/
