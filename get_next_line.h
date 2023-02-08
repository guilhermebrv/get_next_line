/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gubranco <gubranco@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 21:10:47 by gubranco          #+#    #+#             */
/*   Updated: 2023/02/08 21:12:50 by gubranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <limits.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 33
# endif

char	*get_next_line(int fd);
char	*ft_strjoin(char *line, char *buffer);
int		ft_clean_buffer(char *buffer);
int		ft_strlen(const char *str);

#endif
