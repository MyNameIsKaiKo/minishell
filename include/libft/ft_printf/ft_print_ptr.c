/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nredouan <nredouan@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 19:54:50 by nredouan          #+#    #+#             */
/*   Updated: 2025/11/04 18:12:13 by nredouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_ptr(unsigned long long ptr, char *base)
{
	int					write_size;

	write_size = 0;
	if (!ptr)
	{
		write_size += write (1, "(nil)", 5);
		return (write_size);
	}
	else
	{
		write_size += write (1, "0x", 2);
		write_size += ft_putnbr_base_ptr(ptr, base);
	}
	return (write_size);
}
