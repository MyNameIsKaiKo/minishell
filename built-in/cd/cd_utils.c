/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nredouan <nredouan@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 17:16:31 by nredouan          #+#    #+#             */
/*   Updated: 2026/03/19 16:29:41 by nredouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../built_in.h"

char	*path_error(char *path, char *oldpath)
{
	ft_putstr_fd("cd: ", 2);
	perror(path);
	free(oldpath);
	return (build_prompt());
}

void	set_dash_pwd(t_env *pwd, t_env *old_pwd)
{
	char	*tmp;

	tmp = pwd->value;
	pwd->value = old_pwd->value;
	old_pwd->value = tmp;
	chdir(pwd->value);
}

void	set_dash_oldpwd(t_env *old_pwd)
{
	char	*tmp;

	tmp = old_pwd->value;
	old_pwd->value = getcwd(NULL, 256);
	if (!old_pwd->value)
	{
		ft_putendl_fd("cd: allocation error", 2);
		old_pwd->value = tmp;
	}
	else
	{
		chdir(tmp);
		free(tmp);
	}
}

static char	*set_pwd_value(char *old_value, char *new_value)
{
	free(old_value);
	return (new_value);
}

void	change_pwd(t_env *old_pwd, char *newpwd, char *oldpwd)
{
	t_env	*pwd;

	pwd = old_pwd;
	while (pwd && ft_strcmp("PWD", pwd->name))
		pwd = pwd->next;
	while (old_pwd && ft_strcmp("OLDPWD", old_pwd->name))
		old_pwd = old_pwd->next;
	if (!newpwd || !oldpwd)
	{
		ft_putendl_fd("cd: allocation error", 2);
		if (!newpwd)
			free(pwd->value);
		if (!old_pwd)
			free(old_pwd->value);
		return ;
	}
	if (pwd && newpwd)
		pwd->value = set_pwd_value(pwd->value, newpwd);
	if (old_pwd && oldpwd)
		old_pwd->value = set_pwd_value(old_pwd->value, oldpwd);
}
