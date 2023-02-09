/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 12:41:11 by lwencesl          #+#    #+#             */
/*   Updated: 2023/02/09 12:41:11 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	main(int c, char *v)
{
	t_stack	stack_a;
	t_stack	*print_stack;
	int		i;

	stack_a = criar_stack(c, v);
	print_stack = stack_a;
	while (!print_stack->next)
	{
		ft_printf("%i\n", print_stack->content);
		print_stack = print_stack->next;
	}
	return (0);
}
