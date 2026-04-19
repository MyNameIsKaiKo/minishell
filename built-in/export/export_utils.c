/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nredouan <nredouan@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 11:18:29 by nredouan          #+#    #+#             */
/*   Updated: 2026/04/18 15:05:32 by nredouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../built_in.h"

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

void	free_strings(char *name, char *value)
{
	free(name);
	free(value);
	ft_putstr_fd("T&J Shell: export: allocation error\n", 2);
}

bool	parser_export(char *arg)
{
	int	i;

	i = 0;
	if (ft_isdigit(arg[i]))
		return (false);
	while (arg[i])
	{
		if ((arg[i] == '=' || (arg[i] == '+'
					&& arg[i + 1] && arg[i + 1] == '=')) && i != 0)
			return (true);
		else if (!ft_isalnum(arg[i]) && arg[i] != '_')
			return (false);
		i++;
	}
	return (true);
}
