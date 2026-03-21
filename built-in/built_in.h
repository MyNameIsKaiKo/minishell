/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nredouan <nredouan@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 12:22:55 by nredouan          #+#    #+#             */
/*   Updated: 2026/03/21 12:53:17 by nredouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILT_IN_H
# define BUILT_IN_H

# include <stdbool.h>
# include <stdlib.h>
# include <stdio.h>
# include "../include/libft/libft.h"
# include "../env_var/env_var.h"

/*Execute "cd" built-in: change current working directory*/
char				*cd(char **args, t_env *env_var);
char				*path_error(char *path, char *oldpath);
void				set_dash_pwd(t_env *pwd, t_env *old_pwd);
void				set_dash_oldpwd(t_env *old_pwd);
void				change_pwd(t_env *old_pwd, char *newpwd, char *oldpwd);

/*Execute "pwd" built-in: write the path of the current working
directory in the standard output*/
void				pwd(void);

/*Execute "unset" built-in: unset one or multiple env vars*/
t_env				*unset(char **args, t_env *env_var);

/*Execute "env" built-in: print the list of env vars,
except those that have not been assigned a value*/
void				env(char **arg, t_env *env_var);

/*Execute "export" built-in: create new env vars,
change value of an env var or print the list of env vars*/
t_env				*export(char **args, t_env *env_var);

/*Print the list of all variables set in env_var in alphabetical order.*/
void				print_export(t_env *env_var);

/*Print an error message in case of non-alphabetical
characters in the name of the variable we want to add.*/
void				print_export_error(char *arg, int err);
bool				check_export_args(char **args);
bool				env_search(char *name, t_env *env_var);
char				*set_name(char *arg, int i);
char				*set_value(char *arg, int i);
void				chose_value(t_env *env, char *name, char *value, char c);
void				free_strings(char *name, char *value);
bool				parser_export(char *arg);
void				quick_sort(char **name_copy, int start, int end);

/*Execute "echo" built-in: write arguments in the standard output*/
void				echo(char **args, t_env *env_var);

char				*build_prompt(void);

#endif