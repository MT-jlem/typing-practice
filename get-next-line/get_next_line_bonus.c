/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjlem <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 23:14:59 by mjlem             #+#    #+#             */
/*   Updated: 2021/12/05 21:52:36 by mjlem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_read_bonus(int fd, char *tmp)
{
	char	*buf;
	int		i;

	buf = malloc (BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	i = 1;
	while (!ft_strchr_bonus(tmp, '\n') && i)
	{
		i = read (fd, buf, BUFFER_SIZE);
		if (i == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[i] = '\0';
		tmp = ft_strjoin_bonus(tmp, buf);
	}
	free(buf);
	return (tmp);
}

char	*get_line_bonus(char *tmp)
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
	if (tmp[l] == '\n')
		line[l++] = '\n';
	line[l] = '\0';
	return (line);
}

char	*get_rest_bonus(char *tmp)
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
	i = ft_strlen_bonus(&tmp[l]);
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
	static char	*tmp[10240];
	char		*line;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	tmp[fd] = ft_read_bonus(fd, tmp[fd]);
	if (!tmp[fd])
		return (NULL);
	line = get_line_bonus(tmp[fd]);
	tmp[fd] = get_rest_bonus(tmp[fd]);
	return (line);
}
