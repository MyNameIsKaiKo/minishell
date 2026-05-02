/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_dash.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nredouan <nredouan@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 13:22:29 by nredouan          #+#    #+#             */
/*   Updated: 2026/04/19 14:26:14 by nredouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../built_in.h"

static void	spread_pwd(t_env *env_var)
{
	while (env_var)
	{
		if (env_var->prev)
			env_var->pwd_s = env_var->prev->pwd_s;
		env_var = env_var->next;
	}
}

int	set_dash_pwd(t_env *pwd, t_env *old_pwd, t_env *env_var)
{
	char	*tmp;

	tmp = pwd->value;
	pwd->value = old_pwd->value;
	if (chdir(pwd->value) < 0)
	{
		pwd->value = tmp;
		return (path_error(old_pwd->value, NULL));
	}
	old_pwd->value = tmp;
	free(env_var->pwd_s);
	env_var->pwd_s = ft_strdup(pwd->value);
	env_var = env_var->next;
	while (env_var)
	{
		env_var->pwd_s = env_var->prev->pwd_s;
		env_var = env_var->next;
	}
	return (0);
}

int	set_dash_oldpwd(t_env *old_pwd, t_env *env_var)
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
		if (chdir(tmp) < 0)
		{
			free(old_pwd->value);
			old_pwd->value = tmp;
			return (path_error(old_pwd->value, NULL));
		}
		free(env_var->pwd_s);
		env_var->pwd_s = tmp;
		spread_pwd(env_var);
	}
	return (0);
}
