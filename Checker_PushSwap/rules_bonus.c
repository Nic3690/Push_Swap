/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfurlani <nfurlani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 15:44:50 by nfurlani          #+#    #+#             */
/*   Updated: 2023/10/07 15:45:58 by nfurlani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

void	swap(t_list **stack)
{
	int	temp;

	if (!(*stack)->next)
		return ;
	temp = (*stack)->content;
	(*stack)->content = (*stack)->next->content;
	(*stack)->next->content = temp;
}

/*primo diventa ultimo*/
void	rotate(t_list **stack)
{
	t_list	*temp;
	t_list	*head;

	if (!(*stack)->next)
		return ;
	head = (*stack);
	temp = (*stack);
	(temp)->next->prev = NULL;
	while ((temp)->next != NULL)
		(temp) = (temp)->next;
	(*stack) = head->next;
	(head)->prev = temp;
	temp->next = (head);
	head->next = NULL;
}

/*ultimo diventa primo*/
void	reverse(t_list **stack)
{
	t_list	*temp;
	t_list	*last;

	if (!(*stack)->next)
		return ;
	temp = (*stack);
	last = (*stack);
	while (last->next != NULL)
	{
		temp = last;
		last = last->next;
	}
	last->next = (*stack);
	(*stack) = last;
	temp->next = NULL;
}

void	push(t_list **stack_one, t_list **stack_two)
{
	t_list	*temp;

	if (!(*stack_two))
		return ;
	temp = (*stack_two);
	(*stack_two) = (*stack_two)->next;
	temp->next = (*stack_one);
	(*stack_one) = temp;
}
