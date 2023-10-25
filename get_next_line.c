/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seckhard <seckhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 20:22:53 by seckhard          #+#    #+#             */
/*   Updated: 2023/10/25 16:52:31 by seckhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_nl(int fd, char *saved)
{
	char	buffer[BUFFER_SIZE + 1];
	int		bytes_read;
	char	*temp;

	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read <= 0)
		return (NULL);
	buffer[bytes_read] = '\0';
	if (!saved)
		saved = ft_strdup("");
	temp = saved;
	saved = ft_strjoin(saved, buffer);
	free(temp);
	return (saved);
}

char	*get_next_line(int fd)
{
	static char	*saved = NULL;
	char		*line;
	char		*temp;
	char		*newline_pos;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	newline_pos = ft_strchr(saved, '\n');
	while (!newline_pos)
	{
		saved = read_nl(fd, saved);
		if (!saved)
			return (NULL);
		newline_pos = ft_strchr(saved, '\n');
	}
	*newline_pos = '\0';
	line = ft_strdup(saved);
	temp = ft_strdup(newline_pos + 1);
	free(saved);
	saved = temp;
	return (line);
}

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 32
#endif

int main(void)
{
    int fd = open("test.txt", O_RDONLY);
    char *line;

    if (fd == -1)
        return (1);

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("Line: %s\n", line);
        free(line);
    }

    close(fd);
    return (0);
}
