/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_printf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nredouan <nredouan@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 17:33:59 by nredouan          #+#    #+#             */
/*   Updated: 2025/11/29 13:17:17 by nredouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen_bis(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	check_param(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return (1);
		i++;
	}
	return (0);
}

int	what_print(char c, va_list args)
{
	int	size;

	size = 0;
	if (c == 'c')
		size += ft_putchar_count(va_arg(args, int));
	else if (c == 's')
		size += ft_putstr_count(va_arg(args, char *));
	else if (c == 'd' || c == 'i')
		size += ft_putnbr_count(va_arg(args, int));
	else if (c == 'u')
		size += ft_putnbr_base(va_arg(args, unsigned int), "0123456789");
	else if (c == 'x')
		size += ft_putnbr_base(va_arg(args, unsigned int), BASELOW);
	else if (c == 'X')
		size += ft_putnbr_base(va_arg(args, unsigned int), BASEUP);
	else if (c == 'p')
		size += ft_print_ptr(va_arg(args, unsigned long long), BASELOW);
	else
		size += ft_putchar_count(c);
	return (size);
}
