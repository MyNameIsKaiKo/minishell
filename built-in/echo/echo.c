/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nredouan <nredouan@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 16:44:38 by nredouan          #+#    #+#             */
/*   Updated: 2026/03/12 17:42:57 by nredouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

void	echo(char **args, t_env *env_var)
{
	int	i;

	(void)env_var;
	if (!(*args))
	{
		write(1, "\n", 1);
		return ;
	}
	if (!ft_strcmp(args[0], "-n"))
		i = 1;
	else
		i = 0;
	while (args[i])
	{
		ft_putstr_fd(args[i], 1);
		if (args[i + 1])
			write(1, " ", 1);
		i++;
	}
	if (ft_strcmp(args[0], "-n"))
		write(1, "\n", 1);
}
