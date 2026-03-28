/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nredouan <nredouan@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 15:39:18 by nredouan          #+#    #+#             */
/*   Updated: 2026/03/19 16:29:09 by nredouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../built_in.h"

static void	change_value(t_env *env_var, char *name, char *value)
{
	while (env_var && ft_strcmp(name, env_var->name))
		env_var = env_var->next;
	free(env_var->value);
	free(name);
	env_var->value = value;
}

static void	add_value(t_env *env_var, char *name, char *value)
{
	t_env	*env_head;
	char	*tmp;

	env_head = env_var;
	while (env_var && ft_strcmp(name, env_var->name))
		env_var = env_var->next;
	if (!env_var->value || !env_var->value[0])
	{
		change_value(env_head, name, value);
		return ;
	}
	tmp = env_var->value;
	env_var->value = ft_strjoin(env_var->value, value);
	if (!env_var->value)
	{
		ft_putstr_fd("export: allocation error\n", 2);
		env_var->value = value;
	}
	else
		free(value);
	free(name);
	free(tmp);
}

void	chose_value(t_env *env, char *name, char *value, char c)
{
	if (c == '+')
		add_value(env, name, value);
	else
		change_value(env, name, value);
}

static t_env	*exec_export(char *arg, t_env *env_var, int separator)
{
	char	*value;
	char	*name;

	name = set_name(arg, separator);
	value = set_value(arg, separator);
	if (!name || (arg[separator] == '=' && !value))
	{
		free_strings(name, value);
		return (env_var);
	}
	if (!env_var)
	{
		env_var = first_env(name, value);
		if (!env_var)
		{
			free_strings(name, value);
			return (NULL);
		}
	}
	else if (!env_search(name, env_var))
		add_env(env_var, name, value);
	else
		chose_value(env_var, name, value, arg[separator - 1]);
	return (env_var);
}

t_env	*export(char **args, t_env *env_var)
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
			if (!parser_export(args[i]))
				print_export_error(args[i], 0);
			else
			{
				while (args[i][j] && args[i][j] != '=')
					j++;
				env_var = exec_export(args[i], env_var, j);
			}
			j = 0;
			i++;
		}
	}
	return (env_var);
}
