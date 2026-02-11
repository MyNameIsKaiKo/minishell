/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleray <marvin@d42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 12:34:32 by jleray            #+#    #+#             */
/*   Updated: 2026/02/11 12:34:32 by jleray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include "./libft/libft.h"

// -- pipex_tools Function --
void	check_files(char *infile, char *outfile);

// -- main_error Function --
void	arg_error(void);
void	error(void);

#endif
