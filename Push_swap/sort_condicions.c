/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_condicions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 18:41:30 by lwencesl          #+#    #+#             */
/*   Updated: 2023/02/09 18:41:30 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	best_movs_build(void)
{
	return (0);
}

int	*which_mov(int best_stack_a_mov, int best_stack_b_mov,
int best_pa_mov, int best_pb_mov)
{
	int	smallest;
	int	pos;
	int	i;

	i = 0;
	smallest = INT_MAX;
	pos = 0;
	while (i < 4)
	{
		if (best_stack_a_mov < smallest)
			pos = 1;
		if (best_stack_b_mov < smallest)
			pos = 2;
		if (best_pa_mov < smallest)
			pos = 3;
		if (best_pb_mov < smallest)
			pos = 5;
	}
	return (0);
}

int	sei_la(t_stack stack_a, t_stack stack_b)
{
	int	sa = best_stack_ord_mov(stack_a);
	int	sb = best_stack_ord_mov(stack_b);
	int	pa = best_stack_p1p2_mov(stack_a);
	int	pb = best_stack_p1p2_mov(stack_b);


}

/*
if ((best_sa * best_sb) < 0)
		return (0);
	if ((best_sa * best_pb) < 0)
		return (0);
	if ((best_sb * best_pa_mov) < 0)
		return (0);
	if ((best_pa * best_pb) < 0)
		return (0);
*/

/*
					A	-7 & -4 = 6
					B	3 & 4 = 3

A 	B

-9
-8
-7
-5
-4
-3
-2
-1
0
1
2
3
4
5
6
7
9
8

*/





