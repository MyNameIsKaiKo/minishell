/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_variable.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nredouan <nredouan@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 12:22:02 by nredouan          #+#    #+#             */
/*   Updated: 2026/02/19 13:45:56 by nredouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	init_env(t_env *env_var)
{
	char	cwd[256];

	getcwd(cwd, sizeof(cwd));
	env_var->pwd = ft_strdup(cwd);
	if (!getenv("OLDPWD"))
		env_var->old_pwd = NULL;
	else
		env_var->old_pwd = ft_strdup(cwd);
}

void	free_env(t_env *env_var)
{
	free(env_var->pwd);
	free(env_var->old_pwd);
}
