/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_rules_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfurlani <nfurlani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 15:47:53 by nfurlani          #+#    #+#             */
/*   Updated: 2023/10/17 12:15:00 by nfurlani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

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

int	ft_check_error(char *argv)
{
	int		i;
	long	temp;

	i = 0;
	temp = 0;
	while (argv[i])
	{
		if (argv[i] == '-')
			i++;
		if (argv[i] < '0' || argv[i] > '9')
		{
			write(1, "Error\n", 6);
			return (1);
		}
		i++;
	}
	temp = ft_atoi(argv);
	if (temp > 2147483647 || temp < -2147483648)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	return (0);
}
