/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_copy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nredouan <nredouan@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 14:38:58 by nredouan          #+#    #+#             */
/*   Updated: 2026/04/12 15:07:26 by nredouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

static int	copy_exec(char *result, t_env *env, int i)
{
	int	j;

	j = 0;
	while (env && env->exec && env->exec[j])
	{
		result[i] = env->exec[j];
		i += 1;
		j++;
	}
	return (i);
}

static int	copy_exit_status(char *result, t_env *env, int i)
{
	char	*exit_status;
	int		j;

	j = 0;
	exit_status = ft_itoa(env->exit_status);
	while (exit_status && exit_status && exit_status[j])
	{
		result[i] = exit_status[j];
		i += 1;
		j++;
	}
	free(exit_status);
	return (i);
}

static int	copy_env_value(char *result, t_env *env, int i)
{
	int	j;

	j = 0;
	while (env && env->value && env->value[j])
	{
		result[i] = env->value[j];
		i += 1;
		j++;
	}
	return (i);
}

void	expand_copy(char *result, int *i, t_env *env, char *var)
{
	if (!env || (env->name && !env->value))
		return ;
	if (!ft_strcmp(var, "0"))
		*i = copy_exec(result, env, *i);
	else if (!ft_strcmp(var, "?"))
		*i = copy_exit_status(result, env, *i);
	else
		*i = copy_env_value(result, env, *i);
}
