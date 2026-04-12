/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nredouan <nredouan@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 11:54:48 by nredouan          #+#    #+#             */
/*   Updated: 2026/04/11 15:07:34 by nredouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../built_in.h"

/*Print an error message in case of wrong argument,
the env built-in don't need any argument*/
static void	print_env_error(char *arg)
{
	ft_putstr_fd("minishell: env: \'", 2);
	ft_putstr_fd(arg, 2);
	ft_putstr_fd("\': No such file or directory\n", 2);
}

int	env(char **arg, t_env *env_var)
{
	if (arg[0])
	{
		print_env_error(arg[0]);
		return (1);
	}
	while (env_var)
	{
		if (env_var->value)
			printf("%s=%s\n", env_var->name, env_var->value);
		env_var = env_var->next;
	}
	return (0);
}
