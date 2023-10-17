/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfurlani <nfurlani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 13:26:21 by nfurlani          #+#    #+#             */
/*   Updated: 2023/10/10 19:36:20 by nfurlani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_H
# define BONUS_H

# include <strings.h>
# include <string.h>
# include <fcntl.h>
# include <ctype.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_list
{
	struct s_list	*prev;
	int				content;
	struct s_list	*next;
}				t_list;

/*bonus.c*/
void	ft_check_moves_bonus(t_list **stack_a, t_list **stack_b);
int		ft_check_stack_bonus(t_list **stack_a);
void	ft_moves_bonus(t_list **stack_a, t_list **stack_b, char *str);
void	ft_free(t_list **stack);

/*utils_bonus.c*/
long	ft_atoi(const char *str);
int		ft_strcmp(const char *s1, const char *s2);
void	*ft_calloc(size_t nelem, size_t elsize);
void	ft_bzero(void *s, size_t n);
char	*get_next_line(int fd);

/*utils_lst_bonus.c*/
t_list	*ft_list(int argc, char **argv);
int		ft_lstsize(t_list **lst);
t_list	*ft_lstnew(int content);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);

/*rules_bonus.c*/
void	swap(t_list **stack);
void	rotate(t_list **stack);
void	reverse(t_list **stack);
void	push(t_list **stack_one, t_list **stack_two);

/*double_rules_bonus.c*/
void	swap_both(t_list **stack_a, t_list **stack_b);
void	rotate_both(t_list **stack_a, t_list **stack_b);
void	reverse_both(t_list **stack_a, t_list **stack_b);
int		ft_check_error(char *argv);

#endif
