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

t_node	*make_tree(char *str)
{
	char	*is_op;
	t_node	*node;

	is_op = get_last_op(str, "LOGIC");
	if (!is_op)
		is_op = get_last_op(str, "PIPE");
	if (ft_strncmp(is_op, "&&", 2) || ft_strncmp(is_op, "||", 2))
	{
		node = nodenew(ft_strdup(is_op), is_op, NULL);
		node_add(&node, make_tree(ft_getleft(str, is_op)), "LEFT");
		node_add(&node, make_tree(ft_getright(str, is_op)), "RIGHT");
	}
	else if (ft_strncmp(is_op, "|", 1))
	{
		node = nodenew(ft_strdup(is_op), is_op, NULL);
		node_add(&node, make_tree(ft_getleft(str, is_op)), "LEFT");
		node_add(&node, make_tree(ft_getright(str, is_op)), "RIGHT");
	}
	else
		node = nodenew(ft_strdup(str), "CMD", NULL);
	return (node);
}
