/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfurlani <nfurlani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 14:11:51 by nfurlani          #+#    #+#             */
/*   Updated: 2023/10/10 19:27:50 by nfurlani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <strings.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <ctype.h>

typedef struct s_list
{
	struct s_list	*prev;
	int				content;
	struct s_list	*next;
}				t_list;

typedef enum e_moves
{
	SA = 1,
	SB = 2,
	SS = 3,
	PA = 4,
	PB = 5,
	RA = 6,
	RB = 7,
	RR = 8,
	RRA = 9,
	RRB = 10,
	RRR = 11,
}	t_moves;

/* push.c */
void	ft_push_swap(t_list **stack_a, t_list **stack_b, int min, int n);
void	ft_algorithm(t_list **stack_a, t_list **stack_b);
void	ft_final_push(t_list **stack_a, t_list **stack_b, int n);

/* check.c */
int		ft_check_number(t_list **stack);
int		ft_check_error(char *argv);
int		ft_check_stack_a(t_list **stack_a);
void	ft_check_three(t_list **stack, int a, int b, int c);
void	ft_check_five(t_list **stack, int i);

/* rules.c */
void	swap(t_list **stack);
void	rotate(t_list **stack);
void	reverse(t_list **stack);
void	push(t_list **stack_one, t_list **stack_two);

/* double_rules.c */
void	swap_both(t_list **stack_a, t_list **stack_b);
void	rotate_both(t_list **stack_a, t_list **stack_b);
void	reverse_both(t_list **stack_a, t_list **stack_b);
int		*ft_double_moves(int *ar, int *temp, int a, int b);

/* min_moves.c */
int		ft_first_move(t_list **stack_a, t_list **stack_b);
void	ft_moves_three(t_list **stack);
void	ft_moves_four(t_list **stack_a, t_list **stack_b);
void	ft_moves_five(t_list **stack_a, t_list **stack_b);

/* count_moves.c */
int		ft_moves_a(t_list **stack_a, int i);
int		ft_find_point_b(int n, int content, int next);
int		ft_moves_b(t_list **stack_b, int n);
void	ft_plus(t_list **stack_a, t_list **stack_b);

/* print_moves.c */
void	ft_fill_moves(int *array, int i, int move);
void	ft_print_a(t_list **stack_a, int n, int *array);
void	ft_print_b(t_list **stack_b, int n, int *array);
void	ft_apply_moves(t_list **stack_a, t_list **stack_b, int *array, int i);
void	ft_print_moves(int *array, int i);

/* sort.c */
int		ft_min_index(t_list **stack);
void	ft_sort(t_list **stack, int point);
void	ft_check_sort_a(t_list **stack_a, int point);
void	ft_sort_a(t_list **stack_a);

/*utils_lst.c*/
t_list	*ft_list(int argc, char **argv);
int		ft_lstsize(t_list **lst);
t_list	*ft_lstnew(int content);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);

/*utils.c*/
long	ft_atoi(const char *str);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
int		*ft_memmove(int *dst, const int *src, int min);
void	ft_free(t_list **stack);

#endif