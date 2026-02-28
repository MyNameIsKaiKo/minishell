/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_quote.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleray <marvin@d42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 11:14:23 by jleray            #+#    #+#             */
/*   Updated: 2026/02/28 11:14:23 by jleray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lexer.h"

void	find_firstq(t_lexer **lex, t_quotedata **data)
{
	t_lexer	*tmp;

	tmp = *lex;
	while (tmp->next)
	{
		if (tmp->type == PONCT && !ft_strncmp(tmp->data, "\'", 1))
		{
			(*data)->lex_index = tmp->index;
			(*data)->state = SQUOTE;
		}
		else if (tmp->type == PONCT && !ft_strncmp(tmp->data, "\"", 1))
		{
			(*data)->lex_index = tmp->index;
			(*data)->state = DQUOTE;
		}
	}
}

void	combined_quotes(t_lexer **lex)
{
	t_quotedata	*data;

	find_firstq(lex, &data);
	if (data->state == SQUOTE)
		// TODO
	else if (data->state == DQUOTE)
		// TODO
	return ;
}
