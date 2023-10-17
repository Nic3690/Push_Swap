/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfurlani <nfurlani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 20:09:26 by nfurlani          #+#    #+#             */
/*   Updated: 2023/10/10 19:11:36 by nfurlani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	if (!s)
		return ;
	i = 0;
	while (i < n)
	{
		*(unsigned char *)(s + i) = 0;
		i++;
	}
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

void	*ft_calloc(size_t nelem, size_t elsize)
{
	void	*ptr;

	if (nelem == 0 || elsize == 0)
	{
		nelem = 1;
		elsize = 1;
	}
	ptr = malloc(nelem * elsize);
	if (ptr)
		ft_bzero(ptr, nelem * elsize);
	return (ptr);
}

long	ft_atoi(const char *str)
{
	int		i;
	long	sign;
	long	value;

	i = 0;
	sign = 1;
	value = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		value *= 10;
		value += str[i] - 48;
		i++;
	}
	value *= sign;
	return (value);
}

int	*ft_memmove(int *dst, const int *src, int min)
{
	int	i;

	i = 0;
	if (!dst && !src)
		return (0);
	while (i < min)
	{
		dst[i] = src[i];
		i++;
	}
	return (dst);
}
