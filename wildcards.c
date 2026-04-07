/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcards.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nredouan <nredouan@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 16:14:27 by nredouan          #+#    #+#             */
/*   Updated: 2026/03/28 14:48:38 by nredouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include "header.h"

static int	count_obj(void)
{
	DIR				*dirp;
	struct dirent	*names;
	int				i;

	i = 0;
	dirp = opendir(".");
	if (!dirp)
		return (0);
	names = readdir(dirp);
	while (names)
	{
		names = readdir(dirp);
		i++;
	}
	closedir(dirp);
	return (i);
}

static bool	wild_check(char *pattern, char *str, int index_p, int index_s)
{
	if (str[0] == '.' && pattern[0] != '.')
		return (false);
	if (!pattern[index_p] && !str[index_s])
		return (true);
	if (pattern[index_p] == str[index_s])
		return (wild_check(pattern, str, index_p + 1, index_s + 1));
	if (pattern[index_p] == '*')
	{
		if (wild_check(pattern, str, index_p + 1, index_s))
			return (true);
		if (str[index_s])
			return (wild_check(pattern, str, index_p, index_s + 1));
	}
	return (false);
}

static char	**recup_names(char *pattern, char **result, int max)
{
	DIR				*dirp;
	struct dirent	*names;
	int				i;

	i = 0;
	dirp = opendir(".");
	while (i < max)
	{
		names = readdir(dirp);
		if (!names)
			break ;
		if (wild_check(pattern, names->d_name, 0, 0))
		{
			result[i] = ft_strdup(names->d_name);
			if (!result[i])
			{
				free_str(result);
				return (NULL);
			}
			i++;
		}
	}
	result[i] = NULL;
	closedir(dirp);
	return (result);
}

char	**wildcards(char *pattern)
{
	char			**result;
	int				i;
	int				j;

	j = 0;
	i = count_obj();
	if (i == 0)
		return (NULL);
	result = malloc((i + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	result = recup_names(pattern, result, i);
	if (!result)
		return (NULL);
	if (!result[0])
	{
		result[0] = ft_strdup(pattern);
		result[1] = NULL;
	}
	return (result);
}
