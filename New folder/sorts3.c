/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 08:38:07 by lwencesl          #+#    #+#             */
/*   Updated: 2023/02/24 17:28:49 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	if_dif_signs_adv(int val_pos1, int val_pos2,
int stack_size1, int stack_size2 )
{
	int	sign1;
	int	sign2;
	int	needed_movs1;
	int	needed_movs2;

	sign1 = 1;
	sign2 = 1;
	needed_movs1 = nr_movs(val_pos1, stack_size1);
	needed_movs2 = nr_movs(val_pos2, stack_size2);
	if (needed_movs1 < 0)
	{
		needed_movs1 = needed_movs1 * (-1);
		sign1 = -1;
	}
	else if (needed_movs2 < 0)
	{
		needed_movs2 = needed_movs2 * (-1);
		sign2 = -1;
	}

	if (needed_movs1 < needed_movs2)
		return (val_pos1);
	return (val_pos2);
}

int	total_movs_adv(int val_pos1, int val_pos2,
int stack_size1, int stack_size2)
{
	int	total_movs_need;
	int	needed_movs1;
	int	needed_movs2;

	needed_movs1 = nr_movs(val_pos1, stack_size1);
	needed_movs2 = nr_movs(val_pos2, stack_size2);
	if (needed_movs1 * needed_movs2 < 0)
		total_movs_need = if_dif_signs_adv(val_pos1,
				val_pos2, stack_size1, stack_size2);
	else
	{
		if (needed_movs1 > needed_movs2)
			total_movs_need = val_pos2;
		else
			total_movs_need = val_pos1;
	}
	return (total_movs_need);
}
