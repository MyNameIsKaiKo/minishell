/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodenew.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleray <marvin@d42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 16:00:23 by jleray            #+#    #+#             */
/*   Updated: 2026/02/13 16:00:23 by jleray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"

// data will always be a malloc so in node free, need to free data !
t_node	*nodenew(char *data, char *type, t_node *head)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!head)
		head = node;
	node->data = data;
	node->right = NULL;
	node->left = NULL;
	node->head = head;
	node->type = type;
	return (node);
}
