/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nredouan <nredouan@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 11:33:16 by nredouan          #+#    #+#             */
/*   Updated: 2025/12/20 15:25:28 by nredouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base(unsigned int nbr, char *base)
{
	unsigned int	base_size;
	int				write_size;

	write_size = 0;
	base_size = ft_strlen_bis(base);
	if (nbr >= base_size)
	{
		write_size += ft_putnbr_base(nbr / base_size, base);
		write_size += write(1, &base[nbr % base_size], 1);
	}
	else if (nbr < base_size)
		write_size += write (1, &base[nbr], 1);
	return (write_size);
}

int	ft_putnbr_base_ptr(unsigned long long nbr, char *base)
{
	unsigned long long	base_size;
	int					write_size;

	write_size = 0;
	base_size = ft_strlen_bis(base);
	if (nbr >= base_size)
	{
		write_size += ft_putnbr_base_ptr(nbr / base_size, base);
		write_size += write(1, &base[nbr % base_size], 1);
	}
	else if (nbr < base_size)
		write_size += write (1, &base[nbr], 1);
	return (write_size);
}
