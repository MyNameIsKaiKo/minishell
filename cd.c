/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nredouan <nredouan@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 15:54:18 by nredouan          #+#    #+#             */
/*   Updated: 2026/02/17 12:48:31 by nredouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*cd(const char *path, t_env *env_var)
{
	char	*str;

	if (!path)
	{
		str = getenv("HOME");
		if (!str)
			ft_putendl_fd("Error: HOME not set", 2);
		else
			chdir(str);
	}
	else
	{
		path += 3;//a retirer pour parsing complet
		if (chdir(path) < 0)
			perror("Error");
	}
	change_prompt(env_var);
	str = build_prompt(env_var);
	return (str);
}
