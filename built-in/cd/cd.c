/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nredouan <nredouan@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 15:54:18 by nredouan          #+#    #+#             */
/*   Updated: 2026/03/12 16:44:04 by nredouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

// static int	count_words(char const *s)
// {
// 	int	i;
// 	int	words;

// 	i = 0;
// 	words = 0;
// 	if (!s || s[0] == '\0')
// 		return (0);
// 	while (s[i])
// 	{
// 		while (s[i] == ' ')
// 			i++;
// 		while (s[i] && s[i] != ' ')
// 			i++;
// 		if (s[i] != '\0')
// 			words++;
// 	}
// 	if (i != 0 && s[i] == '\0' && s[i - 1] != ' ')
// 		words++;
// 	return (words);
// }

// static char	*cd_parser(const char *arg)//plus besoin
// {
// 	int		i;
// 	int		words;
// 	char	*path;

// 	i = 0;
// 	words = count_words(arg);
// 	if (words == 0)
// 		return (NULL);
// 	while (arg[i] == ' ')
// 		i++;
// 	path = ft_strdup((char *)&arg[i]);
// 	i = 0;
// 	while (path[i])
// 	{
// 		if (path[i] == ' ' && words == 1)
// 		{
// 			path[i] = '\0';
// 			break ;
// 		}
// 		i++;
// 	}
// 	return (path);
// }

static void	cd_home(t_env *env_var)
{
	t_env	*home;

	home = env_var;
	while (home && ft_strncmp("HOME", home->name, 4))
		home = home->next;
	if (!home || !home->value)
	{
		ft_putendl_fd("cd: HOME not set", 2);
		return ;
	}
	else
	{
		change_pwd(env_var, ft_strdup(home->value), getcwd(NULL, 256));
		chdir(home->value);
	}
}

static void	cd_dash(t_env *old_pwd, char *oldpath)
{
	t_env	*pwd;

	pwd = old_pwd;
	free(oldpath);
	while (pwd && ft_strncmp("PWD", pwd->name, 3))
		pwd = pwd->next;
	while (old_pwd && ft_strncmp("OLDPWD", old_pwd->name, 6))
		old_pwd = old_pwd->next;
	if (!old_pwd || !old_pwd->value)
	{
		ft_putendl_fd("cd: OLDPWD not set", 2);
		return ;
	}
	else
	{
		if (pwd)
			set_pwd(pwd, old_pwd);
		else
			set_oldpwd(old_pwd);
	}
}

static bool	check_cd_args(char **args)
{
	int	i;

	i = 0;
	while (args && args[i])
		i++;
	if (i > 1)
		return (false);
	return (true);
}

/*This function change the directory and the prompt.*/
char	*cd(char **args, t_env *env_var)
{
	char	*oldpath;

	if (!check_cd_args(args))
		ft_putendl_fd("cd: too many arguments", 2);
	else
	{
		if (!args[0])
			cd_home(env_var);
		else
		{
			oldpath = getcwd(NULL, 256);
			if (!ft_strncmp(args[0], "-", 2))
				cd_dash(env_var, oldpath);
			else if (chdir(args[0]) < 0)
				return (path_error((char *)args[0], oldpath));
			else
				change_pwd(env_var, getcwd(NULL, 256), oldpath);
		}
	}
	return (build_prompt());
}
