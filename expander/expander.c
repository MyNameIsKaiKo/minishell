/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nredouan <nredouan@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 18:17:55 by jleray            #+#    #+#             */
/*   Updated: 2026/04/15 18:25:18 by nredouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../header.h"

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

static void	skip_dquote(char *result, int *i, int *j)
{
	(*j)++;
	while (result[*i + *j] && result[*i + *j] != '\"')
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
		if (result[i + j] && result[i + j] == '\"')
		{
			skip_dquote(result, &i, &j);
			continue ;
		}
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

char	*expander(char *args, t_env *env)
{
	char	*result;
	int		i;

	i = 0;
	result = ft_strdup(args);
	while (result[i])
	{
		if (result[i] == '\'' || result[i] == '\"')
		{
			if (result[i] == '\'')
				not_expand(result, &i);
			else if (result[i] == '\"')
				result = expand_dquotes(result, &i, env);
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
