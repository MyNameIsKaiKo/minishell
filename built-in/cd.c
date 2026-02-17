/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nredouan <nredouan@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 15:54:18 by nredouan          #+#    #+#             */
/*   Updated: 2026/02/17 15:31:46 by nredouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"
#include <stdio.h>

static int	count_words(char const *s)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	if (!s || s[0] == '\0')
		return (0);
	while (s[i])
	{
		while (s[i] == ' ')
			i++;
		while (s[i] && s[i] != ' ')
			i++;
		if (s[i] != '\0')
			words++;
	}
	if (i != 0 && s[i] == '\0' && s[i - 1] != ' ')
		words++;
	return (words);
}

static char	*cd_parser(const char *arg)
{
	int		i;
	int		words;
	char	*path;

	i = 0;
	words = count_words(arg);
	if (words == 0)
		return (NULL);
	while (arg[i] == ' ')
		i++;
	path = ft_strdup((char *)&arg[i]);
	i = 0;
	while (path[i])
	{
		if (path[i] == ' ' && words == 1)
		{
			path[i] = '\0';
			break ;
		}
		i++;
	}
	return (path);
}

char	*cd(const char *arg, t_env *env_var)
{
	char	*str;
	char	*path;

	path = cd_parser(arg);
	if (count_words(path) <= 1)
	{
		if (!path)
		{
			str = getenv("HOME");
			if (!str)
				ft_putendl_fd("Error: HOME not set", 2);
			else
				chdir(str);
		}
		else
		{
			if (chdir(path) < 0)
				perror("Error");
		}
	}
	else
		ft_putendl_fd("Error: too many arguments", 2);
	change_prompt(env_var);
	str = build_prompt(env_var);
	return (str);
}
