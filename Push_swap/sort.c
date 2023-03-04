/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 19:16:34 by lwencesl          #+#    #+#             */
/*   Updated: 2023/03/04 01:11:08 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_5(t_stack **stack_1, t_stack **stack_2, int *mov)
{
	//ft_printf("sort_5 in\n");
	char	*id;

	while (stack_2 != NULL)
	{
		best_stack_p_mov(*stack_2, *stack_1, mov);
		id = pa_decisions(find_val(*stack_2, mov[1]),
				find_val(*stack_1, mov[2]), mov[1], mov[2]);
		if (id[0] == 'p')
			p_movs(stack_1, stack_2, id);
		else if (id[0] == 's')
			ss_movs(stack_1, stack_2, id);
		else if (id[0] == 'r' && id[2] != '\0')
			rrr_movs(stack_1, stack_2, id);
		else if (id[0] == 'r')
			rr_movs(stack_1, stack_2, id);
	}
	//ft_printf("sort_5 out\n");
	return (1);
}

void	sort_4(t_stack **stack, int *mov)
{
	char	*id;
	id = sa_decisions(*stack, mov[1], mov[2]);
	if (id[0] == 'p')
		p_movs(stack, stack, id);
	else if (id[0] == 's')
		ss_movs(stack, stack, id);
	else if (id[0] == 'r' && id[2] != '\0')
		rrr_movs(stack, stack, id);
	else if (id[0] == 'r')
		rr_movs(stack, stack, id);
}

void	sort_3(t_stack **stack_1, t_stack **stack_2, char *id_1, char *id_2)
{
	//ft_printf("sort_3 in\n");
	ft_printf("*id_1 -> %s, *id_2 -> %s\n", id_1, id_2);
	if (((id_1[0] == 'r' && id_1[1] == 'r') && (ft_strlen(id_1) == 3))
		&& ((id_2[0] == 'r' && id_2[1] == 'r') && (ft_strlen(id_2) == 3))
		&& ((id_1[2] == 'a' && id_2[2] == 'b')))
		ft_reverse_rotate_rotate(stack_1, stack_2);
	else if (id_1[0] == 'r' && ft_strlen(id_1) == 2 && id_2[0] == 'r' && ft_strlen(id_2) == 2
		&& ((id_1[1] == 'a' && id_2[1] == 'b')))
		ft_rotate_rotate(stack_1, stack_2);
	else if ((id_1[0] == 's') && (id_2[0] == 's'))
		ft_swap_swap(stack_1, stack_2);
	else if (id_1[0] == 'r' && id_1[1] == 'r' && id_1[2] == 'r' && ft_strlen(id_1) == 3)
		ft_reverse_rotate_rotate(stack_1, stack_2);
	else if (id_1[0] == 'r' && id_1[1] == 'r' && ft_strlen(id_1) == 3)
		ft_reverse_rotate(stack_1, id_1[2]);
	else if (id_1[0] == 'r' && id_1[1] == 'r')
		ft_rotate_rotate(stack_1, stack_2);
	else if (id_1[0] == 'r' && ft_strlen(id_1) == 2)
		ft_rotate(stack_1, id_1[1]);
	else if (id_1[0] == 's')
		ft_swap(stack_1, id_1[1]);
	else if (id_1[0] == 'p' || id_1[0] == 'p')
		ft_pass_to(stack_1, stack_2, id_1[1]);
	//ft_printf("\nsort_3 out\n");
}

void	sort_1(t_stack **stack_1, t_stack **stack_2, int *sa, int *pb)
{
	char *sa_id;
	char *pb_id;

	sa_id = sa_decisions(*stack_1, sa[1], sa[2]);
	pb_id = pb_decisions(*stack_1, *stack_2, pb[1], pb[2]);
	//ft_printf("sa_id -> %s	|	pb_id -> %s\n", sa_id, pb_id);
	//ft_printf("sort_1 in\n");
	//ft_printf("sa[0] = %i > nr_movs biggest = %i\n", sa[0], (nr_movs(find_pos(*stack_1, find_biggest(*stack_1)), ft_lstsize(*stack_1))));
	ft_printf("BEST MOVS sa[0] = %i > pb[0] = %i\n", sa[0], pb[0]);
	if (sa[0] < pb[0])
	{
		//ft_printf("sort_1 second if in\n");
		//ft_printf("sa[0] = %i < pb[0] = %i\n", sa[0], pb[0]);
		if (sa_id[0] == 'r' && (sa_id[1] == 'b' || sa_id[2] == 'b'))
			sort_3(stack_2, stack_1, sa_id, pb_id);
		else
			sort_3(stack_1, stack_2, sa_id, pb_id);
	}
	else
	{
		//ft_printf("sort_1 terceiro if in\n");
		if (pb_id[0] == 'r' && (pb_id[1] == 'b' || pb_id[2] == 'b'))
			sort_3(stack_2, stack_1, pb_id, sa_id);
		else
			sort_3(stack_1, stack_2, pb_id, sa_id);
	}
	//ft_printf("\nsort_1 out\n");
}

int	sort(t_stack **stack_1, t_stack **stack_2)
{
	int		sa[4];
	int		pb[4];
	int		done;

	done = 0;
	sa[0] = INT_MAX;
	pb[0] = INT_MAX;
	best_stack_sa_mov(*stack_1, sa);
	ft_printf("BEST sa[ %i | pos1 -> %i val1 -> %i | pos2 -> %i val2 -> %i ];\n", sa[0], sa[1],
			find_val(*stack_1, sa[1]), sa[2], find_val(*stack_1, sa[2]));
	best_stack_p_mov(*stack_1, *stack_2, pb);
	//ft_printf("best_stack_p_mov out\n");
	ft_printf("BEST pb[ %i | pos1 -> %i val1 -> %i | pos2 -> %i val2 -> %i ];\n", pb[0], pb[1],
		find_val(*stack_1, pb[1]), pb[2], find_val(*stack_2, pb[2]));
	if (sa[0] != INT_MAX)
		sort_1(stack_1, stack_2, sa, pb);
	if (sa[0] == INT_MAX)
		done = sort_5(stack_1, stack_2, pb);
	return (done);
}
