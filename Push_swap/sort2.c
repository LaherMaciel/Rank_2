/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 09:36:32 by lwencesl          #+#    #+#             */
/*   Updated: 2023/04/06 09:57:25 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"


void	sort_p_2(t_stack **stack_1, t_stack **stack_2, int fase)
{
	int		pb[4];
	char	*id;

	if (*stack_1 == NULL)
		return ;
	pb[0] = INT_MAX;
	if (fase == 0)
	{
		best_stack_pb_mov(*stack_1, *stack_2, pb);
		id = pb_decisions(*stack_1, *stack_2, pb[1], pb[2]);
	}
	else
	{
		best_stack_pa_mov(*stack_1, *stack_2, pb);
		if (ft_lstsize(*stack_1) == 1 && ft_lstsize(*stack_2) > 3 && pb[1] == 1)
			pb[1] = 0;
		id = pa_decisions(*stack_1, *stack_2, pb[1], pb[2]);
	}
	sorting(stack_a, stack_b, id);
}

void	sort__2(t_stack **stack_a, t_stack **stack_b, int *cont)
{
	int	sa_ord;
	int	done;
	int	stop;
	int	nr;

	stop = ft_lstsize(*stack_a) * 5;
	sa_ord = 0;
	done = 0;
	while (done == 0 || *stack_b)
	{
		if ((*cont > stop - 10) || (stop < 10) || *cont < 10 || (ft_lstsize(*stack_a) <= 3))
		{
			print_tab(*stack_a, *stack_b);
			ft_printf("\ncont -> %i\n", *cont);
		}
		if (ft_lstsize(*stack_a) <= 3 && sa_ord == 0)
		{
			sort_s_3(stack_a, 'a', cont);
			sa_ord = 1;
		}
		else if (sa_ord == 0)
		{
			nr = find_above_media(*stack_a);
			if (nr > 0)
				ft_reverse_rotate(stack_a, 'a');
			else if (nr < 0)
				ft_rotate(stack_a, 'a');
			else
				ft_pass_to(stack_a, stack_b, 'b');
		}
		else
		
			sort_1(stack_b, stack_a, sa_ord);
			done = 1;
		}
		*cont = *cont + 1;
	}
}

