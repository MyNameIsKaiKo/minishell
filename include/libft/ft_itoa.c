/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleray <marvin@d42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 19:12:30 by jleray            #+#    #+#             */
/*   Updated: 2025/10/15 19:12:30 by jleray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	find_size(int nb)
{
	int	size_l;

	size_l = 0;
	if (nb == 0)
		size_l++;
	if (nb < 0)
		size_l++;
	while (nb != 0)
	{
		size_l++;
		nb = nb / 10;
	}
	return (size_l);
}

char	*fill_itoa(int n, int len, char *nb)
{
	while (len >= 0)
	{
		nb[len] = ((n % 10) + '0');
		n = n / 10;
		len--;
	}
	return (nb);
}

char	*ft_itoa(int n)
{
	char	*nb;
	int		len;

	len = find_size(n);
	nb = malloc(sizeof(char) * (len + 1));
	if (!nb)
		return (0);
	if (n == -2147483648)
		ft_strlcpy(nb, "-2147483648", 12);
	else if (n == 2147483647)
		ft_strlcpy(nb, "2147483647", 11);
	else if (n < 0)
	{
		n *= -1;
		nb = fill_itoa(n, len - 1, nb);
		nb[0] = '-';
	}
	else
		nb = fill_itoa(n, len - 1, nb);
	nb[len] = '\0';
	return (nb);
}
