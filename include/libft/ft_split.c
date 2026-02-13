/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleray <marvin@d42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 13:23:18 by jleray            #+#    #+#             */
/*   Updated: 2025/10/21 13:23:18 by jleray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_separator(char str, char c)
{
	if (c == str)
		return (1);
	if (str == '\0')
		return (1);
	return (0);
}

int	count_words(char *str, char sep)
{
	int	i;
	int	wordsnb;

	wordsnb = 0;
	i = 0;
	while (str[i])
	{
		if (!(is_separator(str[i], sep)) && is_separator(str[i + 1], sep))
			wordsnb++;
		i++;
	}
	return (wordsnb);
}

static char	*fill(const char *str, char sep)
{
	char	*word;
	int		i;
	int		len;

	len = 0;
	i = 0;
	if (!str)
		return (NULL);
	while (str[len] && !is_separator(str[len], sep))
		len++;
	word = malloc(sizeof(char) * (len + 1));
	if (!word)
		return (0);
	while (i < len)
	{
		word[i] = str[i];
		i++;
	}
	word[len] = '\0';
	return (word);
}

void	ft_free(char **str, int i)
{
	int	j;

	j = 0;
	while (j < i)
	{
		free(str[j]);
		j++;
	}
	free(str);
}

char	**ft_split(char const *s, char c)
{
	char	**output;
	int		i;

	i = 0;
	if (!s)
		return (0);
	output = ft_calloc(sizeof(char *), (count_words((char *)s, c) + 1));
	if (!output)
		return (0);
	while (*s)
	{
		while (*s && is_separator(*s, c))
			s++;
		if (!*s)
			break ;
		output[i++] = fill(s, c);
		if (!output[i - 1])
		{
			ft_free(output, i - 1);
			return (0);
		}
		while (*s && !is_separator(*s, c))
			s++;
	}
	return (output);
}
