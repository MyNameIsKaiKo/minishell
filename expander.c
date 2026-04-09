/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nredouan <nredouan@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 14:50:36 by nredouan          #+#    #+#             */
/*   Updated: 2026/04/09 16:03:02 by nredouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	skip_squote(char *result, int *i, int *j)
{
	(*j)++;
	while (result[*i + *j] && result[*i + *j] != '\'')
	{
		result[*i] = result[*i + *j];
		(*i)++;
	}
	(*j)++;
}

static char	*supp_quote(char *result)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (result[i + j])
	{
		while (result[i + j] && result[i + j] == '\"')
			j++;
		if (result[i + j] == '\'')
		{
			skip_squote(result, &i, &j);
			continue ;
		}
		if (result[i + j])
		{
			result[i] = result[i + j];
			i++;
		}
	}
	result[i] = '\0';
	return (result);
}

static void	not_expand(char *result, int *i)
{
	(*i)++;
	while (result[*i] && result[*i] != '\'')
		(*i)++;
	if (result[*i])
		(*i)++;
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
			not_expand(result, &i);
			continue ;
		}
		if (result[i] == '$')
		{
			result = search_and_expand(result, &i, env);
			continue ;
		}
		i++;
	}
	result = supp_quote(result);
	free(args);
	return (result);
}
