/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nredouan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 14:20:44 by nredouan          #+#    #+#             */
/*   Updated: 2025/10/24 17:26:35 by nredouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write (fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s && s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}

void	ft_putendl_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s && s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
	write(fd, "\n", 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	int	mod;

	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	if (n < 0 && n != -2147483648)
	{
		write (fd, "-", 1);
		n *= -1;
	}
	if (n >= 10)
	{
		mod = (n % 10) + 48;
		ft_putnbr_fd(n / 10, fd);
		write(fd, &mod, 1);
	}
	if (n < 10 && n != -2147483648)
	{
		mod = n + 48;
		write (fd, &mod, 1);
	}
}
