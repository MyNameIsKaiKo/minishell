/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word_and_ponct_merger.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleray <marvin@d42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 13:28:13 by jleray            #+#    #+#             */
/*   Updated: 2026/03/13 14:23:14 by jleray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lexer.h"

int	is_chained_word_ponct(t_lexer *lex)
{
	while (lex->next)
	{
		if ((lex->type == WORD && lex->next->type == PONCT)
			|| (lex->type == PONCT && lex->next->type == WORD))
			return (1);
		lex = lex->next;
	}
	return (0);
}

t_lexer	*find_start(t_lexer *lex)
{
	while (lex)
	{
		if (lex->type == WORD && lex->next->type == PONCT)
			return (lex);
		if (lex->type == PONCT && lex->next->type == WORD)
			return (lex);
		lex = lex->next;
	}
	return (NULL);
}

t_lexer	*find_stop(t_lexer *start, t_lexer *lex)
{
	while (lex->index == start->index)
		lex = lex->next;
	if (start->type == PONCT)
	{
		if (lex->next->type == WORD)
			return (lex->next);
	}
	else if (start->type == WORD)
	{
		if (lex->next->type == PONCT)
			return (lex->next);
	}
	return (NULL);
}

void	merge_word_ponct(t_lexer **lex)
{
	t_lexer	*start;
	t_lexer	*stop;

	indexing_lex(lex);
	while (is_chained_word_ponct(*lex))
	{
		start = find_start((*lex));
		stop = find_stop(start, (*lex));
		lexer_merge(lex, start->index, stop->index, WORD);
	}
}
