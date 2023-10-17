/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfurlani <nfurlani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 14:10:30 by nfurlani          #+#    #+#             */
/*   Updated: 2023/10/10 19:23:11 by nfurlani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_swap(t_list **stack_a, t_list **stack_b, int min, int n)
{
	int	i;
	int	*array;
	int	*temp;

	i = -1;
	temp = NULL;
	array = ft_calloc(min + 2, sizeof(int));
	if (!array)
		return ;
	ft_print_a(stack_a, n, array);
	if (*stack_b)
		ft_print_b(stack_b, n, array);
	array[min] = PB;
	array[min + 1] = 0;
	if (array[0] != PB)
	{
		temp = ft_calloc(min + 2, sizeof(int));
		temp = ft_memmove(temp, array, min + 2);
		ft_bzero(array, (min + 2) * sizeof(int));
		array = ft_double_moves(array, temp, 0, 0);
		free(temp);
	}
	ft_apply_moves(stack_a, stack_b, array, i);
	ft_print_moves(array, i);
	free(array);
}

void	ft_algorithm(t_list **stack_a, t_list **stack_b)
{
	int	size;

	size = ft_lstsize(stack_a) - 2;
	if (ft_first_move(stack_a, stack_b) == 0)
	{
		push(stack_b, stack_a);
		push(stack_b, stack_a);
		write(1, "pb\npb\n", 6);
		while (size > 5)
		{
			ft_plus(stack_a, stack_b);
			size--;
		}
		if (ft_lstsize(stack_a) == 4)
			ft_moves_four(stack_a, stack_b);
		else
		{
			if ((*stack_b)->content < (*stack_b)->next->content)
			{
				swap(stack_b);
				write(1, "sb\n", 3);
			}
			ft_moves_five(stack_a, stack_b);
		}
	}
}

void	ft_final_push(t_list **stack_a, t_list **stack_b, int n)
{
	t_list	*temp;
	int		i;

	temp = (*stack_a);
	i = 0;
	while (temp != NULL && temp->next != NULL)
	{
		if ((n > temp->content && n < temp->next->content)
			|| (temp->content > temp->next->content
				&& n < temp->content && n < temp->next->content))
		{
			while (i < ft_lstsize(stack_a) - 1)
			{
				reverse(stack_a);
				write(1, "rra\n", 4);
				i++;
			}
			break ;
		}
		temp = temp->next;
		i++;
	}
	push(stack_a, stack_b);
	write(1, "pa\n", 3);
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
	if (ft_check_number(&stack_a) == 1)
		return (-1);
	if (ft_check_stack_a(&stack_a) == 1)
		return (-1);
	ft_algorithm(&stack_a, &stack_b);
	while (stack_b)
		ft_final_push(&stack_a, &stack_b, stack_b->content);
	ft_sort_a(&stack_a);
	ft_free(&stack_a);
	ft_free(&stack_b);
}
