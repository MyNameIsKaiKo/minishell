/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmanip.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nredouan <nredouan@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 16:43:21 by nredouan          #+#    #+#             */
/*   Updated: 2026/02/06 18:13:25 by nredouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (src[i] && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = ft_strlen(dst);
	if (size <= j)
		return (ft_strlen(src) + size);
	while (src[i] && (i + j) < size - 1)
	{
		dst[j + i] = src[i];
		i++;
	}
	dst[j + i] = '\0';
	return (j + ft_strlen(src));
}

char	*ft_str_replace(char *modify, char to_replace, char replacer)
{
	char	*new;
	int		i;

	i = 0;
	new = malloc((ft_strlen(modify) + 1) * sizeof (char));
	if (!new)
		return (NULL);
	while (modify[i])
	{
		if (modify[i] == to_replace)
			new[i] = replacer;
		else
			new[i] = modify[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}
