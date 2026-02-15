/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parserv2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleray <marvin@d42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 07:59:30 by jleray            #+#    #+#             */
/*   Updated: 2026/02/15 07:59:30 by jleray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static char	*check_operator(char *str)
{
	const char	*s_and = ft_strrnstr(str, "&&", 2);
	const char	*s_or = ft_strrnstr(str, "||", 2);

	if (ft_strlen(s_and) > ft_strlen(s_or))
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
		return (op);
	}
	else if (ft_strncmp(type, "PIPE", 4) == 0)
	{
		op = ft_strrchr(str, '|');
		return (op);
	}
	return (str);
}
