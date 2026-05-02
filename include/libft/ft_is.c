/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nredouan <nredouan@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 20:32:29 by nredouan          #+#    #+#             */
/*   Updated: 2025/10/25 17:22:18 by nredouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

int	ft_isdigit(int c)
{
	return ((c - '0' <= 9) && (c - '0' >= 0));
}

int	ft_isalnum(int c)
{
	return (ft_isalpha(c) == 1 || ft_isdigit(c) == 1);
}

int	ft_isascii(int c)
{
	return (c < 128 && c >= 0);
}

int	ft_isprint(int c)
{
	return ((c >= 32) && (c <= 126));
}
