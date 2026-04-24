/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nredouan <nredouan@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 17:16:31 by nredouan          #+#    #+#             */
/*   Updated: 2026/04/24 17:43:52 by nredouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../built_in.h"

int	path_error(char *path, char *oldpath)
{
	ft_putstr_fd("cd: ", 2);
	perror(path);
	free(oldpath);
	return (1);
}

static void	cd_error(char *newpwd, char *oldpwd)
{
	perror("cd");
	free(newpwd);
	free(oldpwd);
}

static char	*set_pwd_value(char *old_value, char *new_value, t_env *env_var)
{
	if (env_var)
	{
		free(env_var->pwd_s);
		env_var->pwd_s = ft_strdup(new_value);
		env_var = env_var->next;
		while (env_var)
		{
			env_var->pwd_s = env_var->prev->pwd_s;
			env_var = env_var->next;
		}
	}
	free(old_value);
	return (new_value);
}

void	change_pwd(t_env *env_var, char *newpwd, char *oldpwd)
{
	t_env	*pwd;
	t_env	*old_pwd;

	pwd = env_var;
	old_pwd = env_var;
	while (pwd && pwd->name && ft_strcmp("PWD", pwd->name))
		pwd = pwd->next;
	while (old_pwd && old_pwd->name && ft_strcmp("OLDPWD", old_pwd->name))
		old_pwd = old_pwd->next;
	if (!newpwd || !oldpwd)
	{
		cd_error(newpwd, oldpwd);
		return ;
	}
	if (!pwd || !pwd->name)
		free(set_pwd_value(NULL, newpwd, env_var));
	else
		pwd->value = set_pwd_value(pwd->value, newpwd, env_var);
	if (!old_pwd || !old_pwd->name)
		free(oldpwd);
	else
		old_pwd->value = set_pwd_value(old_pwd->value, oldpwd, NULL);
}
