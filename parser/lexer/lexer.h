/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleray <marvin@d42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 23:49:11 by jleray            #+#    #+#             */
/*   Updated: 2026/02/20 23:49:11 by jleray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include "../../include/libft/libft.h"

typedef enum e_token_type
{
	WORD,
	PIPE,
	REDIR_IN,
	REDIR_OUT,
	PONCT,
	HEREDOC,
	APPEND,
	OPERATOR
}						t_token_type;

typedef struct s_lexer
{
	char				*data;
	enum e_token_type	type;
	struct s_lexer		*next;
	int					index;
}						t_lexer;

// -- struct Function --
t_lexer					*lexer_last(t_lexer *lex);
t_lexer					*lexernew(char *data, int type);
void					lexer_add(t_lexer *head, t_lexer *to_add);
void					lexer_free(t_lexer *lex);
void					indexing_lex(t_lexer **lex);

// -- lexer --
t_lexer					*lexing(char *str);

// -- lexer_utils Function --
char					*strcjoin(char *s, char c);
int						is_complete_w(char *str);

#endif
