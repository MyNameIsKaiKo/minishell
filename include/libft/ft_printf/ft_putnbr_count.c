/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_count.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nredouan <nredouan@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 15:06:34 by nredouan          #+#    #+#             */
/*   Updated: 2025/11/04 18:25:12 by nredouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_count(int n)
{
	int	size_nbr;
	int	mod;

	size_nbr = 0;
	if (n < 0)
	{
		mod = -(n % 10) + 48;
		size_nbr += write(1, "-", 1);
		if (n < -9)
			size_nbr += ft_putnbr_count(-(n / 10));
	}
	if (n >= 10)
	{
		mod = (n % 10) + 48;
		size_nbr += ft_putnbr_count(n / 10);
	}
	if (n < 10 && n >= 0)
		mod = n + 48;
	size_nbr += write(1, &mod, 1);
	return (size_nbr);
}
