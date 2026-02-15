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
	if (!node)
		return ;
	node_free(node->left);
	node_free(node->right);
	if (node->data)
		free(node->data);
	free(node);
}
