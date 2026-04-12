/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsearch.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nredouan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 19:54:14 by nredouan          #+#    #+#             */
/*   Updated: 2025/10/18 17:49:20 by nredouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*occ;
	int		i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return (occ = (char *)&s[i]);
		i++;
	}
	if ((char)c == 0)
		return (occ = (char *)&s[i]);
	return (NULL);
}

char	*ft_strrchr(const char *s, int c)
{
	char	*occ;
	int		i;

	i = 0;
	occ = NULL;
	while (s[i])
	{
		if (s[i] == (char)c)
			occ = (char *)&s[i];
		i++;
	}
	if ((char)c == 0)
		return (occ = (char *)&s[i]);
	return (occ);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] == s2[i] && i < (n - 1))
	{
		if (s1[i] == '\0' || s2[i] == '\0')
		{
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		}
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t		i;
	size_t		j;

	i = 0;
	if (little[i] == '\0')
		return ((char *)big);
	while (big[i] && (i < len))
	{
		j = 0;
		while (big[i + j] == little[j] && little[j] && (i + j) < len)
			j++;
		if (!little[j])
			return ((char *)big + i);
		i++;
	}
	return (NULL);
}
