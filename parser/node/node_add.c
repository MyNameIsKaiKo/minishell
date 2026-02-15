/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_add.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleray <marvin@d42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 16:05:32 by jleray            #+#    #+#             */
/*   Updated: 2026/02/13 16:08:45 by jleray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"

void	node_add(t_node *node, t_node *new_node, char *side)
{
	if (!node || !new_node)
		return ;
	if (ft_strncmp(side, "left", 4) == 0)
		node->left = new_node;
	if (ft_strncmp(side, "right", 5) == 0)
		node->right = new_node;
	return ;
}
