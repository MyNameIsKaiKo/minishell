/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nredouan <nredouan@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 15:14:16 by nredouan          #+#    #+#             */
/*   Updated: 2025/11/03 17:01:38 by nredouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *to_print, ...)
{
	va_list	args;
	int		i;
	int		size;

	i = 0;
	size = 0;
	va_start(args, to_print);
	if (!to_print)
		return (-1);
	while (to_print[i])
	{
		if (to_print[i] == '%' && to_print[i + 1])
		{
			if (check_param("cspdiuxX%", to_print[i + 1]))
				size += what_print(to_print[i + 1], args);
			else
				size += ft_putchar_count(to_print[i]);
			i++;
		}
		else
			size += ft_putchar_count(to_print[i]);
		i++;
	}
	va_end(args);
	return (size);
}
