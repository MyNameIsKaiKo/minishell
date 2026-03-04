/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nredouan <nredouan@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 15:16:42 by nredouan          #+#    #+#             */
/*   Updated: 2026/03/04 18:23:50 by nredouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

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

t_env	*unset(const char *arg, t_env *env_var)
{
	size_t	size;
	t_env	*node;
	
	node = env_var;
	size = ft_strlen(arg);
	if (ft_strlen(env_var->name) > size)
		size = ft_strlen(env_var->name);
	while (node && ft_strncmp(arg, node->name, size))
	{
		if (ft_strlen(node->name) > size)
			size = ft_strlen(node->name);
		node = node->next;
	}
	if (!node)
		return (env_var);
	env_var = supp_node(node->name, env_var);
	return (env_var);
}
