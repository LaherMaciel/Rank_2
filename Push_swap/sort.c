/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 19:16:34 by lwencesl          #+#    #+#             */
/*   Updated: 2023/02/28 22:23:59 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2(t_stack **stack_1, t_stack **stack_2, char *id_1, char *id_2)
{
	if ((id_1[0] == 'r' && id_1[1] == 'r')
		&& (id_2[0] == 'r' && id_2[1] == 'r'))
		ft_reverse_rotate_rotate(stack_1, stack_2);
	else if ((id_1[0] == 'r' && id_1[1] != 'r')
		&& (id_2[0] == 'r' && id_2[1] != 'r'))
		ft_rotate_rotate(stack_1, stack_2);
	else if ((id_1[0] == 's') && (id_2[0] == 's'))
		ft_swap_swap(stack_1, stack_2);
	else if (id_1[0] == 'r' && id_1[1] == 'r')
		ft_reverse_rotate(stack_1, id_1[2]);
	else if (id_1[0] == 'r')
		ft_rotate(stack_1, id_1[1]);
	else if (id_1[0] == 's')
		ft_swap(stack_1, id_1[1]);
	else if (id_1[0] == 'p' || id_1[0] == 'p')
		ft_pass_to(stack_1, stack_2, id_1[1]);
	else if (id_2[0] == 'r' && id_2[1] == 'r')
		ft_reverse_rotate(stack_1, id_2[2]);
	else if (id_2[0] == 'r')
		ft_rotate(stack_1, id_2[1]);
	else if (id_2[0] == 's')
		ft_swap(stack_1, id_2[1]);
	else if (id_2[0] == 'p' || id_2[0] == 'p')
		ft_pass_to(stack_1, stack_2, id_2[1]);
}

void	sort_1(t_stack **stack_1, t_stack **stack_2)
{
	while (stack_2 == NULL)
	{
		if (nr_movs(find_pos(*stack_1, find_biggest(*stack_1)),
				ft_lstsize(*stack_1)) > 0)
			ft_reverse_rotate_(stack_1, 'a');
		else if (nr_movs(find_pos(*stack_1, find_biggest(*stack_1)),
				ft_lstsize(*stack_1)) < 0)
			ft_rotate_(stack_1, 'a');
		else
			ft_pass_to(stack_1, stack_2, 'b');
	}
}

void	sort(t_stack **stack_1, t_stack **stack_2)
{
	int		sa[4];
	int		pb[4];

	*sa = best_stack_sa_mov(*stack_1, &sa);
	*pb = best_stack_p_mov(stack_1, stack_2, &pb);
	if (ft_lstsize(*stack_1) > 3 && stack_2 == NULL && sa[0]
		> nr_movs(find_pos(find_biggest(*stack_1), stack_1),
			ft_lstsize(*stack_1)))
		sort_1(stack_1, stack_2);
	else if (sa[0] < pb[0])
		sort_2(stack_1, stack_2, s_decisions_cont(*stack_1, sa[1], sa[2]),
			pb_decisions(find_val(*stack_1, pb[1]),
				find_val(*stack_1, pb[2]), pb[1], pb[2]));
	else
		sort_2(stack_1, stack_2, pb_decisions(find_val(*stack_1, pb[1]),
				find_val(*stack_1, pb[2]), pb[1], pb[2]),
			s_decisions_cont(*stack_1, sa[1], sa[2]));
}
