/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_var.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nredouan <nredouan@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 18:07:37 by nredouan          #+#    #+#             */
/*   Updated: 2026/04/07 11:54:45 by nredouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static t_env	*get_exp(char *arg, char *var, t_env *env_var, int *size)
{
	if (!ft_strcmp(var, "0"))
	{
		*size = ft_strlen(arg) - *size + ft_strlen(env_var->exec) + 1;
		return (env_var);
	}
	while (env_var && ft_strcmp(var, env_var->name))
		env_var = env_var->next;
	if (!env_var || !env_var->value)
		*size = ft_strlen(arg) - *size + 1;
	else
		*size = ft_strlen(arg) - *size + ft_strlen(env_var->value) + 1;
	return (env_var);
}

static void	expand_copy(char *result, int *i, t_env *env, bool is_exec)
{
	int	j;

	j = 0;
	if (!env || (env->name && !env->value))
		return ;
	if (!is_exec)
	{
		while (env && env->exec && env->exec[j])
		{
			result[*i] = env->exec[j];
			*i += 1;
			j++;
		}
	}
	else
	{
		while (env && env->value && env->value[j])
		{
			result[*i] = env->value[j];
			*i += 1;
			j++;
		}
	}
}

char	*expand_var(char *arg, int start, int *end, t_env *env)
{
	char	*result;
	char	*var;
	int		size;
	int		i;
	int		j;

	i = 0;
	j = 0;
	size = *end - start;
	var = ft_substr(arg, start + 1, *end - start - 1);
	env = get_exp(arg, var, env, &size);
	result = ft_calloc(size + 1, sizeof(char));
	while (i < size)
	{
		if (j == start)
		{
			expand_copy(result, &i, env, ft_strcmp(var, "0"));
			j += (*end - start);
			*end = i;
		}
		result[i++] = arg[j++];
	}
	free(arg);
	free(var);
	return (result);
}
