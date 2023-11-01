/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seckhard <seckhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 21:44:04 by seckhard          #+#    #+#             */
/*   Updated: 2023/11/01 17:39:14 by seckhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*str;
	int			i;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	i = 0;
	str = NULL;
	while (*buffer != 0 || read(fd, buffer, BUFFER_SIZE) > 0)
	{
		str = ft_strjoin(str, buffer);
		if (ft_buffer_manager(buffer))
			break ;
		i = read(fd, buffer, BUFFER_SIZE);
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
