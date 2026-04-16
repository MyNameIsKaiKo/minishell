/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleray <marvin@d42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 23:49:11 by jleray            #+#    #+#             */
/*   Updated: 2026/04/15 22:12:54 by jleray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include "../../include/libft/libft.h"

// typedef enum e_token_type
// {
// WORD = 1,
// PIPE = 2,
// REDIR_IN = 3,
// REDIR_OUT = 4,
// PONCT = 5,
// HEREDOC = 6,
// APPEND = 7,
// OPERATOR = 8,
// SUBPROCESS = 9,
// }						t_token_type;

typedef enum e_token_type
{
	WORD = 1,
	SUBPROCESS = 2,
	REDIR_IN = 3,
	REDIR_OUT = 4,
	PONCT = 5,
	WSPACE = 6,
	HEREDOC = 7,
	APPEND = 8,
	PIPE = 9,
	OPERATOR = 10,
}						t_token_type;

typedef enum e_quote_states
{
	SQUOTE = 1,
	DQUOTE = 2
}						t_quote_stats;

typedef struct s_quotedata
{
	enum e_quote_states	state;
	int					lex_index;
}						t_quotedata;

typedef struct s_lexer
{
	char				*data;
	enum e_token_type	type;
	struct s_lexer		*next;
	struct s_lexer		*to_freen;
	int					index;
	int					is_squoted;
}						t_lexer;

// -- struct Function --
t_lexer					*lexer_last(t_lexer *lex);
t_lexer					*lexernew(char *data, int type);
void					lexer_add(t_lexer **head, t_lexer *to_add);
void					lexer_free(t_lexer **lex);
void					indexing_lex(t_lexer **lex);
void					lexer_delone(t_lexer **to_del, t_lexer **head);
void					lexerlst_trim(t_lexer **lex);
void					lexer_abs_free(t_lexer **lex);
void					lexer_set_next(t_lexer **lex, t_lexer *next);

// -- lexer --
t_lexer					*lexer(char *str);

// -- handle_ponct Function --
void					handle_ponct(t_lexer **lex);

// -- lexer_utils Function --
char					*strcjoin(char *s, char c);
int						is_complete_w(char *str, char *og);
t_lexer					*find_by_index(t_lexer *lex, int index);
void					combined_parr(t_lexer **lex);
void					combined_quotes(t_lexer **lex);
void					merge_words(t_lexer **lex);
void					merge_word_ponct(t_lexer **lex);
void					remove_remaining_type(t_lexer **lex, t_token_type type);

// -- lexer_merge function --
t_lexer					*lexer_merge(t_lexer **lex, int start, int stop,
							int type);

#endif
