/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_quote.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleray <marvin@d42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 11:14:23 by jleray            #+#    #+#             */
/*   Updated: 2026/03/06 18:46:51 by jleray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lexer.h"

static void	find_firstq(t_lexer **lex, t_quotedata *data)
{
	t_lexer	*tmp;

	tmp = *lex;
	while (tmp)
	{
		if (tmp->type == PONCT && !ft_strncmp(tmp->data, "\'", 1))
		{
			data->lex_index = tmp->index;
			data->state = SQUOTE;
			return ;
		}
		else if (tmp->type == PONCT && !ft_strncmp(tmp->data, "\"", 1))
		{
			data->lex_index = tmp->index;
			data->state = DQUOTE;
			return ;
		}
		tmp = tmp->next;
	}
}

static void	get_scdq(t_lexer *lex, t_quotedata *cdata, char *s)
{
	lex = lex->next;
	while (lex)
	{
		if (lex->type == PONCT && !ft_strncmp(lex->data, s, 1))
		{
			cdata->lex_index = lex->index;
			return ;
		}
		lex = lex->next;
	}
	cdata->lex_index = 0;
	return ;
}

static void	find_scdq(t_lexer **lex, t_quotedata *data)
{
	t_lexer		*tmp;
	t_quotedata	cdata;

	tmp = find_by_index(*lex, data->lex_index);
	if (!tmp)
		return ;
	if (data->state == SQUOTE)
		get_scdq(tmp, &cdata, "\'");
	else
		get_scdq(tmp, &cdata, "\"");
	if (cdata.lex_index != 0 && data->lex_index != 0)
		lexer_merge(lex, data->lex_index, cdata.lex_index, WORD);
	else if (data->lex_index != 0)
		tmp->type = WORD;
}

void	combined_quotes(t_lexer **lex)
{
	t_quotedata	data;

	find_firstq(lex, &data);
	if (data.state == SQUOTE || data.state == DQUOTE)
		find_scdq(lex, &data);
	return ;
}
