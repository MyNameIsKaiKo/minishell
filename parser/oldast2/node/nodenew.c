/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodenew.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleray <marvin@d42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 16:00:23 by jleray            #+#    #+#             */
/*   Updated: 2026/03/12 15:01:11 by jleray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ast.h"

t_ast	*nodenew(char *data, int type, t_ast **head)
{
	t_ast	*node;

	node = malloc(sizeof(t_ast));
	if (!head)
		*head = node;
	node->data = data;
	node->right = NULL;
	node->left = NULL;
	node->head = (*head);
	node->type = type;
	return (node);
}
