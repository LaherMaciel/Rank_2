/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <laherwpayotmaciel@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 17:43:48 by lwencesl          #+#    #+#             */
<<<<<<< HEAD:Checker/main.c
/*   Updated: 2023/05/05 20:17:48 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
=======
/*   Updated: 2023/05/03 17:13:43 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
>>>>>>> f1f5c4aa36db2b2f137c201c0d9175b7edf83a49:Push_swap/main_bonus.c

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
<<<<<<< HEAD:Checker/main.c
		if (commands != NULL && commands[0] != 'x')
=======
		if (commands != NULL)
>>>>>>> f1f5c4aa36db2b2f137c201c0d9175b7edf83a49:Push_swap/main_bonus.c
			inputed_commands(&stack_a, &stack_b, commands, &cont);
		else if (commands != NULL && commands[0] == 'x')
			proxy(&stack_a, &stack_b, cont);
	}
	else
		proxy(&stack_a, &stack_b, cont);
<<<<<<< HEAD:Checker/main.c
	if ((commands != NULL && commands[0] != 'x'))
		free(commands);
=======
	end_code(&stack_a, &stack_b, commands);
	free(commands);
>>>>>>> f1f5c4aa36db2b2f137c201c0d9175b7edf83a49:Push_swap/main_bonus.c
	while (stack_a != NULL)
		pop(&stack_a);
	while (stack_b != NULL)
		pop(&stack_b);
	return (0);
}

/*
commands[0] != 'e' && 

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