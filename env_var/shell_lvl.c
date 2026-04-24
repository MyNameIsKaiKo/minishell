/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_lvl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nredouan <nredouan@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 11:17:03 by nredouan          #+#    #+#             */
/*   Updated: 2026/04/24 17:32:14 by nredouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env_var.h"

unsigned int	get_newlvl(char *value)
{
	int				oldlvl;
	unsigned int	newlvl;

	if (!value || !value[0])
		newlvl = 1;
	else if (value[0] == '-')
	{
		oldlvl = ft_atoi(value);
		if (oldlvl == 0)
			newlvl = 0;
		else
			newlvl = (unsigned int)(oldlvl + 1);
	}
	else
	{
		oldlvl = ft_atoi(value);
		if (oldlvl == -1)
			newlvl = 0;
		else
			newlvl = (unsigned int)(oldlvl + 1);
	}
	if (newlvl > INT_MAX)
		newlvl = 0;
	return (newlvl);
}

void	shell_lvl(t_env *env_var)
{
	unsigned int	newlvl;

	while (env_var)
	{
		if (env_var->name && !ft_strcmp(env_var->name, "SHLVL"))
		{
			newlvl = get_newlvl(env_var->value);
			free(env_var->value);
			env_var->value = ft_itoa(newlvl);
			break ;
		}
		env_var = env_var->next;
	}
}
