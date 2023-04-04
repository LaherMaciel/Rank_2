/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 12:43:29 by lwencesl          #+#    #+#             */
/*   Updated: 2023/03/06 10:12:47 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		movs;

	if (argc > 0)
	{
		stack_a = store_integers_in_stack2(ft_atoi(argv[1]),
				ft_atoi(argv[2]), ft_atoi(argv[3]));
		stack_b = NULL;
		movs = order(&stack_a, &stack_b);
		ft_printf("\n\nMAIN FINAL PRINT\n");
		print_tab(stack_a, stack_b);
		ft_printf("NUMERO DE MOVIMENTOS FEITOS: %i\n", movs);
		while (stack_a != NULL)
			pop(&stack_a);
		while (stack_b != NULL)
			pop(&stack_b);
		ft_printf("ok");
	}
	if (check_stack(stack_a) != 0)
		ft_printf("KO\n", check_stack(stack_a));
	else
		ft_printf("\nOK!\n");
	return (0);
}

int	main2(int argc, char *argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	*commands;
	int		movs;

	if (argc > 0)
	{
		stack_a = store_integers_in_stack3(argc, argv);
		commands = error_check(argc - 1, argv, stack_a);
		if (commands != NULL)
		{
			if (ft_lstsize(stack_a) == argc)
			{
				stack_b = NULL;
				movs = order(&stack_a, &stack_b);
				ft_printf("\n\nMAIN FINAL PRINT\n");
				print_tab(stack_a, stack_b);
				ft_printf("NUMERO DE MOVIMENTOS FEITOS: %i\n", movs);
				while (stack_a != NULL)
					pop(&stack_a);
				while (stack_b != NULL)
					pop(&stack_b);
				ft_printf("ok");
			}
			else if (ft_lstsize(stack_a) < argc)
				ft_printf("Commands");
		}
		while (stack_a != NULL)
			pop(&stack_a);
		while (stack_b != NULL)
			pop(&stack_b);
	}
	else
		ft_printf("Proxy");
	return (0);
}

/*
int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		val;

	val = check_vals(argc, argv);
	if (val != 1)
	{
		ft_printf("ERROR: 1 OR MORE IQUAL NUMBERS (%i)\n", val);
		return (0);
	}
	stack_a = store_integers_in_stack(argc, argv);
	stack_b = NULL;
	//ft_printf("stack size = %i\n", (ft_lstsize(stack_a) / 2));
	val = order(&stack_a, &stack_b);
	ft_printf("\n\nMAIN FINAL PRINT\n");
	print_tab(stack_a, stack_b);
	ft_printf("NUMERO DE MOVIMENTOS FEITOS: %i\n", val);
	while (stack_a != NULL)
		pop(&stack_a);
	while (stack_b != NULL)
		pop(&stack_b);
	ft_printf("ok");
	return (0);
}
*/


/*
visualizer2(&stack_a, &stack_b);

done = sort(&stack_a, &stack_b);
print_tab(stack_a, stack_a);
*/
