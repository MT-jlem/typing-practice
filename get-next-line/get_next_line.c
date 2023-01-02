/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjlem <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 15:35:01 by mjlem             #+#    #+#             */
/*   Updated: 2021/12/05 21:55:34 by mjlem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read(int fd, char *tmp)
{
	char	*buf;
	int		i;

	buf = malloc (BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	i = 1;
	while (!ft_strchr(tmp, '\n') && i)
	{
		i = read (fd, buf, BUFFER_SIZE);
		if (i == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[i] = '\0';
		tmp = ft_strjoin(tmp, buf);
	}
	free(buf);
	return (tmp);
}

char	*get_line(char *tmp)
{
	char	*line;
	int		l;

	l = 0;
	if (!tmp[l])
		return (NULL);
	while (tmp[l] && tmp[l] != '\n')
		l++;
	if (tmp[l] == '\0')
		line = malloc (l + 1);
	else
		line = malloc (l + 2);
	if (!line)
		return (NULL);
	l = 0;
	while (tmp[l] && tmp[l] != '\n')
	{
		line[l] = tmp[l];
		l++;
	}
	// if (tmp[l] == '\n')
	// 	line[l++] = '\n';
	line[l] = '\0';
	return (line);
}

char	*get_rest(char *tmp)
{
	char	*rest;
	int		l;
	int		i;

	l = 0;
	while (tmp[l] && tmp[l] != '\n')
		l++;
	if (!tmp[l])
	{
		free(tmp);
		return (NULL);
	}
	l++;
	i = ft_strlen(&tmp[l]);
	rest = malloc (i + 1);
	if (!rest)
		return (NULL);
	i = 0;
	while (tmp[l])
		rest[i++] = tmp[l++];
	rest[i] = '\0';
	free(tmp);
	return (rest);
}

char	*get_next_line(int fd)
{
	static char	*tmp;
	char		*line;

	if (BUFFER_SIZE <= 0 || fd == -1)
		return (NULL);
	tmp = ft_read(fd, tmp);
	if (!tmp)
		return (NULL);
	line = get_line(tmp);
	tmp = get_rest(tmp);
	return (line);
}
