/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nredouan <nredouan@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 17:16:31 by nredouan          #+#    #+#             */
/*   Updated: 2026/03/10 17:43:33 by nredouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

char	*path_error(char *path, char *oldpath)
{
	ft_putstr_fd("cd: ", 2);
	perror(path);
	free(oldpath);
	return (build_prompt());
}

void	set_pwd(t_env *pwd, t_env *old_pwd)
{
	char	*tmp;

	tmp = pwd->value;
	pwd->value = old_pwd->value;
	old_pwd->value = tmp;
	chdir(pwd->value);
}

void	set_oldpwd(t_env *old_pwd)
{
	char	*tmp;

	tmp = old_pwd->value;
	old_pwd->value = getcwd(NULL, 256);
	chdir(tmp);
	free(tmp);
}

void	change_pwd(t_env *old_pwd, char *newpwd, char *oldpwd)
{
	t_env	*pwd;

	pwd = old_pwd;
	while (pwd && ft_strncmp("PWD", pwd->name, 3))
		pwd = pwd->next;
	while (old_pwd && ft_strncmp("OLDPWD", old_pwd->name, 6))
		old_pwd = old_pwd->next;
	if (pwd)
	{
		free(pwd->value);
		pwd->value = newpwd;
	}
	if (old_pwd)
	{
		free(old_pwd->value);
		old_pwd->value = oldpwd;
	}
}
