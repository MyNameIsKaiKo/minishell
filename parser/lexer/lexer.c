/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleray <marvin@d42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 20:16:19 by jleray            #+#    #+#             */
/*   Updated: 2026/02/20 20:16:19 by jleray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include <stdio.h>

// Aim -> create t_lexer with everything with a token
// token list :
// - word -> file and cmd ?
// - operator -> logic or pipe
// - direction

static int	handle_singletype(char *s)
{
	if (ft_strncmp(s, "|", 1) == 0 && ft_strncmp(s, "||", 2))
		return (PIPE);
	if (ft_strncmp(s, "<", 1) == 0 && ft_strncmp(s, "<<", 2))
		return (REDIR_OUT);
	if (ft_strncmp(s, ">", 1) == 0 && ft_strncmp(s, ">>", 2))
		return (REDIR_IN);
	if (!ft_strncmp(s, "\'", 1) || !ft_strncmp(s, "\"", 1))
		return (PONCT);
	if (!ft_strncmp(s, "(", 1) || !ft_strncmp(s, ")", 1))
		return (PONCT);
	return (0);
}

static int	handle_dualtype(char *s)
{
	if (!ft_strncmp(s, "<<", 2))
		return (HEREDOC);
	if (!ft_strncmp(s, ">>", 2))
		return (APPEND);
	if (!ft_strncmp(s, "&&", 2) || !ft_strncmp(s, "||", 2))
		return (OPERATOR);
	return (0);
}

static int	is_type(char *s, char *og)
{
	const size_t	size = ft_strlen(s);
	int				status;

	if (size == 1)
	{
		status = handle_singletype(s);
		return (status);
	}
	else if (size == 2)
	{
		status = handle_dualtype(s);
		return (status);
	}
	else if (is_complete_w(s, og))
		return (1);
	return (0);
}

// Maybe need to do a scd lexing part where we assamble thing from lexing
void	lexing(t_lexer **lex, char *str)
{
	char	*tmp;
	int		type;

	tmp = ft_strdup("");
	if (!tmp)
		return ;
	while (*str)
	{
		tmp = strcjoin(tmp, *str);
		str++;
		type = is_type(tmp, str);
		if (type)
		{
			if (!(*lex))
				(*lex) = lexernew(ft_strdup(tmp), type);
			else
				lexer_add(lex, lexernew(ft_strdup(tmp), type));
			free(tmp);
			tmp = ft_strdup("");
		}
	}
	return ;
}

t_lexer	*lexer(char *str)
{
	t_lexer	*lex;

	lex = NULL;
	lexing(&lex, str);
	indexing_lex(&lex);
	// if (lex)
	// handle_ponct(&lex);
	// else
	// return (NULL);
	return (lex);
}
