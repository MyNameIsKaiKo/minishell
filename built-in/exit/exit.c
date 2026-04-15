/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nredouan <nredouan@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 14:55:54 by nredouan          #+#    #+#             */
/*   Updated: 2026/04/13 18:21:06 by nredouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../built_in.h"

static int	exit_verif(char *arg)
{
	int		sign;
	int		i;

	i = 0;
	sign = 1;
	if (arg && (arg[0] == '-' || arg[0] == '+'))
	{
		if (arg[0] == '-')
			sign *= -1;
		i++;
	}
	while (arg && arg[i])
	{
		if (!ft_isdigit(arg[i]))
			return (0);
		i++;
	}
	return (sign);
}

static bool	print_exit_error(char *arg)
{
	ft_putendl_fd("exit", 2);
	ft_putstr_fd("minishell: exit: ", 2);
	ft_putstr_fd(arg, 2);
	ft_putendl_fd(": numeric argument required", 2);
	return (true);
}

static bool	num_arg_verif(char *arg)
{
	int	sign;

	sign = exit_verif(arg);
	if (sign == 0)
		return (print_exit_error(arg));
	else if (sign == 1)
	{
		if (ft_atoll(arg) == -1)
			return (print_exit_error(arg));
	}
	else if (sign == -1)
	{
		if (ft_atoll(arg) == 0)
			return (print_exit_error(arg));
	}
	return (false);
}

int	minish_exit(char **args, t_env *env_var)
{
	int	i;

	i = 0;
	while (args[i])
		i++;
	env_var->is_valid_exit = 1;
	if (i != 0)
	{
		if (num_arg_verif(args[0]))
		{
			env_var->exit_status = 2;
			return (env_var->exit_status);
		}
	}
	if (i > 1)
	{
		ft_putendl_fd("minishell: exit: too many arguments", 2);
		env_var->is_valid_exit = 0;
		env_var->exit_status = 1;
		return (env_var->exit_status);
	}
	else if (args[0])
		env_var->exit_status = (unsigned char)ft_atoll(args[0]);
	ft_putendl_fd("exit", 2);
	return (env_var->exit_status);
}
