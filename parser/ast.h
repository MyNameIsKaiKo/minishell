/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleray <marvin@d42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 14:51:35 by jleray            #+#    #+#             */
/*   Updated: 2026/03/28 16:45:03 by jleray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AST_H
# define AST_H

# include "../minishell.h"
# include "./lexer/lexer.h"

typedef enum e_token_ast
{
	PIPE_AST = 1,
	OPERATOR_AST = 2,
	HEREDOC_AST = 3,
	APPEND_AST = 4,
	REDIR_IN_AST = 5,
	REDIR_OUT_AST = 6,
	SUBPROCESS_AST = 7,
	CMD_AST = 8
}						t_token_ast;

typedef enum e_side
{
	LEFT,
	RIGHT,
}						t_side;

typedef struct s_filesfd
{
	int					fdin;
	int					fdout;
}						t_filesfd;

typedef struct s_ast
{
	enum e_token_ast	type;
	char				*data;
	char				**args;
	struct s_ast		*left;
	struct s_ast		*right;
	struct s_ast		*head;
	int					old_lexindex;
	struct s_filesfd	filesfd;
}						t_ast;

//	--- ast Function ---
t_ast					*make_tree(t_lexer **lex);

//	--- ast_utils Function ---
t_lexer					*get_last_cpoint(t_lexer *lex);
t_lexer					*getright(t_lexer *lex, int index);
t_lexer					*getleft(t_lexer **lex, int index);

//	--- ast node Fucntion ---
t_ast					*nodenew(t_lexer *checkpoint);
void					node_add(t_ast **ast, t_ast *new_node, t_side side);
void					ast_free(t_ast **ast);
int						handle_cmd_merge(t_lexer **lexhead, t_lexer *checkpoint,
							t_ast **node);
void					handle_node_data(t_ast **new_node, t_lexer *checkpoint);

//	--- ast exec Function ---
int						exec_tree(t_ast *tree);
#endif
