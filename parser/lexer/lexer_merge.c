/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_merge.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleray <marvin@d42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 19:56:30 by jleray            #+#    #+#             */
/*   Updated: 2026/02/24 19:56:30 by jleray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

t_lexer	*find_by_index(t_lexer *lex, int index)
{
	while (lex->next && lex->index != index)
		lex = lex->next;
	if (lex)
		return (lex);
	return (NULL);
}

char	*merge_data(t_lexer *start_lex, int diff)
{
	int		i;
	char	*merged;
	char	*tmp;

	i = 1;
	merged = ft_strdup(start_lex->data);
	start_lex = start_lex->next;
	while (i < diff)
	{
		tmp = ft_strdup(merged);
		free(merged);
		merged = ft_strjoin(tmp, start_lex->data);
		free(tmp);
		start_lex = start_lex->next;
	}
	return (merged);
}

t_lexer	*lexer_merge(t_lexer *lex, int start, int stop, int type)
{
	t_lexer	*start_lex;
	t_lexer	*new_lex;
	t_lexer	*tmp;
	char	*data;

	start_lex = find_by_index(lex, start);
	data = merge_data(start_lex, stop - start);
	new_lex = lexernew(data, type);
	tmp = find_by_index(lex, start - 1);
	tmp->next = new_lex;
	tmp = find_by_index(lex, stop + 1);
	new_lex->next = tmp;
	lexer_free(start_lex);
	return (lex);
}
