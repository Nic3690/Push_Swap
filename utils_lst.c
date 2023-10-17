/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfurlani <nfurlani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 18:42:40 by nfurlani          #+#    #+#             */
/*   Updated: 2023/10/10 18:38:51 by nfurlani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_list(int argc, char **argv)
{
	t_list	*stack;
	int		content;

	argv++;
	(void)argc;
	stack = NULL;
	while (*argv)
	{
		if (ft_check_error(*argv))
		{
			stack = NULL;
			return (NULL);
		}
		content = ft_atoi(*argv);
		ft_lstadd_back(&stack, ft_lstnew(content));
		argv++;
	}
	return (stack);
}

int	ft_lstsize(t_list **lst)
{
	t_list	*temp;
	int		count;

	count = 0;
	temp = (*lst);
	while (temp != 0)
	{
		temp = temp->next;
		count++;
	}
	temp = (*lst);
	return (count);
}

t_list	*ft_lstnew(int content)
{
	t_list	*new;

	new = (t_list *)ft_calloc(1, sizeof(t_list));
	if (new == NULL)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

t_list	*ft_lstlast(t_list *lst)
{
	while (lst)
	{
		if (lst->next == NULL)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	temp = ft_lstlast(*lst);
	temp->next = new;
}
