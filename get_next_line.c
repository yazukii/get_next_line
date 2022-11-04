/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidouiss <yidouiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 13:28:04 by yidouiss          #+#    #+#             */
/*   Updated: 2022/11/04 17:48:36 by yidouiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

char	*getend(char *end)
{
	char	*str;
	int		i;

	i = 0;
	while (end[i] != '\n' && end[i] != '\0')
		i++;
	if (!end[i])
		return (end);
	str = malloc(sizeof(char) * i);
	i = 0;
	while (end[i] != '\n')
	{
		str[i] = end[i];
		i++;
	}
	str[i] = '\n';
	return (str);
}

char	*getstart(char *start)
{
	char	*str;
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (start[i] != '\n' && start[i])
		i++;
	i++;
	if (!start[i])
		return (NULL);
	str = malloc(sizeof(char) * BUFFER_SIZE - i);
	while (start[i])
	{
		str[j] = start[i];
		i++;
		j++;
	}
	str[j] = '\0';
	return (str);
}

char	*gnl(int fd)
{
	static char	*start;
	char		*buff;
	char		*full;
	static int	sw;

	buff = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (read(fd, buff, BUFFER_SIZE) < 1)
	{
		free(buff);
		return (NULL);
	}
	full = malloc(sizeof(char) * BUFFER_SIZE);
	if (sw != 0)
		full = start;
	sw = 1;
	while (ft_strchr(buff, '\n') == -1 && buff)
	{
		full = ft_strjoin(full, buff);
		read(fd, buff, BUFFER_SIZE);
	}
	full = ft_strjoin(full, getend(buff));
	start = getstart(buff);
	free(buff);
	return (full);
}

char	*get_next_line(int fd)
{
	static char	*full;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	full = gnl(fd);
	if (!full)
	{
		free(full);
		return (NULL);
	}
	return (full);
}

int main(void)
{
	int fd;

	fd = open("test", O_RDONLY);
	printf("%s", get_next_line(fd));
	close(fd);
	return (0);
}
//TODO doesnt work when file is empty