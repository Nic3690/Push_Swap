/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_moves.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfurlani <nfurlani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 10:51:35 by nfurlani          #+#    #+#             */
/*   Updated: 2023/10/10 19:23:50 by nfurlani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*esegue mosse iniziali*/
int	ft_first_move(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(stack_a) <= 5)
	{
		if (ft_lstsize(stack_a) == 2)
		{
			if ((*stack_a)->content > (*stack_a)->next->content)
			{
				swap(stack_a);
				write (1, "sa\n", 3);
			}
		}
		if (ft_lstsize(stack_a) == 3)
			ft_moves_three(stack_a);
		else if (ft_lstsize(stack_a) == 4)
			ft_moves_four(stack_a, stack_b);
		else if (ft_lstsize(stack_a) == 5)
			ft_moves_five(stack_a, stack_b);
		return (1);
	}
	else
		return (0);
}

void	ft_moves_three(t_list **stack)
{
	int	a;
	int	b;
	int	c;

	a = (*stack)->content;
	b = (*stack)->next->content;
	c = (*stack)->next->next->content;
	ft_check_three(stack, a, b, c);
}

void	ft_moves_four(t_list **stack_a, t_list **stack_b)
{
	int	a;
	int	b;
	int	c;
	int	n;

	push(stack_b, stack_a);
	write(1, "pb\n", 3);
	ft_moves_three(stack_a);
	a = (*stack_a)->content;
	b = (*stack_a)->next->content;
	c = (*stack_a)->next->next->content;
	n = (*stack_b)->content;
	if ((n > a) && (n < b))
	{
		rotate(stack_a);
		write(1, "ra\n", 3);
	}
	else if ((n > b) && (n < c))
	{
		reverse(stack_a);
		write(1, "rra\n", 4);
	}
	push(stack_a, stack_b);
	write(1, "pa\n", 3);
	ft_sort(stack_a, ft_min_index(stack_a));
}

void	ft_moves_five(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;
	int		b_content;
	int		i;

	push(stack_b, stack_a);
	write(1, "pb\n", 3);
	ft_moves_four(stack_a, stack_b);
	temp = (*stack_a);
	b_content = (*stack_b)->content;
	i = 0;
	while (temp != NULL && temp->next != NULL)
	{
		if (b_content > temp->content && b_content < temp->next->content)
		{
			ft_check_five(stack_a, i);
			break ;
		}
		temp = temp->next;
		i++;
	}
	push(stack_a, stack_b);
	write(1, "pa\n", 3);
	ft_sort(stack_a, ft_min_index(stack_a));
}
