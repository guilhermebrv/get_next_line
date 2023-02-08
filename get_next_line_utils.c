/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gubranco <gubranco@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 21:10:43 by gubranco          #+#    #+#             */
/*   Updated: 2023/02/08 21:11:53 by gubranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *str)
{
	int	size;

	size = 0;
	if (!str)
		return (0);
	while (str[size])
		size++;
	return (size);
}

/*
The ft_strjoin function takes as input two strings, line and buffer, and returns
a new string that is the concatenation of these two strings. The function starts
by allocating memory for the new string using malloc. It then copies the content
of line into the new string, and frees the memory associated with line. Then it
continues to copy the content of buffer into the new string, until it encounters
a '\n' in the buffer, which breaks the loop. At that point, the function adds a 
'\0'' to the new string and returns a pointer to it.*/
char	*ft_strjoin(char *line, char *buffer)
{
	char	*next_line;
	int		i;

	i = 0;
	next_line = malloc(ft_strlen(line) + ft_strlen(buffer) + 1);
	if (!next_line)
		return (NULL);
	while (line && line[i])
	{
		next_line[i] = line[i];
		i++;
	}
	free(line);
	while (*buffer)
	{
		next_line[i] = *buffer;
		i++;
		if (*buffer++ == '\n')
			break ;
	}
	next_line[i] = '\0';
	return (next_line);
}

/*
The ft_clean_buffer function takes as input a buffer, and iterates it, clearing
the contents of each element of the buffer as it goes. If it contains a '\n'',
the function sets variable next to 1 and copies the contents of the buffer from
that point forward to the beginning of the buffer. Then, it returns next.*/
int	ft_clean_buffer(char *buffer)
{
	int	i;
	int	j;
	int	next;

	i = 0;
	j = 0;
	next = 0;
	while (buffer[i])
	{
		if (next == 1)
		{
			buffer[j] = buffer[i];
			j++;
		}
		if (buffer[i] == '\n')
			next = 1;
		buffer[i] = '\0';
		i++;
	}
	return (next);
}
