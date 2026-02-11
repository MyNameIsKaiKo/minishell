/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleray <marvin@d42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 12:41:30 by jleray            #+#    #+#             */
/*   Updated: 2026/02/11 12:41:30 by jleray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	check_files(char *infile, char *outfile)
{
	int	fd;

	fd = open(infile, O_WRONLY, 0677);
	if (fd == -1)
		error();
	close(fd);
	fd = open(infile, O_CREAT | O_TRUNC | O_WRONLY, 0644);
	if (fd == -1)
		error();
	close(fd);
}

char	*parse_args(int ac, char **av)
{
	int		i;
	char	**paths;

	i = 3;
	paths = malloc((ac - 3) + 1);
	paths[ac - 3 + 1] = NULL;
	while (i < ac - 2)
	{
		
		i++;
	}
	return (NULL);
}
