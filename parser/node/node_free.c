/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleray <marvin@d42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 17:35:19 by jleray            #+#    #+#             */
/*   Updated: 2026/02/13 17:35:19 by jleray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"

void	node_free(t_node *node)
{
	t_node	*tmp;
	t_node	*left;
	t_node	*right;

	left = node->left;
	right = node->right;
	while (left->left)
	{
		tmp = left;
		free(tmp->data);
		left = left->left;
		free(tmp);
	}
	while (right->right)
	{
		tmp = right;
		free(tmp->data);
		right = right->left;
		free(tmp);
	}
	free(node->data);
	free(node);
}
