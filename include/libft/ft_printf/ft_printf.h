/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nredouan <nredouan@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 17:35:08 by nredouan          #+#    #+#             */
/*   Updated: 2025/12/20 15:27:15 by nredouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

//library
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

//brief
# ifndef BASELOW
#  define BASELOW "0123456789abcdef"
# endif

# ifndef BASEUP
#  define BASEUP "0123456789ABCDEF"
# endif

//functions
int		ft_printf(const char *to_print, ...);
int		ft_putchar_count(char c);
int		ft_putnbr_base(unsigned int nbr, char *base);
int		ft_putnbr_base_ptr(unsigned long long nbr, char *base);
int		ft_putnbr_count(int n);
int		ft_putstr_count(char *s);
int		ft_print_ptr(unsigned long long ptr, char *base);
int		check_param(const char *s, int c);
int		what_print(char c, va_list args);
size_t	ft_strlen_bis(const char *str);

#endif
