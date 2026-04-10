/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nredouan <nredouan@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 17:16:31 by nredouan          #+#    #+#             */
/*   Updated: 2026/04/10 15:48:31 by nredouan         ###   ########.fr       */
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

void	set_dash_pwd(t_env *pwd, t_env *old_pwd, t_env *env_var)
{
	char	*tmp;

	tmp = pwd->value;
	pwd->value = old_pwd->value;
	old_pwd->value = tmp;
	free(env_var->s_pwd);
	env_var->s_pwd = ft_strdup(pwd->value);
	env_var = env_var->next;
	while (env_var)
	{
		env_var->s_pwd = env_var->prev->s_pwd;
		env_var = env_var->next;
	}
	chdir(pwd->value);
}

void	set_dash_oldpwd(t_env *old_pwd, t_env *env_var)
{
	char	*tmp;

	tmp = old_pwd->value;
	old_pwd->value = getcwd(NULL, 0);
	if (!old_pwd->value)
	{
		ft_putendl_fd("cd: allocation error", 2);
		old_pwd->value = tmp;
	}
	else
	{
		free(env_var->s_pwd);
		env_var->s_pwd = tmp;
		env_var = env_var->next;
		while (env_var)
		{
			env_var->s_pwd = env_var->prev->s_pwd;
			env_var = env_var->next;
		}
		chdir(tmp);
	}
}

static char	*set_pwd_value(char *old_value, char *new_value, t_env *env_var)
{
	if (env_var)
	{
		free(env_var->s_pwd);
		env_var->s_pwd = ft_strdup(new_value);
		env_var = env_var->next;
		while (env_var)
		{
			env_var->s_pwd = env_var->prev->s_pwd;
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
	while (pwd && ft_strcmp("PWD", pwd->name))
		pwd = pwd->next;
	while (old_pwd && ft_strcmp("OLDPWD", old_pwd->name))
		old_pwd = old_pwd->next;
	if (!newpwd || !oldpwd)
	{
		perror("cd");
		free(newpwd);
		free(oldpwd);
		return ;
	}
	if (pwd && newpwd)
		pwd->value = set_pwd_value(pwd->value, newpwd, env_var);
	if (old_pwd && oldpwd)
		old_pwd->value = set_pwd_value(old_pwd->value, oldpwd, NULL);
}
