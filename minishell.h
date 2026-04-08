/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleray <marvin@d42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 14:12:00 by jleray            #+#    #+#             */
/*   Updated: 2026/04/08 18:50:58 by jleray           ###   ########.fr       */
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
void	apply_expend(t_lexer **lex, t_data data);

// --- Wildscards Function
char	**wildcards(char *pattern);
void	apply_wildcard(t_lexer **lex);

//	--- Utils Function ---
void	free_str(char **str);
char	*ft_strjoinjoin(const char *s1, const char *s2, const char *s3);

#endif
