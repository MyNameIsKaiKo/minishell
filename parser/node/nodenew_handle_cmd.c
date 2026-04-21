/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodenew_handle_cmd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleray <marvin@d42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 19:17:25 by jleray            #+#    #+#             */
/*   Updated: 2026/04/19 20:23:22 by jleray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

static int	count_words(t_lexer *tmp)
{
	int	count;

	count = 0;
	while (tmp && tmp->type == WORD)
	{
		count++;
		tmp = tmp->next;
	}
	return (count);
}

int	handle_cmds_nodenew(t_lexer *checkpoint, t_ast *node)
{
	t_lexer	*tmp;
	int		count;
	int		i;

	tmp = checkpoint;
	count = count_words(tmp);
	node->args = malloc(sizeof(char *) * (count + 1));
	node->quote_states = calloc(sizeof(int), count);
	if (!node->args)
		return (0);
	i = 0;
	tmp = checkpoint;
	while (i < count)
	{
		node->args[i] = ft_strdup(tmp->data);
		if (tmp->is_squoted)
			node->quote_states[i] = 1;
		i++;
		tmp = tmp->next;
	}
	node->args[i] = NULL;
	return (checkpoint->index + count - 1);
}
