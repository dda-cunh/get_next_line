/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-cunh <dda-cunh@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 21:04:20 by dda-cunh          #+#    #+#             */
/*   Updated: 2023/12/31 13:22:16 by dda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
// # include <fcntl.h>
// # include <stdio.h>

# ifndef BUFFER_SIZE
#  define   BUFFER_SIZE 4096
# endif

typedef enum e_bool
{
	FALSE = 0,
	TRUE = 1
}	t_bool;

char		*line_join(char *line, char *buff);
char		*get_next_line(int fd);

#endif