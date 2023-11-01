/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seckhard <seckhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 22:52:13 by seckhard          #+#    #+#             */
/*   Updated: 2023/11/01 17:40:33 by seckhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	buffer[FOPEN_MAX][BUFFER_SIZE + 1];
	char		*str;
	int		i;

	str = NULL;
	i = 0;
	if (fd < 0 || fd > FOPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	while (buffer[fd][0] || read(fd, buffer[fd], BUFFER_SIZE) > 0)
	{
		str = ft_strjoin(str, buffer[fd]);
		if (ft_buffer_manager(buffer[fd]))
			break ;
		i = read(fd, buffer[fd], BUFFER_SIZE);
		if (i < 0)
		{
			free(str);
			str = NULL;
			return (NULL);
		}
	}
	return (str);
}

/*#include <fcntl.h>

int main()
{
	int fd = open("test.txt", O_RDONLY);
	int fd2 = open("test2.txt", O_RDONLY);
	char *line;
	
		line = get_next_line(fd);
		printf("%s", line);
		free (line);
 		line = get_next_line(fd2);
		printf("%s", line);
		free (line);

	return 0;
}*/
