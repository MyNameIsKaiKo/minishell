/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   combine_lexer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleray <marvin@d42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 19:45:23 by jleray            #+#    #+#             */
/*   Updated: 2026/02/26 20:44:24 by jleray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int	find_parro(t_lexer **lex)
{
	t_lexer	*tmp;

	tmp = *lex;
	while (tmp->next)
	{
		if (tmp->type == PONCT && !ft_strncmp(tmp->data, "(", 1))
			return (tmp->index);
		tmp = tmp->next;
	}
	return (0);
}

int	find_parrc(t_lexer **lex, int parro)
{
	t_lexer	*tmp;
	t_lexer	*is_parro;
	int		is_another_open;

	tmp = find_by_index(*lex, parro);
	is_parro = tmp;
	while (tmp->next)
	{
		if (tmp->type == PONCT && !ft_strncmp(tmp->data, ")", 1))
		{
			is_another_open = find_parro(&is_parro);
			if ((is_another_open != 0) && (tmp->index < is_another_open))
				return (tmp->index);
			else
				return (0);
		}
	}
	return (0);
}

void	combined_parr(t_lexer **lex)
{
	int	is_open;
	int	is_close;

	indexing_lex(lex);
	is_open = find_parro(lex);
	is_close = 0;
	if (is_open)
		is_close = find_parrc(lex, is_open);
	if (is_close != 0 && is_open != 0)
		lexer_merge(lex, is_open, is_close, SUBPROCESS);
	return ;
}

void	handle_ponct(t_lexer **lex)
{
	t_lexer	*tmp;

	tmp = *lex;
	return ;
}
