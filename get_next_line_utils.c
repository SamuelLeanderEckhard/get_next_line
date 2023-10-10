/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seckhard <seckhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 16:20:54 by seckhard          #+#    #+#             */
/*   Updated: 2023/10/10 23:05:06 by seckhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *str)
{
	int		n;

	n = 0;
	if (!str)
		return (0);
	while (str[n] != '\0')
		n++;
	return (n);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	char	*str_ptr;

	if (!s1 || !s2)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	str_ptr = str;
	while (*s1)
		*str++ = *s1++;
	while (*s2)
		*str++ = *s2++;
	*str = '\0';
	return (str_ptr);
}

char	*ft_strchr(const char *str, int character)
{
	while (*str != '\0' && *str != (char)character)
		str++;
	if (*str == (char)character)
		return ((char *)str);
	return (NULL);
}

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*dup;

	len = ft_strlen(s);
	dup = (char *)malloc(len + 1);
	if (dup == NULL)
		return (NULL);
	while (!s)
	{
		*dup = *s;
		s++;
		dup++;
	}
	*dup = '\0';
	return (dup);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	n;

	i = 0;
	n = 0;
	str = (char *)malloc(sizeof(*s) * (len + 1));
	if (str == 0)
		return (NULL);
	while (s[i])
	{
		if (i >= start && n < len)
		{
			str[n] = s[i];
			n++;
		}
		i++;
	}
	str[n] = 0;
	return (str);
}
