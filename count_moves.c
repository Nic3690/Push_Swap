/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfurlani <nfurlani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 18:13:34 by nfurlani          #+#    #+#             */
/*   Updated: 2023/10/10 19:20:20 by nfurlani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*calcolo mosse di a*/
int	ft_moves_a(t_list **stack_a, int i)
{
	int	len;
	int	moves;

	len = ft_lstsize(stack_a) / 2;
	if (i <= len)
		moves = i;
	else
		moves = ft_lstsize(stack_a) - i;
	return (moves);
}

/*verifica push b*/
int	ft_find_point_b(int n, int content, int next)
{
	if (((n < content) && (n > next)) || ((n > content) && (n > next)
			&& (next > content)) || ((n < content) && (n < next)
			&& (content < next)))
		return (1);
	return (0);
}

/*calcolo mosse b secondo content(n)*/
int	ft_moves_b(t_list **stack_b, int n)
{
	t_list	*temp;
	int		i;
	int		len;
	int		moves;

	if (!(*stack_b))
		return (0);
	temp = (*stack_b);
	i = 0;
	len = (ft_lstsize(stack_b) / 2);
	while (temp != NULL && temp->next != NULL)
	{
		if (ft_find_point_b(n, temp->content, temp->next->content))
		{
			if (i < len)
				return (i + 1);
			else
				return (ft_lstsize(stack_b) - i - 1);
		}
		else
			moves = 0;
		temp = temp->next;
		i++;
	}
	return (moves);
}

/*mosse minime a + b*/
void	ft_plus(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;
	int		moves;
	int		min;
	int		n;
	int		i;

	if (!(*stack_a))
		return ;
	temp = (*stack_a);
	min = 2147483647;
	i = 0;
	while (temp != NULL)
	{
		moves = ft_moves_a(stack_a, i)
			+ ft_moves_b(stack_b, temp->content);
		if (moves < min)
		{
			min = moves;
			n = temp->content;
		}
		temp = temp->next;
		i++;
	}
	ft_push_swap(stack_a, stack_b, min, n);
}
