/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nredouan <nredouan@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 19:07:19 by nredouan          #+#    #+#             */
/*   Updated: 2025/12/16 18:57:27 by nredouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	if (!s)
		return (0);
	if (s[0] == '\0')
		return (0);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		while (s[i] && s[i] != c)
			i++;
		if (s[i] != '\0')
			words++;
	}
	if (i != 0 && s[i] == '\0' && s[i - 1] != c)
		words++;
	return (words);
}

static int	size_word(char const *s, char c, int start)
{
	int	i;

	i = start;
	while (s[i] && s[i] != c)
		i++;
	return (i - start);
}

static void	free_str(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		words;
	int		start;
	char	**tab;

	i = -1;
	start = 0;
	words = count_words(s, c);
	tab = malloc((words + 1) * sizeof(char *));
	if (!tab)
		return (NULL);
	while (i++ < words - 1)
	{
		while (s[start] == c)
			start++;
		tab[i] = ft_substr(s, start, size_word(s, c, start));
		if (!tab[i])
		{
			free_str(tab);
			return (NULL);
		}
		start += size_word(s, c, start);
	}
	tab[i] = NULL;
	return (tab);
}
