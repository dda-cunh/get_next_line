/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-cunh <dda-cunh@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 21:26:03 by dda-cunh          #+#    #+#             */
/*   Updated: 2023/12/30 21:11:08 by dda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	residual(char *buffer)
{
	int	i;

	i = -1;
	while (++i < BUFFER_SIZE)
		if (buffer[i])
			return (1);
	return (0);
}

static char	*seek_line(char *buffer, char *line, int fd)
{
	long	bytes_read;

	bytes_read = 1;
	while (bytes_read > 0)
	{
		if (str_has_c(line, '\n'))
			break ;
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			if (line)
				free(line);
			return (NULL);
		}
		if (bytes_read == 0)
			break ;
		line = buff_join(line, buffer);
		if (!line)
			return (NULL);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	char		*line;

	line = NULL;
	if (residual(buffer))
		line = buff_join(line, buffer);
	line = seek_line(buffer, line, fd);
	return (line);
}
