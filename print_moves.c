/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfurlani <nfurlani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 18:49:00 by nfurlani          #+#    #+#             */
/*   Updated: 2023/10/10 18:38:30 by nfurlani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_fill_moves(int *array, int i, int move)
{
	int	n;
	int	j;

	n = 0;
	j = 0;
	while (array[j] != 0)
		j++;
	while (n < i)
	{
		array[n + j] = move;
		n++;
	}
}

void	ft_print_a(t_list **stack_a, int n, int *array)
{
	t_list	*temp;
	int		i;
	int		len;

	if (!(*stack_a))
		return ;
	temp = (*stack_a);
	i = 0;
	len = ft_lstsize(stack_a) / 2;
	while (temp != NULL)
	{
		if (temp->content == n)
		{
			if (i <= len)
				ft_fill_moves(array, i, RA);
			else
				ft_fill_moves(array, ft_lstsize(stack_a) - i, RRA);
		}
		temp = temp->next;
		i++;
	}
}

void	ft_print_b(t_list **stack_b, int n, int *array)
{
	t_list	*temp;
	int		i;
	int		len;

	if (!(*stack_b))
		return ;
	temp = (*stack_b);
	i = 0;
	len = ft_lstsize(stack_b) / 2;
	while (temp != NULL && temp->next != NULL)
	{
		if (ft_find_point_b(n, temp->content, temp->next->content))
		{
			if (i < len)
				ft_fill_moves(array, i + 1, RB);
			else
				ft_fill_moves(array, ft_lstsize(stack_b) - i, RRB);
		}
		temp = temp->next;
		i++;
	}
}

void	ft_apply_moves(t_list **stack_a, t_list **stack_b, int *array, int i)
{
	while (array[++i] != 0)
	{
		if (array[i] == SA)
			swap(stack_a);
		else if (array[i] == SB)
			swap(stack_b);
		else if (array[i] == SS)
			swap_both(stack_a, stack_b);
		else if (array[i] == PA)
			push(stack_a, stack_b);
		else if (array[i] == PB)
			push(stack_b, stack_a);
		else if (array[i] == RA)
			rotate(stack_a);
		else if (array[i] == RB)
			rotate(stack_b);
		else if (array[i] == RR)
			rotate_both(stack_a, stack_b);
		else if (array[i] == RRA)
			reverse(stack_a);
		else if (array[i] == RRB)
			reverse(stack_b);
		else if (array[i] == RRR)
			reverse_both(stack_a, stack_b);
	}
}

void	ft_print_moves(int *array, int i)
{
	while (array[++i] != 0)
	{
		if (array[i] == SA)
			write(1, "sa\n", 3);
		else if (array[i] == SB)
			write(1, "sb\n", 3);
		else if (array[i] == SS)
			write(1, "ss\n", 3);
		else if (array[i] == PA)
			write(1, "pa\n", 3);
		else if (array[i] == PB)
			write(1, "pb\n", 3);
		else if (array[i] == RA)
			write(1, "ra\n", 3);
		else if (array[i] == RB)
			write(1, "rb\n", 3);
		else if (array[i] == RR)
			write(1, "rr\n", 3);
		else if (array[i] == RRA)
			write(1, "rra\n", 4);
		else if (array[i] == RRB)
			write(1, "rrb\n", 4);
		else if (array[i] == RRR)
			write(1, "rrr\n", 4);
	}
}
