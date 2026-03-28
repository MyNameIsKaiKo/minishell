/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nredouan <nredouan@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 17:16:47 by nredouan          #+#    #+#             */
/*   Updated: 2025/12/20 17:43:50 by nredouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	free_str(char *s1, char *s2)
{
	free(s1);
	free(s2);
}

static char	*read_buf_stock(char *stock, int fd, int *read_value)
{
	char	*buffer;

	while (*read_value != 0 && !find_line(stock))
	{
		buffer = malloc(BUFFER_SIZE + 1);
		if (!buffer)
			free (stock);
		if (!buffer)
			return (NULL);
		*read_value = read(fd, buffer, BUFFER_SIZE);
		if (*read_value < 0)
			free_str(buffer, stock);
		if (*read_value < 0)
			return (NULL);
		if (*read_value == 0)
			free(buffer);
		if (*read_value == 0)
			return (stock);
		buffer[*read_value] = '\0';
		stock = ft_strjoin2(stock, buffer);
		free(buffer);
		if (!stock)
			return (NULL);
	}
	return (stock);
}

static char	*clean_stock(char *stock)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (stock[i] && stock[i] != '\n')
		i++;
	if (stock[i] == '\n')
		i++;
	if (stock[i] == '\0')
	{
		free (stock);
		return (NULL);
	}
	while (stock[i + j])
	{
		stock[j] = stock[i + j];
		j++;
	}
	stock[j] = '\0';
	return (stock);
}

static char	*get_line(const char *src)
{
	char	*dup;
	int		i;

	i = 0;
	dup = malloc(ft_strlen2(src) + 1);
	if (!dup)
		return (NULL);
	while (src[i])
	{
		dup[i] = src[i];
		if (dup[i] == '\n')
		{
			i++;
			break ;
		}
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*get_next_line(int fd)
{
	static char	*stock = NULL;
	char		*result;
	int			read_value;

	read_value = 1;
	result = NULL;
	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	stock = read_buf_stock(stock, fd, &read_value);
	if (!stock)
		return (NULL);
	result = get_line(stock);
	stock = clean_stock(stock);
	return (result);
}
