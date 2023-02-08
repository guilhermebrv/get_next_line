/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gubranco <gubranco@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 21:10:45 by gubranco          #+#    #+#             */
/*   Updated: 2023/02/08 21:12:35 by gubranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
The get_next_line function is a function that reads a line from a file 
descriptor and returns a pointer to a new string containing that line.
It starts by declaring a static buffer with a size of BUFFER_SIZE + 1, 
as well as a variable next_line which will be used to store the growing
string as the function reads from the file. Then, it checks if the result
of read(fd, 0, 0) is less than 0 or if BUFFER_SIZE is less than 1. 
If either of these conditions is true, the function clears the content
of the buffer by setting each element of the buffer to 0, and then returns 
NULL. Next, it enters a while loop, which continues until either the first
element of the buffer is 0 (indicating that the buffer is empty), or read 
returns 0 (indicating that there is no more data to read from the file). 
Within the loop, the function calls ft_strjoin to append the contents of 
the buffer to the growing string stored in next_line. The function then 
calls ft_clean_buffer to clear the contents of the buffer, and the loop 
continues until ft_clean_buffer returns a non-zero value, which signals 
the end of the line.*/
char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	int			i;

	i = 0;
	if (read(fd, 0, 0) < 0 || BUFFER_SIZE < 1)
	{
		while (buffer[i])
		{
			buffer[i] = '\0';
			i++;
		}
		return (NULL);
	}
	line = NULL;
	while (buffer[0] || read(fd, buffer, BUFFER_SIZE) > 0)
	{
		line = ft_strjoin(line, buffer);
		if (ft_clean_buffer(buffer) == 1)
			break ;
	}
	return (line);
}
