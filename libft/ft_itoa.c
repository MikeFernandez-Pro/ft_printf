/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mifernan <mifernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 18:11:09 by mifernan          #+#    #+#             */
/*   Updated: 2019/10/27 11:08:16 by mifernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		int_len(int n)
{
	int count;

	count = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

static void		*ft_memalloc(size_t size)
{
	size_t	i;
	char	*string;

	i = 0;
	if (!(string = (char*)malloc(sizeof(char) * (int)size)))
		return (NULL);
	while (i < size)
	{
		string[i] = 'x';
		i++;
	}
	return ((void*)string);
}

static char		*int_min(char *str)
{
	int		i;
	char	*i_min;

	i = 0;
	i_min = "-2147483648";
	while (i_min[i])
	{
		str[i] = i_min[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static char		*alloc(int n)
{
	char	*new;

	if (n >= 0)
	{
		if (!(new = (char*)ft_memalloc(sizeof(char) * (int_len(n) + 1))))
			return (NULL);
		new[int_len(n)] = '\0';
	}
	else if (n != -2147483648)
	{
		if (
		!(new = (char*)ft_memalloc(sizeof(char) * (int_len(n * -1) + 1 + 1))))
			return (NULL);
		new[0] = '-';
		new[int_len(n * -1) + 1] = '\0';
	}
	else if (n == -2147483648)
	{
		if (!(new = (char*)ft_memalloc(sizeof(char) * (12))))
			return (NULL);
		new = int_min(new);
	}
	else
		return (NULL);
	return (new);
}

char			*ft_itoa(int n)
{
	int		i;
	char	*new;

	i = 0;
	new = alloc(n);
	if (!(new) || n == -2147483648)
		return (new);
	if (n < 0)
		n *= -1;
	while (new[i])
		i++;
	i--;
	if (n == 0)
		new[0] = '0';
	else
	{
		while ((n > 0 && i >= 0) || (n < 0 && i > 1))
		{
			new[i] = n % 10 + '0';
			n /= 10;
			i--;
		}
	}
	return (new);
}
