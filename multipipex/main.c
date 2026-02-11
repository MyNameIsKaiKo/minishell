/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleray <marvin@d42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 12:33:19 by jleray            #+#    #+#             */
/*   Updated: 2026/02/11 12:33:19 by jleray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// 1 -> nb args
// 2 -> check files
// 3 -> parse args (chercher chemin, test commande etc)
//
// // iteratif
// 4 -> creation pipe (dynamique)
// 5 -> fork
//
// wait (wait ou wait pid)
//

int	main(int ac, char **av)
{
	(void)av;
	if (ac < 5)
		arg_error();
	check_files(av[1], av[ac - 1]);
}
