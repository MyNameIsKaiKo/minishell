/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nredouan <nredouan@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 15:16:42 by nredouan          #+#    #+#             */
/*   Updated: 2026/04/30 20:05:11 by nredouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../built_in.h"

static void	recup_info_head(t_env *to_recup, t_env *new_head)
{
	if (to_recup != new_head)
	{
		new_head->exec = to_recup->exec;
		new_head->exit_status = to_recup->exit_status;
		new_head->is_valid_exit = to_recup->is_valid_exit;
		new_head->prompt = to_recup->prompt;
		new_head->pwd_s = to_recup->pwd_s;
	}
}

static t_env	*supp_node(const char *name, t_env *env_var)
{
	t_env	*head;

	head = env_var;
	while (name != env_var->name)
		env_var = env_var->next;
	free(env_var->name);
	free(env_var->value);
	env_var->name = NULL;
	env_var->value = NULL;
	if (!env_var->prev && !env_var->next)
		return (head);
	if (!env_var->prev)
	{
		head = env_var->next;
		head->prev = NULL;
		recup_info_head(env_var, head);
	}
	else
	{
		env_var->prev->next = env_var->next;
		if (env_var->next)
			env_var->next->prev = env_var->prev;
	}
	free(env_var);
	return (head);
}

int	unset(char **args, t_env **env_var)
{
	t_env	*node;
	int		i;

	i = 0;
	while (args[i])
	{
		if (!(*env_var)->name && !(*env_var)->value)
			return (0);
		node = *env_var;
		while (node && ft_strcmp(args[i], node->name))
			node = node->next;
		i++;
		if (!node)
			continue ;
		*env_var = supp_node(node->name, *env_var);
	}
	return (0);
}
