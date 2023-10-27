/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seckhard <seckhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 20:23:07 by seckhard          #+#    #+#             */
/*   Updated: 2023/10/27 21:30:29 by seckhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# include <stdio.h>

void	ft_zero_buffer(char *buf);
int	ft_buffer_manager(char *buffer);
int	ft_strlen(const char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*get_next_line(int fd);

#endif
