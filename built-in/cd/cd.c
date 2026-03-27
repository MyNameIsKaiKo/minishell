/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nredouan <nredouan@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 15:54:18 by nredouan          #+#    #+#             */
/*   Updated: 2026/03/26 11:21:14 by nredouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../built_in.h"

static void	cd_home(t_env *env_var, t_silent_env *senv)
{
	t_env	*home;

	home = env_var;
	while (home && ft_strncmp("HOME", home->name, 4))
		home = home->next;
	if (!home || !home->value)
		ft_putendl_fd("cd: HOME not set", 2);
	else
	{
		change_pwd(env_var, ft_strdup(home->value), getcwd(NULL, 0), senv);
		chdir(home->value);
	}
}

static void	cd_dash(t_env *old_pwd, char *oldpath, t_silent_env *senv)
{
	t_env	*pwd;

	pwd = old_pwd;
	free(oldpath);
	while (pwd && ft_strcmp("PWD", pwd->name))
		pwd = pwd->next;
	while (old_pwd && ft_strcmp("OLDPWD", old_pwd->name))
		old_pwd = old_pwd->next;
	if (!old_pwd || !old_pwd->value)
	{
		ft_putendl_fd("cd: OLDPWD not set", 2);
		return ;
	}
	else
	{
		if (pwd)
			set_dash_pwd(pwd, old_pwd, senv);
		else
			set_dash_oldpwd(old_pwd);
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

char	*cd(char **args, t_env *env_var, t_silent_env *senv)
{
	char	*oldpath;

	if (!check_cd_args(args))
		ft_putendl_fd("cd: too many arguments", 2);
	else
	{
		if (!args[0])
			cd_home(env_var, senv);
		else
		{
			oldpath = getcwd(NULL, 0);
			if (!oldpath)
				oldpath = ft_strdup(senv->pwd);
			if (!ft_strncmp(args[0], "-", 2))
				cd_dash(env_var, oldpath, senv);
			else if (chdir(args[0]) < 0)
				return (path_error((char *)args[0], oldpath, senv));
			else
				change_pwd(env_var, getcwd(NULL, 0), oldpath, senv);
		}
	}
	return (build_prompt(senv));
}
