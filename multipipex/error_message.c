/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleray <marvin@d42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 12:36:45 by jleray            #+#    #+#             */
/*   Updated: 2026/02/11 12:36:45 by jleray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	arg_error(void)
{
	ft_putstr_fd("Wrong amount of argument \n", 2);
	ft_putstr_fd("Please follow : ", 2);
	ft_putstr_fd("./pipex infile cmd1 cmd2 ... cmdn outfile\n", 2);
	exit(EXIT_FAILURE);
}

void	error(void)
{
	perror("Error :");
	exit(EXIT_FAILURE);
}
