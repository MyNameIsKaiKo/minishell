/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nredouan <nredouan@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 15:39:18 by nredouan          #+#    #+#             */
/*   Updated: 2026/03/10 17:48:35 by nredouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

static bool	identifier(char *arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if ((arg[i] == '=' || (arg[i] == '+'
					&& arg[i + 1] && arg[i + 1] == '=')) && i != 0)
			return (true);
		else if (!ft_isalpha(arg[i]) && arg[i] != '_')
			return (false);
		i++;
	}
	return (true);
}

static void	change_value(t_env *env_var, char *name, char *value)
{
	size_t	size;

	size = ft_strlen(name);
	if (ft_strlen(env_var->name) > size)
		size = ft_strlen(env_var->name);
	while (env_var && ft_strncmp(name, env_var->name, size))
	{
		if (ft_strlen(env_var->name) > size)
			size = ft_strlen(env_var->name);
		env_var = env_var->next;
	}
	free(env_var->value);
	free(name);
	env_var->value = value;
}

static void	add_value(t_env *env_var, char *name, char *value)
{
	t_env	*env_head;
	size_t	size;
	char	*tmp;

	size = ft_strlen(name);
	env_head = env_var;
	if (ft_strlen(env_var->name) > size)
		size = ft_strlen(env_var->name);
	while (env_var && ft_strncmp(name, env_var->name, size))
	{
		if (ft_strlen(env_var->name) > size)
			size = ft_strlen(env_var->name);
		env_var = env_var->next;
	}
	if (!env_var->value || !env_var->value[0])
	{
		change_value(env_head, name, value);
		return ;
	}
	tmp = env_var->value;
	env_var->value = ft_strjoin(env_var->value, value);
	free(value);
	free(name);
	free(tmp);
}

static void	exec_export(char *arg, t_env *env_var)
{
	char	*value;
	char	*name;
	int		i;

	i = 0;
	if (!identifier(arg))
	{
		print_export_error(arg);
		return ;
	}
	while (arg[i] && arg[i] != '=')
		i++;
	name = set_name(arg, i);
	value = set_value(arg, i);
	if (!env_search(name, env_var))
		add_env(env_var, name, value);
	else
	{
		if (arg[i - 1] == '+')
			add_value(env_var, name, value);
		else
			change_value(env_var, name, value);
	}
}

void	export(char **args, t_env *env_var)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!check_export_args(args))
		print_export(env_var);
	else
	{
		while (args[i])
		{
			exec_export(args[i], env_var);
			i++;
		}
	}
}
