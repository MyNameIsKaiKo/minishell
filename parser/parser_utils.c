/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleray <marvin@d42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 06:38:16 by jleray            #+#    #+#             */
/*   Updated: 2026/02/19 20:09:57 by jleray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	free_in_treenodes(char *op, char *left, char *right)
{
	if (op)
		free(op);
	if (left)
		free(left);
	if (right)
		free(right);
}

t_node	*create_treenodes(char *str, char *is_op, t_node **head)
{
	t_node	*node;
	char	*op;
	char	*left;
	char	*right;

	op = ft_strdup(is_op);
	left = ft_getleft(str, is_op);
	right = ft_getright(str, is_op);
	if (!op || !left || !right)
	{
		free_in_treenodes(op, left, right);
		return (NULL);
	}
	node = nodenew(op, is_op, *head);
	if (!node)
	{
		node_free(*head);
		return (NULL);
	}
	node_add(&node, make_tree(left, head), "LEFT");
	node_add(&node, make_tree(right, head), "RIGHT");
	return (node);
}


