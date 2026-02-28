/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_ponct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleray <marvin@d42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 09:14:54 by jleray            #+#    #+#             */
/*   Updated: 2026/02/28 11:17:13 by jleray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int	is_ponct(char *str)
{
	if (!ft_strncmp(str, "\'", 1) || !ft_strncmp(str, "\"", 1))
		return (1);
	if (!ft_strncmp(str, "(", 1) || !ft_strncmp(str, ")", 1))
		return (2);
	return (0);
}

int	find_first_ponct(t_lexer *lex)
{
	int	status;

	status = 0;
	while (lex->next)
	{
		status = is_ponct(lex->data);
		if (status != 0)
			return (status);
		lex = lex->next;
	}
	return (status);
}

void	handle_ponct(t_lexer **lex)
{
	int		ponct_id;

	indexing_lex(lex);
	ponct_id = find_first_ponct(*lex);
	if (ponct_id == 1)
		combined_quotes(lex);
	else if (ponct_id == 2)
		combined_parr(lex);
	else
		return ;
}
