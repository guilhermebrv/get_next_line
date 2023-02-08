/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gubranco <gubranco@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 21:10:29 by gubranco          #+#    #+#             */
/*   Updated: 2023/02/08 21:11:43 by gubranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

/* 
The get_next_line function is a function that reads a line from a file 
descriptor and returns a pointer to a new string containing that line.
This one uses a static 2D array 'buffer' of size 'FOPEN_MAX' (the maximum 
number of files that can be opened simultaneously) and 'BUFFER_SIZE + 1' 
(the size of the buffer plus one for the null character). The first few lines 
of the function checks if the file descriptor is valid (i.e. within the range 
of 0 and FOPEN_MAX). If the file descriptor is not valid, the function returns 
a null pointer. If the file descriptor is valid, the function calls the read 
function and checks if it returns a value less than zero or if BUFFER_SIZE is
less than one. If either of these conditions is true, the function sets all 
the elements in the buffer to the null character and returns a null pointer.
Next, it enters a while loop, which continues until either the first
element of the buffer is 0 (indicating that the buffer is empty), or read 
returns 0 (indicating that there is no more data to read from the file). 
Within the loop, the function calls ft_strjoin to append the contents of 
the buffer to the growing string stored in next_line. The function then 
calls ft_clean_buffer to clear the contents of the buffer, and the loop 
continues until ft_clean_buffer returns a non-zero value, which signals 
the end of the line.*/
char	*get_next_line(int fd)
{
	static char	buffer[FOPEN_MAX][BUFFER_SIZE + 1];
	char		*line;
	int			i;

	i = 0;
	if (fd < 0 || fd > FOPEN_MAX)
		return (NULL);
	if (read(fd, 0, 0) < 0 || BUFFER_SIZE < 1)
	{
		while (buffer[fd][i])
		{
			buffer[fd][i] = '\0';
			i++;
		}
		return (NULL);
	}
	line = NULL;
	while (buffer[fd][0] || read(fd, buffer[fd], BUFFER_SIZE) > 0)
	{
		line = ft_strjoin(line, buffer[fd]);
		if (ft_clean_buffer(buffer[fd]))
			break ;
	}
	return (line);
}
