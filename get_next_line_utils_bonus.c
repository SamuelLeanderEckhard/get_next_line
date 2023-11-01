/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seckhard <seckhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 22:59:19 by seckhard          #+#    #+#             */
/*   Updated: 2023/11/01 17:41:02 by seckhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	return (i + (str[i] == '\n'));
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		size;
	int		i;
	int		x;
	char	*str;

	i = 0;
	x = -1;
	size = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	while (s1 && s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[++x])
	{
		str[i++] = s2[x];
		if (s2[x] == '\n')
			break ;
	}
	str[i] = '\0';
	free(s1);
	return (str);
}

int	ft_buffer_manager(char *buffer)
{
	int	flag;
	int	i;
	int	x;

	flag = 0;
	i = 0;
	x = 0;
	while (buffer[i])
	{
		if (flag)
			buffer[x++] = buffer[i];
		if (buffer[i] == '\n')
			flag = 1;
		buffer[i++] = '\0';
	}
	return (flag);
}
