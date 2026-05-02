/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nredouan <nredouan@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 17:59:29 by nredouan          #+#    #+#             */
/*   Updated: 2026/04/13 17:01:05 by nredouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

static int	get_sign(const char *nptr, int *i)
{
	int	sign;

	sign = 1;
	if (nptr[*i] == '-')
	{
		sign *= -1;
		(*i)++;
	}
	else if (nptr[*i] == '+')
		(*i)++;
	return (sign);
}

int	ft_atoi(const char *nptr)
{
	int	sign;
	int	i;
	int	result;

	i = 0;
	result = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	sign = get_sign(nptr, &i);
	while (ft_isdigit(nptr[i]))
	{
		if (result > (INT_MAX - (nptr[i] - 48)) / 10)
		{
			if (sign == -1)
				return (0);
			else
				return (-1);
		}
		result = (result * 10) + nptr[i] - 48;
		i++;
	}
	return (result * sign);
}

long long	ft_atoll(const char *nptr)
{
	int			i;
	long long	sign;
	long long	result;

	i = 0;
	result = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	sign = get_sign(nptr, &i);
	while (ft_isdigit(nptr[i]))
	{
		if ((sign == 1 && (unsigned long long)result
				> ((unsigned long long)LLONG_MAX - (nptr[i] - 48)) / 10))
			return (-1);
		if (sign == -1 && (unsigned long long)result
			> (((unsigned long long)LLONG_MAX - (nptr[i] - 48) + 1) / 10))
			return (0);
		result = (result * 10) + nptr[i] - 48;
		i++;
	}
	return (result * sign);
}
