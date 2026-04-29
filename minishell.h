/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nredouan <nredouan@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 14:12:00 by jleray            #+#    #+#             */
/*   Updated: 2026/04/29 15:00:19 by nredouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "ast.h"
# include "header.h"
# include "lexer.h"
# include "libft.h"

//	--- Built in Function ---
char	*build_prompt(char *pwd);

//	--- Expand Function ---
char	*expand_var(char *arg, int start, int *end, t_env *env);
char	*expander(char *args, t_env *env);
char	*supp_quote(char *result);

// --- Wildscards Function ---
char	**wildcards(char *pattern);

// --- Loop utils ---
bool	ast_error_init(t_lexer *lex, t_ast *ast, t_env **env_var);
bool	lex_init_error(t_lexer *lex, t_env **env_var);
int		loop_init(char *tmp, int type);
t_lexer	*lex_init(char *tmp, t_data *data, t_env **env_var);

//	--- Utils Function ---
void	free_str(char **str);
char	*ft_strjoinjoin(const char *s1, const char *s2, const char *s3);

#endif
