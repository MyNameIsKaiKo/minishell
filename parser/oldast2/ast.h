/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleray <marvin@d42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 13:26:02 by jleray            #+#    #+#             */
/*   Updated: 2026/03/12 17:21:18 by jleray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AST_H
# define AST_H

# include "../include/libft/libft.h"
# include "lexer/lexer.h"

typedef enum e_side
{
	LEFT = 1,
	RIGHT = 2
}						t_side;

typedef struct s_ast
{
	enum e_token_type	type;
	char				*data;
	struct s_ast		*right;
	struct s_ast		*left;
	struct s_ast		*head;
}						t_ast;

// -- Node function --
void					ast_free(t_ast **ast);
void					node_add(t_ast **node, t_ast *new_node, t_side side);
t_ast					*nodenew(char *data, int type, t_ast **head);

// -- Utils related Function --
t_lexer					*get_last_op(t_lexer *lex, t_token_type operator);
t_ast					*create_treenodes(t_lexer *lex, t_lexer *is_op,
							t_ast **head);
#endif
