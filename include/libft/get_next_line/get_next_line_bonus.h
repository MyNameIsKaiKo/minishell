/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nredouan <nredouan@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 13:03:32 by nredouan          #+#    #+#             */
/*   Updated: 2025/12/20 17:54:03 by nredouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

//libraries
# include <unistd.h>
# include <stdlib.h>

//brief
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

//functions
char	*get_next_line(int fd);
int		find_line(const char *s);
char	*ft_strjoin2(char *s1, char *s2);
size_t	ft_strlen2(const char *str);

#endif