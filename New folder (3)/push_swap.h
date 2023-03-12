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

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

//# include "libft.h"

# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdint.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_stack
{
	int				content;
	struct s_stack	*next;
}					t_stack;

// Movs
void	ft_swap(t_stack **head, char id);
void	ft_swap_swap(t_stack **stack_a, t_stack **stack_b);
void	ft_pass_to(t_stack **stack_1, t_stack **stack_2, char id);
void	ft_rotate(t_stack **stack, char id);
void	ft_rotate_rotate(t_stack **stack_a, t_stack **stack_b);
void	ft_reverse_rotate(t_stack **stack, char id);
void	ft_reverse_rotate_rotate(t_stack **stack_a, t_stack **stack_b);

// List manipulation
t_stack	*store_integers_in_stack(int argc, char *argv[]);
t_stack	*store_integers_in_stack2(int len, int min, int max);
int		pop(t_stack **stack);
void	push(t_stack **stack, int data);
void	print_stack(t_stack *head);
int		check_vals(int argc, char *argv[]);
int		check_vals2(t_stack *head, int num);
//t_stack	*create_stack(int argc, char **argv, int i);

// sort_condictions
int		nr_movs(int pos, int stack_size);
int		total_movs(int needed_movs1, int needed_movs2);
int		total_movs_s(t_stack *stack, int pos_1, int pos_2);
int		total_movs_p(t_stack *src, t_stack *dst, int pos_1, int pos_2);

// sort.c
int		*best_stack_sa_mov(t_stack *stack, int *best_movs);
int		best_stack_pb_mov_aux(t_stack *src, t_stack *dst, int *pos_1, int *pos_2);
void	find_pos_1(t_stack *src, int *pos_1, int *cont);
int		*best_stack_pb_mov(t_stack *src,
		t_stack *dst, int *best_movs);
int		best_stack_pa_mov_aux(t_stack *src, t_stack *dst,
		int *pos_1, int *pos_2);
int		*best_stack_pa_mov(t_stack *src,
		t_stack *dst, int *best_movs);
int		order(t_stack **stack_a, t_stack **stack_b);
void		sort(t_stack **stack_1, t_stack **stack_2, int *cont);
void	sort_1(t_stack **stack_1, t_stack **stack_2, char *id_1);
void	sort_2(t_stack **stack_1, t_stack **stack_2, char *id_1);
void	sort_s_3(t_stack **stack, char id, int *cont);
void	sort_p(t_stack **stack_1, t_stack **stack_2, int fase);

// pa, pb & p_cont
char	 *pa_decisions(t_stack *src, t_stack *dst, int pos_1, int pos_2);
char	*pb_decisions(t_stack *src, t_stack *dst, int pos_1, int pos_2);
int		p_decisions_cont(t_stack *src, t_stack *dst, int pos_1, int pos_2);
void	p_decisison_cont_aux(int *pos_1, int *pos_2, int final_pos_2);
int		find_media(t_stack *stack);

// sa && sa_cont
char	*sa_decisions(t_stack *stack, int pos_1, int pos_2);
int		s_decisions_cont(t_stack *stack, int pos_1, int pos_2);

// find
int		find_smallest(t_stack *stack);
int		find_smaller_then(t_stack *head, int val, int smallest);
int		find_bigger_then(t_stack *head, int val, int biggest);
int		find_biggest(t_stack *stack);
int		find_pos(t_stack *head, int val);
int		find_val(t_stack *stack, int val);

// libft
long	ft_atoi(char *str);
char	*ft_itoa(int n);
size_t	ft_strlen(const char *a);
t_stack	*ft_lstnew(int content);
int		ft_lstsize(t_stack *lst);
char	*ft_strjoin(char *s1, char s2);

// ft_printf
int		ft_printf(const char *a, ...);

// visualizer
void	visualizer(t_stack **stack_a, t_stack **stack_b);
void	visualizer2(t_stack **stack_a, t_stack **stack_b);
void	p_movs(t_stack **stack_a, t_stack **stack_b, char *input);
void	ss_movs(t_stack **stack_a, t_stack **stack_b, char *input);
void	rr_movs(t_stack **stack_a, t_stack **stack_b, char *input);
void	rrr_movs(t_stack **stack_a, t_stack **stack_b, char *input);
void	print_tab(t_stack *stack_a, t_stack *stack_b);

#endif // !FT_PUSH_SWAP.H