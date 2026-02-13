/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleray <marvin@d42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 14:54:04 by jleray            #+#    #+#             */
/*   Updated: 2026/02/13 14:54:04 by jleray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "../include/libft/libft.h"

typedef struct s_node
{
	char			*type;
	char			*data;
	struct s_node	*right;
	struct s_node	*left;
	struct s_node	*head;
}					t_node;

#endif
