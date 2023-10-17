/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfurlani <nfurlani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 19:15:49 by nfurlani          #+#    #+#             */
/*   Updated: 2023/10/17 12:14:01 by nfurlani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_number(t_list **stack)
{
	t_list	*temp;
	t_list	*head;

	temp = (*stack)->next;
	head = (*stack);
	while ((*stack)->next != NULL)
	{
		while (temp != NULL)
		{
			if (temp->content == (*stack)->content)
			{
				write (1, "Error\n", 6);
				return (1);
			}
			temp = temp->next;
		}
		(*stack) = (*stack)->next;
		temp = (*stack)->next;
	}
	(*stack) = head;
	return (0);
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

int	ft_check_stack_a(t_list **stack_a)
{
	t_list	*temp;

	temp = (*stack_a);
	while (temp != NULL && temp->next != NULL)
	{
		if (temp->content > temp->next->content)
			return (0);
		temp = temp->next;
	}
	return (1);
}

void	ft_check_three(t_list **stack, int a, int b, int c)
{
	if ((b > a) && (b > c))
	{
		reverse(stack);
		write(1, "rra\n", 4);
		if ((a < b) && (a < c))
		{
			swap(stack);
			write(1, "sa\n", 3);
		}
	}
	else if ((a > b) && (a > c))
	{
		rotate(stack);
		write(1, "ra\n", 3);
		if ((c < b) && (c < a))
		{
			swap(stack);
			write(1, "sa\n", 3);
		}
	}
	else if ((b < a) && (b < c))
	{
		swap(stack);
		write(1, "sa\n", 3);
	}
}

void	ft_check_five(t_list **stack, int i)
{
	if (i == 0)
	{
		rotate(stack);
		write(1, "ra\n", 3);
	}
	else if (i == 1)
	{
		rotate(stack);
		rotate(stack);
		write(1, "ra\nra\n", 6);
	}
	else if (i == 2)
	{
		reverse(stack);
		write(1, "rra\n", 4);
	}
}
