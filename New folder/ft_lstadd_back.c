/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:53:57 by lwencesl          #+#    #+#             */
/*   Updated: 2022/11/15 17:30:50 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*temp;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	temp = ft_lstlast(*lst);
	temp->next = new;
}
