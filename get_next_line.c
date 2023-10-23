/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seckhard <seckhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 20:22:53 by seckhard          #+#    #+#             */
/*   Updated: 2023/10/23 23:26:58 by seckhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	read_line(int fd, char **line, char **remainder)
{
	char		buffer[BUFFER_SIZE + 1];
	int			bytes_read;
	char		*tmp;
	static char	*remaining_data = NULL;

	bytes_read = read(fd, buffer, BUFFER_SIZE)

	if (fd < 0 || !line)
		return (-1);
	if (!remaining_data)
		remaining_data = ft_strdup("");
	while (bytes_read > 0)
	{
		buffer[bytes_read] = '\0';
		tmp = ft_strjoin(remaining_data, buffer);
		free(remaining_data);
		remaining_data = tmp;
		if (ft_strchr(buffer, '\n'))
			return (find_newline(line));
	}
	if (bytes_read == 0 && remaining_data[0] != '\0')
		return (find_newline(line));
	free(remaining_data);
	remaining_data = NULL;
	return (0);
}

int	find_newline(char **line)
{
	char	*newline_pos;
	char	*tmp;

	newline_pos = ft_strchr(remaining_data, '\n');
	if (newline_pos != NULL)
	{
		*newline_pos = '\0';
		*line = ft_strdup(remaining_data);
		*tmp = ft_strdup(newline_pos + 1);
		free(remaining_data);
		remaining_data = tmp;
		return (1);
	}
	return (0);
}

int	get_next_line(int fd, char **line)
{
	if (read_line(fd, line) == 1)
		return (1);
	return (0);
}
