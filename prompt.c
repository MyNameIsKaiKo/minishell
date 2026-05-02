/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nredouan <nredouan@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 15:18:50 by nredouan          #+#    #+#             */
/*   Updated: 2026/04/29 17:05:15 by nredouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static char	*do_the_join(char *dest, const char *src, int start)
{
	size_t	i;

	i = 0;
	while (src && src[i])
	{
		dest[start + i] = src[i];
		i++;
	}
	return (dest);
}

char	*ft_strjoinjoin(const char *s1, const char *s2, const char *s3)
{
	char	*dest;
	size_t	size1;
	size_t	size2;
	size_t	size3;

	if (!s1 || !s2 || !s3)
		return (NULL);
	size1 = ft_strlen(s1);
	size2 = ft_strlen(s2);
	size3 = ft_strlen(s3);
	dest = ft_calloc(size1 + size2 + size3 + 1, sizeof(char));
	if (!dest)
		return (NULL);
	dest = do_the_join(dest, s1, 0);
	dest = do_the_join(dest, s2, size1);
	dest = do_the_join(dest, s3, size1 + size2);
	dest[size1 + size2 + size3] = '\0';
	return (dest);
}

char	*build_prompt(char *pwd)
{
	char	*prompt;

	prompt = ft_strjoinjoin("\001\033[35m\002<T&J Shell>", pwd,
			"$ \001\033[0m\002");
	if (!prompt)
		return (NULL);
	return (prompt);
}
