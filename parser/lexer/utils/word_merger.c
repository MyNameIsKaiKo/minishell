/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word_merger.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleray <marvin@d42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 17:36:34 by jleray            #+#    #+#             */
/*   Updated: 2026/03/14 16:53:59 by jleray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lexer.h"

static int	is_chained_words(t_lexer *lex)
{
	int	chained;

	chained = 0;
	while (lex->next && lex->next->data[0] != '\0')
	{
		if (lex->type == lex->next->type)
			chained = 1;
		lex = lex->next;
	}
	return (chained);
}

static t_lexer	*find_first_word(t_lexer *lex, int index)
{
	while (lex->index != index)
		lex = lex->next;
	while (lex)
	{
		if (lex->type == WORD)
			return (lex);
		lex = lex->next;
	}
	return (NULL);
}

static t_lexer	*find_last_word(t_lexer *lex, int index)
{
	t_lexer	*tmp;

	tmp = find_by_index(lex, index);
	while (tmp->type == WORD)
		tmp = tmp->next;
	tmp = find_by_index(lex, tmp->index - 1);
	return (tmp);
}

void	merge_words(t_lexer **lex)
{
	t_lexer	*first_word;
	t_lexer	*last_word;
	int		index;

	indexing_lex(lex);
	last_word = NULL;
	while (is_chained_words(*lex))
	{
		if (last_word)
			index = last_word->index;
		else
			index = 1;
		first_word = find_first_word(*lex, index);
		last_word = find_last_word(*lex, first_word->index);
		lexer_merge(lex, first_word->index, last_word->index, WORD);
	}
}
