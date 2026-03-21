/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexerlst_merge.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleray <marvin@d42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 19:56:30 by jleray            #+#    #+#             */
/*   Updated: 2026/03/21 18:56:56 by jleray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lexer.h"

char	*merge_data(t_lexer *start_lex, int diff)
{
	int		i;
	char	*merged;
	char	*tmp;

	i = 0;
	merged = ft_strdup(start_lex->data);
	start_lex = start_lex->next;
	while (i < diff)
	{
		tmp = ft_strdup(merged);
		free(merged);
		merged = ft_strjoin(tmp, start_lex->data);
		free(tmp);
		start_lex = start_lex->next;
		i++;
	}
	return (merged);
}

t_lexer	*lexer_merge(t_lexer **lex, int start, int stop, int type)
{
	t_lexer	*start_lex;
	t_lexer	*new_lex;
	t_lexer	*tmp;
	char	*data;

	start_lex = find_by_index(*lex, start);
	data = merge_data(start_lex, stop - start);
	new_lex = lexernew(data, type);
	tmp = find_by_index(*lex, stop + 1);
	new_lex->next = tmp;
	tmp = find_by_index(*lex, stop);
	tmp->next = NULL;
	tmp = find_by_index(*lex, start - 1);
	if (tmp)
		tmp->next = new_lex;
	else
		*lex = new_lex;
	lexer_free(&start_lex);
	indexing_lex(lex);
	return (new_lex->index);
}
