/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nredouan <nredouan@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 14:50:36 by nredouan          #+#    #+#             */
/*   Updated: 2026/04/07 15:42:02 by nredouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static char	*supp_dquote(char *result)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (result[i + j])
	{
		while (result[i + j] && result[i + j] == '\"')
			j++;
		if (result[i + j])
		{
			result[i] = result[i + j];
			i++;
		}
	}
	result[i] = '\0';
	return (result);
}

static char	*not_expand(char *result, int *i)
{
	int	save_end;

	while (result[*i + 1] && result[*i + 1] != '\'')
	{
		result[*i] = result[*i + 1];
		(*i)++;
	}
	save_end = *i;
	while (result[*i + 1] && result[*i + 2])
	{
		result[*i] = result[*i + 2];
		(*i)++;
	}
	result[*i] = '\0';
	*i = save_end;
	return (result);
}

static char	*search_and_expand(char *result, int *i, t_env *env)
{
	int	end;

	end = *i + 1;
	while (result[end]
		&& (ft_isalnum(result[end]) || result[end] == '_'))
		end++;
	if (end != *i + 1)
	{
		result = expand_var(result, *i, &end, env);
		*i = end - 1;
	}
	return (result);
}

char	*expander(char *args, t_env *env)
{
	char	*result;
	int		i;

	i = 0;
	result = ft_strdup(args);
	while (result[i])
	{
		if (result[i] == '\'')
		{
			result = not_expand(result, &i);
			continue ;
		}
		if (result[i] == '$')
		{
			result = search_and_expand(result, &i, env);
			continue ;
		}
		i++;
	}
	result = supp_dquote(result);
	free(args);
	return (result);
}


