/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nredouan <nredouan@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 11:27:59 by nredouan          #+#    #+#             */
/*   Updated: 2026/04/06 16:51:00 by nredouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "include/libft/libft.h"
# include "env_var/env_var.h"
# include "built-in/built_in.h"

/*Build the prompt according to the working directory*/
char	*build_prompt(char *pwd);

void	free_str(char **str);

char	**wildcards(char *pattern);

char	*expander(char *args, t_env *env);
char	*expand_var(char *arg, int start, int *end, t_env *env);

#endif