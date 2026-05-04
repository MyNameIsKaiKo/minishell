/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_heredoc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nredouan <nredouan@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 14:39:24 by nredouan          #+#    #+#             */
/*   Updated: 2026/05/04 14:40:57 by nredouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

char	*expand_heredoc(char *args, t_env *env)
{
	int		i;

	i = 0;
	while (args[i])
	{
		if (args[i] == '$')
		{
			args = search_and_expand(args, &i, env);
			continue ;
		}
		i++;
	}
	return (args);
}
