/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nredouan <nredouan@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 12:22:55 by nredouan          #+#    #+#             */
/*   Updated: 2026/03/02 17:27:13 by nredouan         ###   ########.fr       */
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

typedef struct s_env
{
	char			*name;
	char			*value;
	struct s_env	*next;
}					t_env;

char				*build_prompt(void);
void				add_env(t_env *env_var, char *name, char *value);
t_env				*init_env(char **envp);
void				free_env(t_env *env_var);

char				*cd(const char *path, t_env *env_var);
char				*path_error(char *path, char *oldpath);
void				set_pwd(t_env *pwd, t_env *old_pwd);
void				set_oldpwd(t_env *old_pwd);
void				change_pwd(t_env *old_pwd, char *newpwd, char *oldpwd);

#endif