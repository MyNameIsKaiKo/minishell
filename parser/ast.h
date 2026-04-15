/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleray <marvin@d42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 14:51:35 by jleray            #+#    #+#             */
/*   Updated: 2026/04/12 18:35:52 by jleray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AST_H
# define AST_H

# include "../header.h"
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
	int					fdintmp;
	int					fdouttmp;
}						t_filesfd;

typedef struct s_data
{
	struct s_filesfd	filesfd;
	struct s_env		**env;
}						t_data;

typedef struct s_ast
{
	enum e_token_ast	type;
	char				*data;
	char				**args;
	struct s_ast		*left;
	struct s_ast		*right;
	struct s_ast		*head;
	int					old_lexindex;
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
int						exec_tree(t_ast *tree, t_data data);
int						exec_pipe(t_ast *tree, t_data data);
int						exec_cmd(t_ast *tree, t_data data);
int						exec_builtin(t_ast *tree, t_data data);
int						exec_heredoc(char *delimiter, t_data *data);
int						exec_redir(t_ast *tree, t_data data);

//	--- ast exec cmd utils Function ---
int						is_builtin(char *str);
void					child_init(t_data data);
char					*find_cmdpath(char **paths, char *cmd);
char					**find_path(t_data data);

//	--- free Function ---
void					free_sarr(char **arr);

//	--- cmd error Function ---
int						cmd_path_error(char **paths, char *cmd);
int						cmd_error(char *cmd);
void					cmd_env_error(char **paths, char *path, char *cmd);

//	--- exec_error_message ---
int						pipe_error(t_data data);
#endif
