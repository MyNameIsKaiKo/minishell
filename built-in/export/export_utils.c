/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nredouan <nredouan@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 11:18:29 by nredouan          #+#    #+#             */
/*   Updated: 2026/03/12 13:41:58 by nredouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

bool	check_export_args(char **args)
{
	int	i;

	i = 0;
	while (args[i])
		i++;
	if (i == 0)
		return (false);
	return (true);
}

bool	env_search(char *name, t_env *env_var)
{
	while (env_var && ft_strcmp(name, env_var->name))
		env_var = env_var->next;
	if (!env_var)
		return (false);
	return (true);
}

char	*set_name(char *arg, int i)
{
	if (arg[i - 1] == '+')
		return (ft_substr(arg, 0, i - 1));
	return (ft_substr(arg, 0, i));
}

char	*set_value(char *arg, int i)
{
	if (!arg[i])
		return (NULL);
	else if (arg[i] == '=')
	{
		if (!arg[i + 1])
			return (ft_strdup(""));
	}
	return (ft_substr(arg, i + 1, ft_strlen(arg)));
}

void	chose_value(t_env *env, char *name, char *value, char c)
{
	if (c == '+')
		add_value(env, name, value);
	else
		change_value(env, name, value);
}
