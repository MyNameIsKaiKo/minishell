/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleray <marvin@d42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 12:09:38 by jleray            #+#    #+#             */
/*   Updated: 2026/03/29 12:22:06 by jleray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env_var.h"

static int	env_size(t_env *env)
{
	int	i;

	i = 0;
	while (env)
	{
		env = env->next;
		i++;
	}
	return (i);
}

char	**reverse_env(t_env **env)
{
	t_env	*tmp;
	char	**output;
	char	*tmpstr;
	int		i;

	tmp = *env;
	i = 0;
	output = malloc(sizeof(char *) * (env_size(tmp) + 1));
	output[env_size(tmp)] = NULL;
	while (tmp)
	{
		tmpstr = ft_strjoin(tmp->name, "=");
		output[i - 1] = ft_strjoin(tmpstr, tmp->value);
		free(tmpstr);
		tmp = tmp->next;
	}
	return (output);
}
