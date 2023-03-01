/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 19:16:34 by lwencesl          #+#    #+#             */
/*   Updated: 2023/03/01 18:30:45 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_4(t_stack **stack_1, t_stack **stack_2, int *pb)
{
	char	*id;

	while (stack_2 != NULL)
	{
		best_stack_p_mov(*stack_2, *stack_1, pb);
		id = pa_decisions(find_val(*stack_2, pb[1]),
				find_val(*stack_1, pb[2]), pb[1], pb[2]);
		if (id[0] == 'p')
			p_movs(stack_1, stack_2, id);
		else if (id[0] == 's')
			ss_movs(stack_1, stack_2, id);
		else if (id[0] == 'r' && id[2] != '\0')
			rrr_movs(stack_1, stack_2, id);
		else if (id[0] == 'r')
			rr_movs(stack_1, stack_2, id);
	}
	return (1);
}

void	sort_3(t_stack **stack_1, t_stack **stack_2, char *id_1, char *id_2)
{
	if ((id_1[0] == 'r' && id_1[1] == 'r'
			&& (id_1[2] == 'r' || id_1[2] == 'a' || id_1[2] == 'b'))
		&& (id_2[0] == 'r' && id_2[1] == 'r'
			&& (id_1[2] == 'r' || id_1[2] == 'a' || id_1[2] == 'b')))
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
}

void	sort_2(t_stack **stack_1, t_stack **stack_2)
{
	while (stack_2 == NULL)
	{
		if (nr_movs(find_pos(*stack_1, find_biggest(*stack_1)),
				ft_lstsize(*stack_1)) > 0)
			ft_reverse_rotate(stack_1, 'a');
		else if (nr_movs(find_pos(*stack_1, find_biggest(*stack_1)),
				ft_lstsize(*stack_1)) < 0)
			ft_rotate(stack_1, 'a');
		else
			ft_pass_to(stack_1, stack_2, 'b');
	}
}

void	sort_1(t_stack **stack_1, t_stack **stack_2, char *sa, char *pb)
{
	if (ft_lstsize(*stack_1) > 3 && stack_2 == NULL && sa[0]
		> nr_movs(find_pos(*stack_1, find_biggest(*stack_1)),
			ft_lstsize(*stack_1)))
		sort_2(stack_1, stack_2);
	else if (sa[0] < pb[0])
		sort_3(stack_1, stack_2, s_decisions(*stack_1, sa[1], sa[2], 'a'),
			pb_decisions(find_val(*stack_1, pb[1]),
				find_val(*stack_2, pb[2]), pb[1], pb[2]));
	else
		sort_3(stack_1, stack_2, pb_decisions(find_val(*stack_1, pb[1]),
				find_val(*stack_2, pb[2]), pb[1], pb[2]),
			s_decisions(*stack_1, sa[1], sa[2], 'a'));
}

int	sort(t_stack **stack_1, t_stack **stack_2)
{
	int		sa[4];
	int		pb[4];
	int		done;

	done = 0;
	sa[0] = INT_MAX;
	best_stack_sa_mov(*stack_1, sa);
	best_stack_p_mov(*stack_1, *stack_2, pb);
	if (sa[0] != INT_MAX)
		sort_1(stack_1, stack_2, sa, pb);
	else
		done = sort_4(stack_1, stack_2, pb);
	return (done);
}
