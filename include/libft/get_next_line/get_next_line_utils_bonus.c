/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nredouan <nredouan@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 13:03:11 by nredouan          #+#    #+#             */
/*   Updated: 2025/12/20 17:43:21 by nredouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen2(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (i);
	while (str[i])
		i++;
	return (i);
}

int	find_line(const char *s)
{
	int		i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strjoin2(char *s1, char *s2)
{
	char	*dest;
	size_t	i;
	size_t	j;

	j = 0;
	i = ft_strlen2(s1) + ft_strlen2(s2);
	dest = malloc(i * (sizeof(char) + 1));
	i = 0;
	if (!dest)
		free(s1);
	if (!dest)
		return (NULL);
	while (s1 && s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		dest[i + j] = s2[j];
		j++;
	}
	dest[i + j] = '\0';
	free (s1);
	return (dest);
}
