/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parserv2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleray <marvin@d42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 07:59:30 by jleray            #+#    #+#             */
/*   Updated: 2026/02/19 15:01:30 by jleray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_node	*make_tree(char *str, t_node **head)
{
	t_node	*node;
	char	*is_op;

	is_op = get_last_op(str, "LOGIC");
	if (!is_op)
		is_op = get_last_op(str, "PIPE");
	if (is_op)
	{
		node = create_treenodes(str, is_op, head);
		if (!node)
			return (NULL);
	}
	else
		node = nodenew(ft_strdup(str), "CMD", *head);
	if (!node)
	{
		node_free(*head);
		return (NULL);
	}
	return (node);
}

void	exec_tree(t_node *tree)
{
	if (!ft_strncmp(tree->type, "&&", 2))
	{
		// exec_tree with left and if left return 0 exec right
	}
	else if (!ft_strncmp(tree->type, "||", 2))
	{
		// exec_tree with left and if left return 0 stop else exec right
	}
	else if (!ft_strncmp(tree->type, "|", 1))
	{
		// exec_pipe
		// exec pipe need to call exec_three
	}
	else
	{
		// exec cmd
	}
	return ;
}

void	handle_tree(char *str)
{
	t_node	*head;

	head = nodenew(NULL, "HEAD", NULL);
	if (!head)
		return ;
	node_add(&head, make_tree(str, &head), "LEFT");
	if (!head)
		return ;
}
