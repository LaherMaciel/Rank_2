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

//Movs
void	ft_swap(t_stack **head, char id);
void	ft_swap_swap(t_stack **stack_a, t_stack **stack_b);
void	ft_pass_to(t_stack **stack_1, t_stack **stack_2, char id);
void	ft_rotate(t_stack **stack, char id);
void	ft_rotate_rotate(t_stack **stack_a, t_stack **stack_b);
void	ft_reverse_rotate(t_stack **stack, char id);
void	ft_reverse_rotate_rotate(t_stack **stack_a, t_stack **stack_b);

//List manipulation
t_stack	*store_integers_in_stack(int argc, char *argv[]);
int		pop(t_stack **stack);
void	push(t_stack **stack, int data);
void	print_stack(t_stack *head);
//t_stack	*create_stack(int argc, char **argv, int i);

//sort_condictions
void	rotate_up_or_down(t_stack **stack_1, t_stack **stack_2, char id);
void	rotate_up_or_down_biggest(t_stack **stack_1,
			t_stack **stack_2, char id, int val);
void	ft_smallest_on_top(t_stack **stack_1, int smallest, char id);

//find
int		find_smallest(t_stack *stack);
int		find_smaller_then(t_stack *stack, int val);
int		find_biggest(t_stack *stack);
int		find_val(t_stack *stack, int val);

//sort2
int		nr_movs(int val_pos, int stack_size);
int		if_dif_signs(int val_pos1, int val_pos2,
			int stack_size1, int stack_size2);
int		total_movs(int val_pos1, int val_pos2,
			int stack_size1, int stack_size2);
int		*best_stack_ord_mov(t_stack *stack, int *best_movs);
int		*best_stack_p1p2_mov(t_stack *stack_1,
			t_stack *stack_2, int *best_movs);


//libft
long	ft_atoi(char *str);
char	*ft_itoa(int n);
size_t	ft_strlen(const char *a);
t_stack	*ft_lstnew(int content);
void	ft_lstadd_front(t_stack **lst, t_stack *new);
int		ft_lstsize(t_stack *lst);
t_stack	**ft_lstlast(t_stack **lst);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
void	ft_lstdelone(t_stack *lst, void (*del)(void*));
void	ft_lstclear(t_stack **lst, void (*del)(void*));
void	ft_lstiter(t_stack *lst, void (*f)(void *));
t_stack	*ft_lstmap(t_stack *lst, void *(*f)(void *), void (*del)(void *));

//ft_printf
int		ft_printf(const char *a, ...);

//visualizer
void	visualizer(t_stack **stack_a, t_stack **stack_b,
			int argc, char *argv[]);
void	p_movs(t_stack **stack_a, t_stack **stack_b, char *input);
void	ss_movs(t_stack **stack_a, t_stack **stack_b, char *input);
void	rr_movs(t_stack **stack_a, t_stack **stack_b, char *input);
void	rrr_movs(t_stack **stack_a, t_stack **stack_b, char *input);
void	print_tab(t_stack *stack_a, t_stack *stack_b);

#endif // !FT_PUSH_SWAP.H