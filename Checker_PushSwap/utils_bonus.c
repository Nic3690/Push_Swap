/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfurlani <nfurlani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 16:04:54 by nfurlani          #+#    #+#             */
/*   Updated: 2023/10/10 19:26:57 by nfurlani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

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

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (0);
		else
			i++;
	}
	if (s1[i] != s2[i])
		return (0);
	return (1);
}

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

char	*get_next_line(int fd)
{
	int		i;
	int		byte;
	char	character;
	char	*buffer;

	i = 0;
	byte = read(fd, &character, 1);
	buffer = malloc(4);
	while ((byte > 0))
	{
		buffer[i] = character;
		if (character == '\n')
			break ;
		i++;
		byte = read(fd, &character, 1);
	}
	buffer[i] = '\0';
	if ((byte == -1 || !byte) || i == 0)
	{
		free(buffer);
		return (NULL);
	}
	return (buffer);
}
