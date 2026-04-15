/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nredouan <nredouan@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 16:44:38 by nredouan          #+#    #+#             */
/*   Updated: 2026/04/10 16:04:30 by nredouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../built_in.h"

static bool	check_option(char *args)
{
	int		i;

	i = 0;
	if (!args)
		return (false);
	if (args[i] == '-')
	{
		i++;
		while (args[i] == 'n')
			i++;
		if (!args[i] && args[i - 1] == 'n')
			return (true);
	}
	return (false);
}

int	echo(char **args, t_env *env_var)
{
	bool	option;
	int		i;

	i = 0;
	(void)env_var;
	option = check_option(args[0]);
	while (args && args[i])
	{
		if (i == 0 && option)
		{
			while (check_option(args[i]))
				i++;
		}
		ft_putstr_fd(args[i], 1);
		if (args[i + 1])
			write(1, " ", 1);
		i++;
	}
	if (!option)
		write(1, "\n", 1);
	return (0);
}
