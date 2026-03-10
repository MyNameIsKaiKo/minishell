/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nredouan <nredouan@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 12:22:55 by nredouan          #+#    #+#             */
/*   Updated: 2026/03/10 17:38:20 by nredouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
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
	struct s_env	*prev;
}					t_env;

char				*build_prompt(void);

/*Add a new node in the linked list env_var.
WARNING : name and value must be allocated.*/
void				add_env(t_env *env_var, char *name, char *value);

//Initializing the entire linked list env_var.
t_env				*init_env(char **envp);

//Free the entire linked list env_var.
void				free_env(t_env *env_var);

char				*cd(char **args, t_env *env_var);
char				*path_error(char *path, char *oldpath);
void				set_pwd(t_env *pwd, t_env *old_pwd);
void				set_oldpwd(t_env *old_pwd);
void				change_pwd(t_env *old_pwd, char *newpwd, char *oldpwd);

void				pwd(void);

t_env				*unset(char **args, t_env *env_var);

void				export(char **args, t_env *env_var);
void				print_export(t_env *env_var);
void				print_export_error(char *arg);
bool				check_export_args(char **args);
bool				env_search(char *name, t_env *env_var);
char				*set_name(char *arg, int i);
char				*set_value(char *arg, int i);
void				quick_sort(char **name_copy, int start, int end);

#endif