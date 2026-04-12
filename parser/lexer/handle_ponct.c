/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_ponct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleray <marvin@d42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 09:14:54 by jleray            #+#    #+#             */
/*   Updated: 2026/03/06 19:34:51 by jleray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int	is_ponct(t_lexer *lex)
{
	char	*str;

	str = lex->data;
	if (lex->type == PONCT
		&& (!ft_strncmp(str, "\'", 1) || !ft_strncmp(str, "\"", 1)))
		return (1);
	if (lex->type == PONCT
		&& (!ft_strncmp(str, "(", 1)))
		return (2);
	return (0);
}

int	find_first_ponct(t_lexer *lex)
{
	int		status;
	t_lexer	*tmp;

	status = 0;
	tmp = lex;
	while (tmp)
	{
		status = is_ponct(tmp);
		if (status != 0)
			return (status);
		tmp = tmp->next;
	}
	return (status);
}

void	handle_ponct(t_lexer **lex)
{
	int	ponct_id;

	indexing_lex(lex);
	ponct_id = find_first_ponct(*lex);
	while (ponct_id != 0)
	{
		if (ponct_id == 1)
			combined_quotes(lex);
		else if (ponct_id == 2)
			combined_parr(lex);
		ponct_id = find_first_ponct(*lex);
	}
}
