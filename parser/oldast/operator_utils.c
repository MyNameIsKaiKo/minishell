/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleray <marvin@d42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 20:04:52 by jleray            #+#    #+#             */
/*   Updated: 2026/02/19 20:05:16 by jleray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static char	*check_operator(char *str)
{
	const char	*s_and = ft_strrnstr(str, "&&", 2);
	const char	*s_or = ft_strrnstr(str, "||", 2);

	if (!s_or && !s_and)
		return (NULL);
	if (!s_or)
		return ((char *)s_and);
	if (!s_and)
		return ((char *)s_or);
	if (s_and > s_or)
		return ((char *)s_and);
	else
		return ((char *)s_or);
}

char	*get_last_op(char *str, char *type)
{
	char	*op;

	if (ft_strncmp(type, "LOGIC", 5) == 0)
	{
		op = check_operator(str);
		op = or_and(op);
		return (op);
	}
	else if (ft_strncmp(type, "PIPE", 4) == 0)
	{
		op = ft_strrchr(str, '|');
		if (op)
			op = "|";
		return (op);
	}
	return (NULL);
}

char	*or_and(char *op)
{
	if (op && ft_strncmp(op, "&&", 2) == 0)
		op = "&&";
	else if (op)
		op = "||";
	return (op);
}
