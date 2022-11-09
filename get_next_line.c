/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidouiss <yidouiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 13:28:04 by yidouiss          #+#    #+#             */
/*   Updated: 2022/11/09 17:07:47 by yidouiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

char	*ft_free(char *buffer, char *buf)
{
	char	*temp;

	temp = ft_strjoin(buffer, buf);
	free(buffer);
	return (temp);
}

char	*getend(char *end)
{
	char	*str;
	int		i;

	i = 0;
	if (!end[i])
		return (NULL);
	while (end[i] != '\n' && end[i])
		i++;
	str = ft_calloc(i + 2, sizeof(char));
	i = 0;
	while (end[i] != '\n' && end[i])
	{
		str[i] = end[i];
		i++;
	}
	if (end[i] && end[i] == '\n')
		str[i++] = '\n';
	return (str);
}

char	*getstart(char *start)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	while (start[i] != '\n' && start[i])
		i++;
	if (!start[i])
	{
		free(start);
		return (NULL);
	}
	str = ft_calloc((ft_strlen(start) - i + 1), sizeof(char));
	i++;
	j = 0;
	while (start[i])
	{
		str[j] = start[i];
		i++;
		j++;
	}
	free(start);
	return (str);
}

char	*gnl(int fd, char *full)
{
	char		*buff;
	int			bytes;

	if (!full)
		full = ft_calloc(1, 1);
	buff = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	bytes = 1;
	while (bytes > 0)
	{
		bytes = read(fd, buff, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[bytes] = 0;
		full = ft_free(full, buff);
		if (ft_strchr(buff, '\n'))
			break ;
	}
	free(buff);
	return (full);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*buff;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free (buffer);
		buffer = 0;
		return (NULL);
	}
	buffer = gnl(fd, buffer);
	if (!buffer)
		return (NULL);
	buff = getend(buffer);
	buffer = getstart(buffer);
	return (buff);
}