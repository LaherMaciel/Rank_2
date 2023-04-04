/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proxy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 21:01:28 by lwencesl          #+#    #+#             */
/*   Updated: 2023/04/04 21:53:00 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	active_mode(t_stack **stack_a, t_stack **stack_b)
{
	char	command[100]; // assuming a maximum command length of 100 characters

	command[0] = a;
	ft_printf("Introduz numbers to store them in the first stack,\
		or command to swap the numbers or 'exit' to end the program.\n");
	while ((command[0] == 'e' || command[0] == 'E')
		&& (command[3] == 't' || command[3] == 'T'))
	{
		ft_printf("\n>");
		scanf (%s, command);
		if (stack_a != NULL)
		{
			user_sort(stack_a, stack_b, command);
		}
	}
	if (stack_a != NULL)
	{
		print_tab(*stack_a, *stack_b);
		ft_printf("%i\n", cont);
	}
	ft_printf("FIM DO PROGRAMA!\n");
}

void	input_mode(t_stack **stack_a, t_stack **stack_b, char *command_list)
{
	char	*commands;
	int		i;

	commands = ft_split(command_list, ' ');
	i = -1;
	while (commands[++i] != NULL)
		user_sort(stack_a, stack_b, commands[i]);
	if (stack_a != NULL)
	{
		print_tab(*stack_a, *stack_b);
		ft_printf("%i\n", cont);
	}
	ft_printf("FIM DO PROGRAMA!\n");
}
