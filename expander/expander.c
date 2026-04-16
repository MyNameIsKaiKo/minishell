/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nredouan <nredouan@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 18:17:55 by jleray            #+#    #+#             */
/*   Updated: 2026/04/16 23:38:47 by nredouan         ###   ########.fr       */
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

char	*expand_dquotes(char *result, int *i, t_env *env)
{
	(*i)++;
	while (result[*i] && result[*i] != '\"')
	{
		if (result[*i] == '$')
		{
			if (result[(*i) + 1] && (ft_isalnum(result[(*i) + 1])
					|| result[(*i) + 1] == ' ' || result[(*i) + 1] == '?'))
			{
				result = search_and_expand(result, i, env);
				continue ;
			}
			(*i)++;
			break ;
		}
		(*i)++;
	}
	return (result);
}

char	*supp_quote(char *result)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (result[i + j])
	{
		if (result[i + j] && (result[i + j] == '\"' || result[i + j] == '\''))
		{
			if (!check_unclose(result, result[i + j], i + j))
			{
				i++;
				continue ;
			}
			if (result[i + j] == '\"')
				skip_dquote(result, &i, &j);
			else
				skip_squote(result, &i, &j);
			continue ;
		}
		result[i] = result[i + j];
		i++;
	}
	result[i] = '\0';
	return (result);
}

char	*expander(char *args, t_env *env)
{
	int		i;

	i = 0;
	while (args[i])
	{
		if (args[i] == '\'' || args[i] == '\"' || args[i] == '$')
		{
			if (!check_unclose(args, args[i], i))
			{
				i++;
				continue ;
			}
			if (args[i] == '\'')
				not_expand(args, &i);
			else if (args[i] == '\"')
				args = expand_dquotes(args, &i, env);
			else if (args[i] == '$')
				args = search_and_expand(args, &i, env);
			continue ;
		}
		i++;
	}
	return (args);
}
