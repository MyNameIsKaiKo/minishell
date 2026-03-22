/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodenew_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleray <marvin@d42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 18:04:25 by jleray            #+#    #+#             */
/*   Updated: 2026/03/22 21:25:46 by jleray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ast.h"

static int	merged_cmd(t_lexer **lexhead, t_lexer *checkpoint, t_ast **node,
		int delta)
{
	const int	index = checkpoint->index;
	t_lexer		*merged_lex;

	merged_lex = lexer_merge(lexhead, index, index + delta, checkpoint->type);
	checkpoint = NULL;
	(*node)->data = ft_strdup(merged_lex->data);
	return (merged_lex->index);
}

int	handle_cmd_merge(t_lexer **lexhead, t_lexer *checkpoint, t_ast **node)
{
	const int	index = checkpoint->index;
	t_lexer		*next;
	int			merged_index;

	next = find_by_index(*lexhead, index + 1);
	merged_index = 0;
	if (next && next->type == WORD)
	{
		if (!ft_strncmp(next->data, "-", 1))
		{
			if (next->next && next->next->type == WORD)
				merged_index = merged_cmd(lexhead, checkpoint, node, 2);
			else
				merged_index = merged_cmd(lexhead, checkpoint, node, 1);
		}
		else
			merged_index = merged_cmd(lexhead, checkpoint, node, 1);
	}
	else
		merged_index = checkpoint->index;
	return (merged_index);
}
