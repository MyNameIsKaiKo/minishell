/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleray <marvin@d42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 15:14:20 by jleray            #+#    #+#             */
/*   Updated: 2026/02/13 15:14:20 by jleray           ###   ########.fr       */
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

static void	make_three(char *operator, char *str, t_node **node)
{
	char	*l_part;
	char	*r_part;
	char	*op_pos;

	if (!operator)
	{
	}
	else
	{
		*node = nodenew(ft_strdup(str), operator, NULL);
		op_pos = ft_strrnstr(str, operator, 2);
		l_part = ft_substr(str, 0, ft_strlen(op_pos - 2));
		r_part = ft_substr(str, ft_strlen(op_pos + 2), ft_strlen(str)
				- ft_strlen(op_pos + 2));
		node_add(node, nodenew(l_part, NULL, *node), "left");
		node_add(node, nodenew(r_part, NULL, *node), "right");
	}
}

void	parser(char *str)
{
	char	*is_operator;
	t_node	*node;

	is_operator = check_operator(str);
	make_three(is_operator, str, &node);
}
