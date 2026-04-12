/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_export.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nredouan <nredouan@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 13:54:41 by nredouan          #+#    #+#             */
/*   Updated: 2026/04/04 17:45:40 by nredouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../built_in.h"

char	*set_name(char *arg, int i)
{
	if (arg[i - 1] == '+')
		return (ft_substr(arg, 0, i - 1));
	return (ft_substr(arg, 0, i));
}

char	*set_value(char *arg, int i)
{
	if (!arg[i])
		return (NULL);
	else if (arg[i] == '=')
	{
		if (!arg[i + 1])
			return (ft_strdup(""));
	}
	return (ft_substr(arg, i + 1, ft_strlen(arg)));
}
