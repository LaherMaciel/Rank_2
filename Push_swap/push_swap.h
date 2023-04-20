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

// Moviments moviments.c && moviments2.c
void	ft_swap(t_stack **head, char id);
void	ft_swap_swap(t_stack **stack_a, t_stack **stack_b);
void	ft_pass_to(t_stack **src, t_stack **dest, char id);
void	ft_rotate(t_stack **stack, char id);
void	ft_rotate_rotate(t_stack **stack_a, t_stack **stack_b);
void	ft_reverse_rotate(t_stack **stack, char id);
void	ft_reverse_rotate_rotate(t_stack **stack_a, t_stack **stack_b);

//ERROR CHECKS error_managemant.c
int		contains_this_values(t_stack *head, int num);
int		contains_duplicate_values(t_stack *head);
int		check_vals(int argc, char *argv[]);
int		check_stack(t_stack *stack);
char	*error_check(t_stack *stack);
int		check_order_ok(t_stack *stack);

// List manipulation stack_work.c
int		pop(t_stack **stack);
void	push(t_stack **stack, int data);
void	print_stack(t_stack *head);
t_stack	*store_integers_in_stack3(int argc, char *argv[]);

// all the find functions find.c && find2.c
int		find_smallest(t_stack *stack);
int		find_bigger_then(t_stack *head, int val, int biggest);
int		find_biggest(t_stack *stack);
int		find_pos(t_stack *head, int val);
int		find_val(t_stack *stack, int val);
int		find_media(t_stack *stack);
int		find_above_media(t_stack *stack, int cont1, int cont2);

// sort_condictions sort_conditions.c
int		nr_movs(int pos, int stack_size);
int		total_movs_p(t_stack *src, t_stack *dst, int pos_1, int pos_2);
int		best_stack_pa_mov_aux(t_stack *src, t_stack *dst,
			int *pos_1, int *pos_2);
int		*best_stack_pa_mov(t_stack *src,
			t_stack *dst, int *best_movs);

// p_decisions.c
char	*p_decisions(t_stack *src, t_stack *dst, int pos_1, int pos_2);
int		p_decisions_cont(t_stack *src, t_stack *dst, int pos_1, int pos_2);
void	p_decisison_cont_aux(int *pos_1, int *pos_2, int final_pos_2);

// sort.c
void	sort(t_stack **stack_1, t_stack **stack_2, int *cont);
void	sort_s_3(t_stack **stack, char id, int *cont);
void	sort_p(t_stack **stack_1, t_stack **stack_2);
void	sorting(t_stack **stack_a, t_stack **stack_b, char *id_1);

// libft functions
long	ft_atoi(char *str);
char	*ft_itoa(int n);
size_t	ft_strlen(const char *a);
char	*ft_strchr(const char *str, int c);
int		ft_strncmp(char *str1, const char *str2, size_t n);
t_stack	*ft_lstnew(int content);
int		ft_lstsize(t_stack *lst);
int		ft_isdigit(int i);
int		ft_isprint(int a);

// ft_printf function
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