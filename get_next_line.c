/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seckhard <seckhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 17:10:58 by seckhard          #+#    #+#             */
/*   Updated: 2023/10/27 21:08:31 by seckhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*str;

	str = NULL;
	if (read(fd, 0, 0) < 0 || BUFFER_SIZE <= 0)
	{
		ft_zero_buffer(buffer);
		return (NULL);
	}
	while (*buffer != 0 || read(fd, buffer, BUFFER_SIZE) > 0)
	{
		str = ft_strjoin(str, buffer);
		if (ft_buffer_manager(buffer))
			break ;
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
