/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-cunh <dda-cunh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 16:12:02 by dda-cunh          #+#    #+#             */
/*   Updated: 2023/06/06 16:44:10 by dda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	buffer[MAX_FDS][BUFFER_SIZE];
	char		*line;
	int			r;

	line = "";
	if (fd >= MAX_FDS || fd < 0)
		return (NULL);
	if (residual(buffer[fd]))
	{
		if (buff_endl(buffer[fd]))
			return (buffjoin(line, buffer[fd], 0, -1));
		line = buffjoin(line, buffer[fd], 0, -1);
	}
	r = 1;
	line = seek_line(buffer[fd], line, r, fd);
	return (line);
}
