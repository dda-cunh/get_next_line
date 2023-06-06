/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-cunh <dda-cunh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 16:12:19 by dda-cunh          #+#    #+#             */
/*   Updated: 2023/06/06 16:45:15 by dda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2048
# endif
# ifndef MAX_FDS
#  define MAX_FDS 128
# endif

char		*seek_line(char *buffer, char *line, int r, int fd);
char		*buffjoin(char *s1, char *s2, int i, int j);
char		*alloc_concat(char *line, char *buff);
char		*get_next_line(int fd);
int			residual(char *buffer);
int			buff_endl(char *buffer);

#endif