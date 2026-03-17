/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_count.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nredouan <nredouan@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 15:02:40 by nredouan          #+#    #+#             */
/*   Updated: 2025/11/04 18:23:24 by nredouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_count(char *s)
{
	int	i;
	int	size_len;

	i = 0;
	size_len = 0;
	if (!s)
	{
		write (1, "(null)", 6);
		return (6);
	}
	while (s && s[i])
	{
		size_len += write(1, &s[i], 1);
		i++;
	}
	return (size_len);
}
