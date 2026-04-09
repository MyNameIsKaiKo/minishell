/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_exec_error_message.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleray <marvin@d42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 13:25:55 by jleray            #+#    #+#             */
/*   Updated: 2026/04/09 13:27:31 by jleray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

int	pipe_error(t_data data)
{
	perror("T&J Shell : ");
	close(data.filesfd.fdin);
	close(data.filesfd.fdout);
	return (1);
}
