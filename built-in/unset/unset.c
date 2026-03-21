/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nredouan <nredouan@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 15:16:42 by nredouan          #+#    #+#             */
/*   Updated: 2026/03/21 12:53:50 by nredouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../built_in.h"

static t_env	*supp_node(const char *name, t_env *env_var)
{
	t_env	*head;

	head = env_var;
	while (name != env_var->name)
		env_var = env_var->next;
	free(env_var->name);
	free(env_var->value);
	if (!env_var->prev)
	{
		if (env_var->next)
			env_var->next->prev = NULL;
		head = env_var->next;
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

t_env	*unset(char **args, t_env *env_var)
{
	t_env	*node;
	int		i;

	i = 0;
	while (args[i])
	{
		if (!env_var)
			return (NULL);
		node = env_var;
		while (node && ft_strcmp(args[i], node->name))
			node = node->next;
		i++;
		if (!node)
			continue ;
		env_var = supp_node(node->name, env_var);
	}
	return (env_var);
}
