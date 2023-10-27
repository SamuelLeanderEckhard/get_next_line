/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seckhard <seckhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 22:52:13 by seckhard          #+#    #+#             */
/*   Updated: 2023/10/27 23:04:19 by seckhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <get_next_line_bonus.h>

char	*get_next_line(int fd)
{
	static char	buffer[FOPEN_MAX][BUFFER_SIZE + 1];
	char		*str;
	int			i;

	str = NULL;
	if (read(fd, 0, 0) < 0 || BUFFER_SIZE <= 0)
	{
		i = 0;
		if (fd >= 0 && fd <= FOPEN_MAX)
		{
			while (buffer[fd][i])
			{
				buffer[fd][i++] = 0;
			}
		}
		return (NULL);
	}
	while (buffer[fd][0] != 0 || read(fd, buffer[fd], BUFFER_SIZE) > 0)
	{
		str = ft_strjoin(str, buffer[fd]);
		if (ft_buffer_manager(buffer[fd]))
			break ;
	}
	return (str);
}

/*#include <fcntl.h>

int main()
{
	int fd = open("teste.txt", O_RDONLY);
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
