/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleray <marvin@d42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 07:59:30 by jleray            #+#    #+#             */
/*   Updated: 2026/02/19 17:12:42 by jleray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

// TODO ADD A WAY TO HANDLE HERE DOC AND TEST MULTI PIPE WITHIN A CMD

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

int	exec_tree(t_node *tree)
{
	int	success;

	if (!tree)
		return (0);
	if (!ft_strncmp(tree->type, "&&", 2))
	{
		if (exec_tree(tree->left))
			return (0);
		else
			success = exec_tree(tree->right);
	}
	else if (!ft_strncmp(tree->type, "||", 2))
	{
		if (exec_tree(tree->left))
			success = exec_tree(tree->right);
		else
			return (0);
	}
	else if (!ft_strncmp(tree->type, "|", 1))
		success = pipe_exec(tree);
	else
		success = cmd_exec(tree);
	if (!success)
		return (success);
	return (success);
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
