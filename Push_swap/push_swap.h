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
int		pop(t_stack **stack);
void	push(t_stack **stack, int data);
void	print_stack(t_stack *head);
//t_stack	*create_stack(int argc, char **argv, int i);

// sort_condictions
int		nr_movs(int pos, int stack_size);
int		total_movs(int needed_movs1, int needed_movs2);
int		total_movs_s(t_stack *stack, int pos_1, int pos_2);
int		total_movs_p(t_stack *src, t_stack *dst, int pos_1, int pos_2);

// sort.c
int		*best_stack_sa_mov(t_stack *stack, int *best_movs);
int		*best_stack_p_mov(t_stack *src, t_stack *dst, int *best_movs);
int		sort(t_stack **stack_1, t_stack **stack_2);
void	sort_1(t_stack **stack_1, t_stack **stack_2, int *sa, int *pb);
void	sort_2(t_stack **stack_1, t_stack **stack_2);
void	sort_3(t_stack **stack_1, t_stack **stack_2, char *id_1, char *id_2);
int		sort_4(t_stack **stack_1, t_stack **stack_2, int *pb);

// pa, pb & p_cont
char	*pa_decisions(int val_1, int val_2, int pos_1, int pos_2);
char	*pb_decisions(int val_1, int val_2, int pos_1, int pos_2);
int		p_decisions_cont(int val_1, int val_2, int pos_1, int pos_2);
void	p_decisison_cont_aux(int *pos_1, int *pos_2, int final_pos_2);

// sa && sa_cont
char	*s_decisions(t_stack *stack, int pos_1, int pos_2, char id);
int		s_decisions_cont(t_stack *stack, int pos_1, int pos_2);
void	aux_1(int *pos_1, int *pos_2, int *cont, t_stack *stack);
void	aux_2(int *pos_1, int *pos_2, t_stack *stack);
void	aux_3(int *pos_1, int *pos_2);

// find
int		find_smallest(t_stack *stack);
int		find_smaller_then(t_stack *stack, int val);
int		find_biggest(t_stack *stack);
int		find_pos(t_stack *head, int val);
int		find_val(t_stack *stack, int val);

// libft
long	ft_atoi(char *str);
char	*ft_itoa(int n);
size_t	ft_strlen(const char *a);
t_stack	*ft_lstnew(int content);
void	ft_lstadd_front(t_stack **lst, t_stack *to_add);
int		ft_lstsize(t_stack *lst);
t_stack	*ft_lstlast(t_stack *lst);
void	ft_lstadd_back(t_stack **lst, t_stack *to_add);
void	ft_lstdelone(t_stack *lst, void (*del)(void*));
void	ft_lstclear(t_stack **lst, void (*del)(void*));
void	ft_lstiter(t_stack *lst, void (*f)(void *));
t_stack	*ft_lstmap(t_stack *lst, void *(*f)(void *), void (*del)(void *));
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