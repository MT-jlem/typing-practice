/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjlem <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 23:20:03 by mjlem             #+#    #+#             */
/*   Updated: 2021/12/05 23:13:14 by mjlem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strchr_bonus(char	*tmp, char c)
{
	int	i;

	if (!tmp)
		return (0);
	i = 0;
	while (tmp[i])
	{
		if (tmp[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_strlen_bonus(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup_bonus(char *s1)
{
	char	*p;
	int		l;
	int		i;

	i = 0;
	l = ft_strlen_bonus(s1) + 1;
	p = (char *) malloc (l);
	if (!p)
		return (0);
	while (s1[i])
	{
		p[i] = s1[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

char	*ft_strjoin_bonus(char *s1, char *s2)
{
	int		i;
	int		l;
	char	*k;
	int		j;

	if (!s2)
		return (NULL);
	if (!s1)
		s1 = ft_strdup_bonus("");
	i = ft_strlen_bonus(s1);
	l = ft_strlen_bonus(s2);
	k = (char *) malloc (i + l + 1);
	if (!k)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
		k[j++] = s1[i++];
	l = 0;
	while (s2[l])
		k[j++] = s2[l++];
	k[j] = '\0';
	free(s1);
	return (k);
}