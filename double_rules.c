/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_rules.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfurlani <nfurlani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 19:09:27 by nfurlani          #+#    #+#             */
/*   Updated: 2023/10/10 18:38:24 by nfurlani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_both(t_list **stack_a, t_list **stack_b)
{
	int	temp_a;
	int	temp_b;

	if (!(*stack_a) || !(*stack_b))
		return ;
	temp_a = (*stack_a)->content;
	temp_b = (*stack_b)->content;
	(*stack_a)->content = (*stack_a)->next->content;
	(*stack_b)->content = (*stack_b)->next->content;
	(*stack_a)->next->content = temp_a;
	(*stack_b)->next->content = temp_b;
}

void	rotate_both(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp_a;
	t_list	*temp_b;
	t_list	*head_a;
	t_list	*head_b;

	if (!(*stack_a) || !(*stack_b))
		return ;
	head_a = (*stack_a);
	head_b = (*stack_b);
	temp_a = (*stack_a);
	temp_b = (*stack_b);
	(temp_a)->next->prev = NULL;
	(temp_b)->next->prev = NULL;
	while ((temp_a)->next != NULL)
		(temp_a) = (temp_a)->next;
	while ((temp_b)->next != NULL)
		(temp_b) = (temp_b)->next;
	(*stack_a) = head_a->next;
	(*stack_b) = head_b->next;
	(head_a)->prev = temp_a;
	(head_b)->prev = temp_b;
	temp_a->next = (head_a);
	temp_b->next = (head_b);
	head_a->next = NULL;
	head_b->next = NULL;
}

void	reverse_both(t_list **stack_a, t_list **stack_b)
{
	t_list	*last;
	t_list	*temp;

	if (!(*stack_a) || !(*stack_b))
		return ;
	temp = (*stack_a);
	last = (*stack_a);
	while (last->next != NULL)
	{
		temp = last;
		last = last->next;
	}
	last->next = (*stack_a);
	(*stack_a) = last;
	temp->next = NULL;
	temp = (*stack_b);
	last = (*stack_b);
	while (last->next != NULL)
	{
		temp = last;
		last = last->next;
	}
	last->next = (*stack_b);
	(*stack_b) = last;
	temp->next = NULL;
}

//ar è l'array di mosse, a è l'indice di A e b è l'indice di B
int	*ft_double_moves(int *ar, int *temp, int a, int b)
{
	int	n;

	n = 0;
	while (temp[b] == RA || temp[b] == RRA)
		b++;
	while ((temp[a] == RA || temp[a] == RRA) && (temp[b] != PB))
	{
		if (temp[a] == RA && temp[b] == RB)
			ar[n++] = RR;
		else if (temp[a] == RRA && temp[b] == RRB)
			ar[n++] = RRR;
		else
		{
			ar[n++] = temp[a];
			ar[n++] = temp[b];
		}
		a++;
		b++;
	}
	while (temp[a] == RA || temp[a] == RRA)
		ar[n++] = temp[a++];
	while (temp[b] != PB)
		ar[n++] = temp[b++];
	ar[n] = PB;
	return (ar);
}
