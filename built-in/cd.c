/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nredouan <nredouan@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 15:54:18 by nredouan          #+#    #+#             */
/*   Updated: 2026/02/19 13:36:18 by nredouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

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

static void	cd_home(t_env *env_var)
{
	char	*str;
	
	str = getenv("HOME");
	if (!str)
	{
		ft_putendl_fd("cd: HOME not set", 2);
		return ;
	}
	else
		chdir(str);
	change_prompt(env_var);
}

static void	cd_dash(t_env *env_var)
{
	char *str;
	
	if (!env_var->old_pwd)
	{
		ft_putendl_fd("cd: OLDPWD not set", 2);
		return ;
	}
	str = env_var->pwd;
	env_var->pwd = env_var->old_pwd;
	env_var->old_pwd = str;
	chdir(env_var->pwd);
}

char	*cd(const char *arg, t_env *env_var)
{
	char	*path;

	path = cd_parser(arg);
	if (count_words(path) <= 1)
	{
		if (!path)
			cd_home(env_var);
		else
		{
			if (!ft_strncmp(path, "-", 2))
				cd_dash(env_var);
			else if (chdir(path) < 0)
			{
				ft_putstr_fd("cd: ", 2);
				perror(path);
			}
			else
				change_prompt(env_var);
		}
	}
	else
		ft_putendl_fd("cd: too many arguments", 2);
	free(path);
	return (build_prompt(env_var));
}
