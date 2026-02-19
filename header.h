/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nredouan <nredouan@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 12:22:55 by nredouan          #+#    #+#             */
/*   Updated: 2026/02/18 13:45:19 by nredouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include <sys/wait.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "include/libft/libft.h"

//TODO affiner la env_var
typedef struct s_env
{
	char	*pwd;
	char	*old_pwd;
}			t_env;

char		*build_prompt(t_env *env_var);
void		change_prompt(t_env *env_var);
void		init_env(t_env *env_var);
void		free_env(t_env *env_var);
char		*cd(const char *path, t_env *env_var);

#endif