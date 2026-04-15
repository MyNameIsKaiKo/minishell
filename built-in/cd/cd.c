/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nredouan <nredouan@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 15:54:18 by nredouan          #+#    #+#             */
/*   Updated: 2026/04/12 18:47:37 by jleray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../built_in.h"

static int	cd_home(t_env *env_var)
{
	t_env	*home;

	home = env_var;
	while (home && ft_strncmp("HOME", home->name, 4))
		home = home->next;
	if (!home || !home->value)
	{
		ft_putendl_fd("minishell: cd: HOME not set", 2);
		return (1);
	}
	if (!home->value[0])
		return (0);
	else
	{
		change_pwd(env_var, ft_strdup(home->value), getcwd(NULL, 0));
		chdir(home->value);
	}
	return (0);
}

static int	cd_dash(t_env *env_var, char *oldpath)
{
	t_env	*pwd;
	t_env	*old_pwd;

	pwd = env_var;
	old_pwd = env_var;
	free(oldpath);
	while (pwd && ft_strcmp("PWD", pwd->name))
		pwd = pwd->next;
	while (old_pwd && ft_strcmp("OLDPWD", old_pwd->name))
		old_pwd = old_pwd->next;
	if (!old_pwd || !old_pwd->value)
	{
		ft_putendl_fd("minishell: cd: OLDPWD not set", 2);
		return (1);
	}
	else
	{
		if (pwd)
			set_dash_pwd(pwd, old_pwd, env_var);
		else
			set_dash_oldpwd(old_pwd, env_var);
	}
	printf("%s\n", env_var->s_pwd);
	return (0);
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

int	cd(char **args, t_env *env_var)
{
	char	*oldpath;
	int		exit_status;

	exit_status = 0;
	if (!check_cd_args(args))
		ft_putendl_fd("minishell: cd: too many arguments", 2);
	else
	{
		if (!args[0])
			exit_status = cd_home(env_var);
		else
		{
			oldpath = ft_strdup(env_var->s_pwd);
			if (!ft_strncmp(args[0], "-", 2))
				exit_status = cd_dash(env_var, oldpath);
			else if (chdir(args[0]) < 0)
				return (path_error((char *)args[0], oldpath));
			else
				change_pwd(env_var, getcwd(NULL, 0), oldpath);
		}
	}
	free(*env_var->prompt);
	*env_var->prompt = build_prompt(env_var->s_pwd);
	return (exit_status);
}
