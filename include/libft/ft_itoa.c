/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nredouan <nredouan@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 17:39:24 by nredouan          #+#    #+#             */
/*   Updated: 2026/02/07 16:04:47 by nredouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*write_str(int nb, int size, int n)
{
	char	*result;
	int		i;

	i = 0;
	result = malloc(sizeof(char) * (size + 1));
	if (!result)
		return (NULL);
	while (i < size)
	{
		result[size - i - 1] = ((nb % 10) + 48);
		nb /= 10;
		i++;
	}
	if (n < 0)
		result[size - i] = '-';
	result[i] = '\0';
	return (result);
}

char	*ft_itoa(int n)
{
	int		size;
	int		nb;
	char	*result;

	size = 0;
	if (n == -2147483648)
	{
		result = ft_strdup("-2147483648");
		return (result);
	}
	if (n < 0)
	{
		nb = -n;
		size++;
	}
	else
		nb = n;
	while (n >= 10 || n <= -10)
	{
		n /= 10;
		size++;
	}
	size++;
	result = write_str(nb, size, n);
	return (result);
}
