/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 12:58:31 by lwencesl          #+#    #+#             */
/*   Updated: 2023/03/02 02:48:02 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	aux_3(int *pos_1, int *pos_2)
{
	if (*pos_1 < 0  && (pos_1 + 1) != pos_2)
	{
		(*pos_1)++;
		(*pos_2)++;
	}
	else if (*pos_1 > 0  && (pos_1 + 1) != pos_2)
	{
		(*pos_1)--;
		(*pos_2)--;
	}
}

void	aux_2(int *pos_1, int *pos_2, int out)
{
	if ((*pos_1 == 0 || *pos_1 == -1)
		&& (*pos_2 == 0 || *pos_2 == -1))
	{
		if ((*pos_1 < *pos_2) && out == 1)
		{
			(*pos_1)++;
			(*pos_2)--;
		}
		else if ((*pos_1 > *pos_2) && out == 2)
		{
			(*pos_1)--;
			(*pos_2)++;
		}
	}
	else
		aux_3(pos_1, pos_2);
}

void	aux_1(int *pos_1, int *pos_2, int *cont, int out)
{
	if (*pos_2 > 0 && *pos_1 == 0 && *pos_2 != 1)
	{
		(*pos_1)--;
		(*pos_2)--;
	}
	else if (*pos_2 < 0 && *pos_1 == 0 && *pos_2 != -1)
		(*pos_1)--;
	else if (*pos_2 > 0 && *pos_1 == -1)
		(*pos_1)++;
	else if (*pos_2 == 1 && *pos_1 == 0 && out == 1)
	{
		(*pos_1)++;
		(*pos_2)--;
		(*cont)++;
	}
	else
		aux_2(pos_1, pos_2, out);
}

int	s_decisions_cont(t_stack *stack, int pos_1, int pos_2)
{
	int	out;
	int	cont;
	int	turn;

	cont = 0;
	out = 0;
	turn = 0;
	if (find_val(stack, pos_1) < find_val(stack, pos_2))
		out = 1;
	else
		out = 2;
	if (((pos_1 - 1) == pos_2) || ((pos_1 + 1) == pos_2))
		return (0);
	while (out != 3)
	{
		aux_1(&pos_1, &pos_2, &cont, out);
		if (pos_2 > (ft_lstsize(stack) / 2) && turn == 0)
		{
			pos_2 = - (ft_lstsize(stack) / 2);
			turn++;
		}
		else if (pos_2 * (-1) > (ft_lstsize(stack) / 2) && turn == 0)
		{
			pos_2 = (ft_lstsize(stack) / 2) - 1;
			turn++;
		}
		cont++;
		if (((pos_1 - 1) == pos_2) && out == 1)
			out = 3;
		else if (((pos_1 + 1) == pos_2) && out == 2)
			out = 3;
	}
	return (cont);
}

char	*sa_decisions(t_stack *stack, int pos_1, int pos_2)
{
	ft_printf("s_decisions in\n");
	if (pos_2 > 0 && pos_1 == 0 && pos_2 != 1)
		return ("rra");
	else if (pos_2 < 0 && pos_1 == 0 && pos_2 != -1)
		return ("sa");
	else if (pos_2 > 0 && pos_1 == -1)
		return ("sa");
	else if ((pos_1 == 0 || pos_1 == -1)
		&& (pos_2 == 0 || pos_2 == -1))
	{
		if (((pos_1 < pos_2) && (find_val(stack, pos_1)
					< find_val(stack, pos_2))))
			return ("sa");
		else if (((pos_1 > pos_2) && (find_val(stack, pos_1)
					> find_val(stack, pos_2))))
			return ("sa");
	}
	else if (pos_1 <= 0 && (pos_1 + 1) != pos_2)
		return ("ra");
	else if (pos_1 > 0 && (pos_1 + 1) != pos_2)
		return ("rra");
	return (NULL);
}

/*
	char	*aux_1(int *pos_1, int *pos_2, int *cont, t_stack stack)
{
	if (pos_2 > 0 && pos_1 == 0 && pos_2 != ft_lstsize(stack))
		return (ft_strjoin("rr", id));// rra or rrb
	else if (pos_2 < 0 && pos_1 == 0 && pos_2 != -1)
		return (ft_strjoin("s", id));// sa or sb
	else if (pos_2 > 0 && pos_1 == -1)
		return (ft_strjoin("s", id));// sa or sb
	else if (pos_2 == 1 && pos_1 == 0 && (find_val(stack, pos_1)
		< find_val(stack, pos_2)))
		return (ft_strjoin(ft_strjoin("rr", id),
			ft_strjoin("s", id)));// rra + sa or rrb + sb
	return (NULL);
}

char	*aux_2(int *pos_1, int *pos_2, t_stack stack)
{
	if ((pos_1 == 0 || pos_1 == -1)
			&& (pos_2 == 0 || pos_2 == -1))
	{
		if (((pos_1 < pos_2) && (find_val(stack, pos_1) < find_val(stack, pos_2)))
			return (ft_strjoin("s", id));// sa or sb
		else if (((pos_1 > pos_2) && (find_val(stack, pos_1) > find_val(stack, pos_2)))
			return (ft_strjoin("s", id));// sa or sb
	}
	else if (pos_1 < 0)
		return (ft_strjoin("r", id));// ra or rb
	else if (pos_1 > 0)
		return (ft_strjoin("rr", id));// rra  or rrb
	return (NULL);
}

	return (aux_1(&pos_1, &pos_2, &cont, stack));
	return (aux_2(&pos_1, &pos_2, stack));
*/
