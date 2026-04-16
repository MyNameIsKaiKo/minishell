/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nredouan <nredouan@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 11:27:59 by nredouan          #+#    #+#             */
/*   Updated: 2026/04/16 20:06:52 by nredouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include "libft.h"
# include <fcntl.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>
# include "./built-in/built_in.h"
# include "./env_var/env_var.h"

/*Build the prompt according to the working directory*/
char	*build_prompt(char *pwd);

void	free_str(char **str);

char	**wildcards(char *pattern);

char	*expander(char *args, t_env *env);
char	*expand_var(char *arg, int start, int *end, t_env *env);
void	expand_copy(char *result, int *i, t_env *env, char *var);
char	*search_and_expand(char *result, int *i, t_env *env);
void	not_expand(char *result, int *i);
bool	check_unclose(char *arg, char quote, int i);

#endif
