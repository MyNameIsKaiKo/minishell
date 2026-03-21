/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minish_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleray <marvin@d42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 17:03:49 by jleray            #+#    #+#             */
/*   Updated: 2026/02/20 17:03:49 by jleray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	is_builtin(char *s)
{
	const int	size = ft_strlen(s);

	if (ft_strnstr(s, "cd", size))
		write(1, "TODO", 1);
	return (0);
}

int	cmd_exec(t_node *tree)
{
	pid_t	cmd;

	if (is_builtin(tree->data))
	{
		write(1, "TODO", 1);
	}
	else
	{
		cmd = fork();
		if (cmd == 0)
			write(1, "TODO", 1);
	}
	return (0);
}
