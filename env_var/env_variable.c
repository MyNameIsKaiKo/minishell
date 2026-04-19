/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_variable.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nredouan <nredouan@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 12:22:02 by nredouan          #+#    #+#             */
/*   Updated: 2026/04/19 13:38:41 by nredouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env_var.h"

/*Free every node of the the linked list.*/
void	free_env(t_env *env_var)
{
	t_env	*tmp;

	if (!env_var)
		return ;
	free(env_var->pwd_s);
	free(env_var->exec);
	free(*env_var->prompt);
	while (env_var)
	{
		free(env_var->name);
		if (env_var->value)
			free(env_var->value);
		tmp = env_var;
		env_var = env_var->next;
		free(tmp);
	}
	env_var = NULL;
}

/*Get the last node of the linked list env_var.*/
static t_env	*env_last(t_env *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

/*Create the first node of the linked list env_var.
"name" and "value" need to be allocated.*/
t_env	*first_env(char *name, char *value, char *executable)
{
	t_env	*env_var;

	env_var = ft_calloc(1, sizeof(t_env));
	if (!env_var)
	{
		ft_putstr_fd("allocation error\n", 2);
		if (name)
			free(name);
		if (value)
			free(value);
		return (NULL);
	}
	env_var->name = name;
	env_var->value = value;
	env_var->pwd_s = getcwd(NULL, 0);
	env_var->prompt = NULL;
	env_var->exec = ft_strdup(executable);
	env_var->exit_status = 0;
	env_var->is_valid_exit = 0;
	env_var->prev = NULL;
	env_var->next = NULL;
	return (env_var);
}

/*Create and add a node in the linked list.
"name" and "value" need to be allocated.*/
void	add_env(t_env *env_var, char *name, char *value)
{
	t_env	*last;

	last = env_last(env_var);
	last->next = ft_calloc(1, sizeof(t_env));
	if (!last->next)
	{
		free(name);
		free(value);
		ft_putendl_fd("allocation error, env_var init failure", 2);
		return ;
	}
	last->next->name = name;
	last->next->value = value;
	last->next->exec = env_var->exec;
	last->next->pwd_s = env_var->pwd_s;
	last->next->exit_status = env_var->exit_status;
	last->next->prev = last;
	last->next->prompt = NULL;
	last->next->next = NULL;
}

/*Initialize the linked list env_var. We will use this list
in every built-in of our Minishell program.*/
t_env	*init_env(char **envp, char *executable)
{
	t_env	*env_var;
	int		i;
	int		j;

	i = 0;
	j = 0;
	env_var = NULL;
	while (envp[i])
	{
		while (envp[i][j] && envp[i][j] != '=')
			j++;
		if (!env_var)
			env_var = first_env(ft_substr(envp[i], 0, j),
					ft_substr(envp[i], j + 1, ft_strlen(envp[i])), executable);
		else
			add_env(env_var, ft_substr(envp[i], 0, j),
				ft_substr(envp[i], j + 1, ft_strlen(envp[i])));
		j = 0;
		i++;
	}
	if (!env_var)
		env_var = first_env(NULL, NULL, executable);
	shell_lvl(env_var);
	return (env_var);
}
