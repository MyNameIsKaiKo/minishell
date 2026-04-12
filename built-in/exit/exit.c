/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nredouan <nredouan@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 14:55:54 by nredouan          #+#    #+#             */
/*   Updated: 2026/04/12 16:27:45 by nredouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../built_in.h"

static bool	exit_verif(char *args)
{
	int	i;

	i = 0;
	while (args && args[i])
	{
		if (!ft_isdigit(args[i]))
			return (false);
		i++;
	}
	if (i > 20)
		return (false);
	return (true);
}

int	minish_exit(char **args, t_env *env_var)
{
	int	i;
	
	i = 0;
	while (args[i])
		i++;
	if (i > 1)
	{
		ft_putendl_fd("minishell: exit: too many arguments", 2);
		env_var->exit_status = 1;
		//ne dois pas exit minishell
		return (env_var->exit_status);
	}
	printf("exit\n");
	if (!exit_verif(args[0]))
	{
		ft_putstr_fd("minishell: exit: ", 2);
		ft_putstr_fd(args[0], 2);
		ft_putendl_fd(":numeric argument required", 2);
		env_var->exit_status =  2;
	}
	else if (args[0])
		env_var->exit_status = ft_atoll(args[0]) % 256;
	return (env_var->exit_status);
	//doit exit minishell
}

//si pas d'arguments, exit status = le dernier reçu (par exemple si ctrl + C est le dernier exit status, "exit" sans rien revient a faire "exit 130")