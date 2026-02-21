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

// Aim -> create t_lexer with everything with a token
// token list :
// - word -> file and cmd ?
// - operator -> logic or pipe
// - direction

static int	handle_singletype(char *s)
{
	if (ft_strncmp(s, "|", 1) == 0)
		return (2);
	if (ft_strncmp(s, "<", 1) == 0)
		return (3);
	if (ft_strncmp(s, ">", 1) == 0)
		return (4);
	if (!ft_strncmp(s, "\'", 1) || !ft_strncmp(s, "\"", 1))
		return (5);
	if (!ft_strncmp(s, "(", 1) || !ft_strncmp(s, ")", 1))
		return (5);
	return (0);
}

static int	handle_dualtype(char *s)
{
	if (!ft_strncmp(s, "<<", 2))
		return (6);
	if (!ft_strncmp(s, ">>", 2))
		return (7);
	if (!ft_strncmp(s, "&&", 2) || !ft_strncmp(s, "||", 2))
		return (8);
	return (0);
}

static int	is_type(char *s)
{
	const size_t	size = ft_strlen(s);
	int				status;

	if (size == 1)
	{
		status = handle_singletype(s);
		exit(status);
	}
	else if (size == 2)
	{
		status = handle_dualtype(s);
		exit(status);
	}
	else
		return (1);
	return (0);
}

t_lexer	*lexing(char *str)
{
	t_lexer	*lex;
	char	*tmp;
	int		type;

	lex = NULL;
	tmp = ft_strdup(str);
	if (!tmp)
		return (NULL);
	while (*str)
	{
		tmp = strcjoin(tmp, *str);
		type = is_type(tmp);
		if (type)
		{
			if (!lex)
				lex = lexernew(tmp, type);
			else
				lexer_add(lex, lexernew(tmp, type));
			free(tmp);
			tmp = ft_strdup("");
		}
		str++;
	}
	return (lex);
}
