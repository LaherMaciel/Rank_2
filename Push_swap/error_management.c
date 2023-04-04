/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 20:39:02 by lwencesl          #+#    #+#             */
/*   Updated: 2023/04/04 15:54:34 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	commands_check_aux(const char *str)
{
	const char	*valid_strings[11];
	int			i;

	valid_strings[0] = "ss";
	valid_strings[1] = "sa";
	valid_strings[2] = "sb";
	valid_strings[3] = "pa";
	valid_strings[4] = "pb";
	valid_strings[5] = "rr";
	valid_strings[6] = "ra";
	valid_strings[7] = "rb";
	valid_strings[8] = "rrr";
	valid_strings[9] = "rra";
	valid_strings[10] = "rrb";
	i = -1;
	while (valid_strings[++i] != NULL)
		if (str == valid_strings[i])
			return (1);
	return (0);
}

int	commands_check(int argc, char *argv[], int stacksize)
{
	char	**val;
	int		i;

	if (stacksize < argc)
	{
		while (argv[++stacksize] != NULL)
		{
			val = ft_split(argv[stacksize], ' ');
			i = -1;
			while (val[++i] != NULL)
				if (commands_check_aux(val[i]) == 0)
					return (0);
		}
	}
	return (1);
}

int	error_check(int argc, char *argv[], t_stack *stack)
{
	int		i;

	i = 1;
	if (stack == NULL || (contains_duplicate_values(stack) != 1))
		i = 0;
	if (commands_check(argc, argv, ft_lstsize(stack)) == 0)
		i = 0;
	if (i == 0)
	{
		ft_printf("Error");
		return (i);
	}
	return (i);
}
