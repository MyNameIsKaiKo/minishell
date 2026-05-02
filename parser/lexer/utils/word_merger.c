/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word_merger.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleray <marvin@d42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 17:36:34 by jleray            #+#    #+#             */
/*   Updated: 2026/04/04 12:22:12 by jleray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lexer.h"

void	merge_words(t_lexer **lex)
{
	t_lexer	*tmp;

	indexing_lex(lex);
	tmp = *lex;
	while (tmp && tmp->next)
	{
		if (tmp->type == WORD && tmp->next->type == WORD)
			tmp = lexer_merge(lex, tmp->index, tmp->next->index, WORD);
		else
			tmp = tmp->next;
	}
}
