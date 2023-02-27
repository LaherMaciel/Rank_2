/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov_cont.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 13:50:45 by lwencesl          #+#    #+#             */
/*   Updated: 2023/02/25 16:38:23 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	nr_movs(int val_pos, int stack_size)
{
	int	needed_movs;

	if (val_pos < 0)
		val_pos = stack_size + val_pos;
	else if (val_pos >= stack_size)
		val_pos = val_pos - stack_size;
	if (val_pos > (stack_size / 2))
		needed_movs = (stack_size + 1) - val_pos;
	else
		needed_movs = (val_pos) * (-1);
	return (needed_movs);
}

void	mov_cont_sa(void)
{
	
}

void	mov_cont_p(void)
{
	
}
