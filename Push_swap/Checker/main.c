/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 17:43:48 by lwencesl          #+#    #+#             */
/*   Updated: 2023/05/16 14:49:45 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	*commands;

	commands = NULL;
	stack_a = store_stack(argc, argv, &commands, NULL);
	stack_b = NULL;
	if (commands != NULL
		&& ft_strncmp(commands, "ok", ft_strlen(commands)) == 0)
		commands = NULL;
	commands = error_check_bonus((argc - 1), stack_a, commands);
	if (commands != NULL && commands[0] != 'p')
		inputed_commands(&stack_a, &stack_b, commands);
	else if (commands != NULL && commands[0] == 'p')
		proxy(&stack_a, &stack_b);
	if ((commands != NULL && commands[0] != 'p'))
		free(commands);
	while (stack_a != NULL)
		pop(&stack_a);
	while (stack_b != NULL)
		pop(&stack_b);
	return (0);
}
