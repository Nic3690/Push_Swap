/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfurlani <nfurlani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 11:34:35 by nfurlani          #+#    #+#             */
/*   Updated: 2023/10/10 19:23:02 by nfurlani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*elemento più piccolo dello stack*/
int	ft_min_index(t_list **stack)
{
	t_list	*temp;
	int		i;
	int		point;

	temp = (*stack);
	i = 0;
	point = 0;
	while (temp != NULL && temp->next != NULL)
	{
		if (temp->next->content < temp->content)
		{
			point = i + 1;
			break ;
		}
		temp = temp->next;
		i++;
	}
	return (point);
}

/*ordinamento array ordine crescente*/
void	ft_sort(t_list **stack, int point)
{
	int	i;

	i = point;
	if (point < ft_lstsize(stack) / 2)
	{
		while (i > 0)
		{
			rotate(stack);
			write(1, "ra\n", 3);
			i--;
		}
	}
	else
	{
		while (ft_lstsize(stack) - i > 0)
		{
			reverse(stack);
			write(1, "rra\n", 4);
			i++;
		}
	}
}

void	ft_check_sort_a(t_list **stack_a, int point)
{
	if (ft_lstsize(stack_a) / 2 < point)
	{
		while (point < ft_lstsize(stack_a) - 1)
		{
			reverse(stack_a);
			write(1, "rra\n", 4);
			point++;
		}
	}
	else
	{
		while (point >= 0)
		{
			rotate(stack_a);
			write(1, "ra\n", 3);
			point--;
		}
	}
}

void	ft_sort_a(t_list **stack_a)
{
	t_list	*temp;
	int		point;

	temp = (*stack_a);
	point = 0;
	while (temp != NULL && temp->next != NULL)
	{
		if (temp->content > temp->next->content)
			ft_check_sort_a(stack_a, point);
		temp = temp->next;
		point++;
	}
}
