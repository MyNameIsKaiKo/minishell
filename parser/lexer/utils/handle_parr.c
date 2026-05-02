/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_parr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nredouan <nredouan@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 19:45:23 by jleray            #+#    #+#             */
/*   Updated: 2026/04/29 16:47:02 by nredouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lexer.h"

int	find_parro(t_lexer **lex)
{
	t_lexer	*tmp;

	tmp = *lex;
	while (tmp)
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
	int		parro_count;

	tmp = find_by_index(*lex, parro);
	if (!tmp)
		return (0);
	parro_count = 1;
	tmp = tmp->next;
	while (tmp)
	{
		if (tmp->type == PONCT && !ft_strncmp(tmp->data, "(", 1))
			parro_count++;
		else if (tmp->type == PONCT && !ft_strncmp(tmp->data, ")", 1))
		{
			parro_count--;
			if (parro_count == 0)
				return (tmp->index);
		}
		tmp = tmp->next;
	}
	return (0);
}

void	combined_parr(t_lexer **lex)
{
	t_lexer	*tmp;
	int		is_open;
	int		is_close;

	is_open = find_parro(lex);
	is_close = 0;
	if (is_open)
		is_close = find_parrc(lex, is_open);
	if (is_close != 0 && is_open != 0)
		lexer_merge(lex, is_open, is_close, SUBPROCESS);
	if (is_close == 0 && is_open)
	{
		tmp = find_by_index((*lex), is_open);
		tmp->type = WORD;
	}
	return ;
}
