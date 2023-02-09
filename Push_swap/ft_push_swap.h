/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 03:10:14 by lwencesl          #+#    #+#             */
/*   Updated: 2023/02/09 03:10:14 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include "libft.h"

void	ft_swap(t_stack *stack, char id);
void	ft_swap_swap(t_stack *stack_a, t_stack *stack_b);
void	ft_pass_to(t_stack **stack_1, t_stack **stack_2, char id);
void	ft_rotate(t_stack **stack, char id);
void	ft_rotate_rotate(t_stack *stack_1, t_stack *stack_2);
void	ft_reverse_rotate(t_stack **stack, char id);
void	ft_reverrse_rotate_rotate(t_stack stack_1, t_stack stack_2);

#endif // !FT_PUSH_SWAP.H