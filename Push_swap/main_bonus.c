/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laher_maciel <laher_maciel@student.42.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 17:43:48 by lwencesl          #+#    #+#             */
/*   Updated: 2023/04/22 11:07:15 by laher_maciel     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	end_code(t_stack **stack_a, t_stack **stack_b, int cont, char *commands)
{
	if (commands != NULL && (check_order_ok(*stack_a) == 1) && *stack_b == NULL)
		ft_printf("\nOK\n");
	else
		ft_printf("\nKO\n");
	if (stack_a != NULL)
	{
		ft_printf("\n\nMAIN FINAL PRINT\n");
		print_tab(*stack_a, *stack_b);
	}
	ft_printf("NUMERO DE MOVIMENTOS FEITOS: %i\n", cont);
	ft_printf("FIM DO PROGRAMA!\n");
}

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	*commands;
	int		cont;

	cont = 0;
	stack_a = NULL;
	stack_b = NULL;
	commands = NULL;
	if (argc > 1)
	{
		stack_a = store_integers_in_stack(argc, argv);
		commands = error_check_bonus((argc - 1), argv, stack_a);
		if (commands != NULL && check_order_ok(stack_a) == 0)
			inputed_commands(&stack_a, &stack_b, commands, &cont);
	}
	else
		proxy(&stack_a, &stack_b, cont);
	end_code(&stack_a, &stack_b, cont, commands);
	while (stack_a != NULL)
		pop(&stack_a);
	while (stack_b != NULL)
		pop(&stack_b);
	return (0);
}

/*
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
*/

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