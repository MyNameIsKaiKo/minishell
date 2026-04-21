/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nredouan <nredouan@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 18:17:04 by jleray            #+#    #+#             */
/*   Updated: 2026/04/21 18:15:18 by jleray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

static t_env	*get_exp(char *arg, char *var, t_env *env_var, int *size)
{
	if (!ft_strcmp(var, "0"))
	{
		*size = ft_strlen(arg) - *size + ft_strlen(env_var->exec) + 1;
		return (env_var);
	}
	if (!ft_strcmp(var, "?"))
	{
		*size = ft_strlen(arg) - *size + ft_intlen(env_var->exit_status) + 1;
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

char	*expand_dquotes(char *result, int *i, t_env *env)
{
	(*i)++;
	while (result[*i] && result[*i] != '\"')
	{
		if (result[*i] == '$')
		{
			result = search_and_expand(result, i, env);
			continue ;
		}
		(*i)++;
	}
	return (result);
}

char	*search_and_expand(char *result, int *i, t_env *env)
{
	int	end;

	end = *i + 1;
	while (result[end] && ((ft_isalnum(result[end]) || result[end] == '_')
			|| result[end] == '?'))
		end++;
	if (end != *i + 1)
	{
		result = expand_var(result, *i, &end, env);
		if ((end - 1) > 0)
			*i = end - 1;
		else
			(*i)++;
	}
	else
		(*i)++;
	return (result);
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
			expand_copy(result, &i, env, var);
			j += (*end - start);
			*end = i;
		}
		result[i++] = arg[j++];
	}
	free(arg);
	free(var);
	return (result);
}
