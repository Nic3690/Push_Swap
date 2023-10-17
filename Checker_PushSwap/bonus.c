/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfurlani <nfurlani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 13:05:31 by nfurlani          #+#    #+#             */
/*   Updated: 2023/10/17 12:11:30 by nfurlani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

void	ft_check_moves_bonus(t_list **stack_a, t_list **stack_b)
{
	char	*str;

	str = get_next_line(0);
	while (str != 0)
	{
		ft_moves_bonus(stack_a, stack_b, str);
		free(str);
		str = get_next_line(0);
	}
}

int	ft_check_stack_bonus(t_list **stack_a)
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

void	ft_moves_bonus(t_list **stack_a, t_list **stack_b, char *str)
{
	if (ft_strcmp(str, "sa"))
		swap(stack_a);
	else if (ft_strcmp(str, "sb"))
		swap(stack_b);
	else if (ft_strcmp(str, "ss"))
		swap_both(stack_b, stack_a);
	else if (ft_strcmp(str, "pa"))
		push(stack_a, stack_b);
	else if (ft_strcmp(str, "pb"))
		push(stack_b, stack_a);
	else if (ft_strcmp(str, "ra"))
		rotate(stack_a);
	else if (ft_strcmp(str, "rb"))
		rotate(stack_b);
	else if (ft_strcmp(str, "rr"))
		rotate_both(stack_a, stack_b);
	else if (ft_strcmp(str, "rra"))
		reverse(stack_a);
	else if (ft_strcmp(str, "rrb"))
		reverse(stack_b);
	else if (ft_strcmp(str, "rrr"))
		reverse_both(stack_a, stack_b);
}

void	ft_free(t_list **stack)
{
	t_list	*temp;
	t_list	*head;

	if (!(*stack))
		return ;
	head = (*stack);
	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	if (argc < 2)
		return (-1);
	stack_a = ft_list(argc, argv);
	if (stack_a == NULL)
		return (-1);
	stack_b = NULL;
	ft_check_moves_bonus(&stack_a, &stack_b);
	if (ft_check_stack_bonus(&stack_a) == 1 && stack_b == NULL)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	ft_free(&stack_a);
	ft_free(&stack_b);
	return (0);
}
