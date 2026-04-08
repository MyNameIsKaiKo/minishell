/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_var.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nredouan <nredouan@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 11:27:53 by nredouan          #+#    #+#             */
/*   Updated: 2026/04/08 16:10:35 by jleray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_VAR_H
# define ENV_VAR_H

# include "../include/libft/libft.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct s_env
{
	char			*name;
	char			*value;
	char			*s_pwd;
	char			*exec;
	struct s_env	*next;
	struct s_env	*prev;
}					t_env;

void				add_env(t_env *env_var, char *name, char *value);
t_env				*init_env(char **envp);
t_env				*first_env(char *name, char *value);
void				free_env(t_env *env_var);
char				**reverse_env(t_env **env);
#endif
