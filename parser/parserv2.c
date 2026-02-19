/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parserv2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleray <marvin@d42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 07:59:30 by jleray            #+#    #+#             */
/*   Updated: 2026/02/19 13:10:38 by jleray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_node	*make_tree(char *str, t_node *head)
{
	t_node	*node;
	char	*is_op;

	is_op = get_last_op(str, "LOGIC");
	if (!is_op)
		is_op = get_last_op(str, "PIPE");
	if (ft_strncmp(is_op, "&&", 2) || ft_strncmp(is_op, "||", 2))
	{
		node = create_threenodes(str, is_op, head);
		if (!node)
			return (NULL);
	}
	else if (ft_strncmp(is_op, "|", 1))
	{
		node = create_threenodes(str, is_op, head);
		if (!node)
			return (NULL);
	}
	else
		node = nodenew(ft_strdup(str), "CMD", head);
	if (!node)
		node_free(head);
	return (node);
}

void	exec_three(t_node **node)
{
}
