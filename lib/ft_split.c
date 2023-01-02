/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjlem <mjlem@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 18:50:48 by mjlem             #+#    #+#             */
/*   Updated: 2022/07/02 16:07:09 by mjlem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_count(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

static char	**a_free(char **a)
{
	int	i;

	i = 0;
	while (a[i])
	{
		free(a[i]);
		i++;
	}
	free(a);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**a;
	int		len;
	int		i;

	if (!s)
		return (NULL);
	a = (char **) malloc ((word_count(s, c) + 1) * sizeof(char *));
	if (!a)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		len = 0;
		while (s[len] != c && s[len])
			len++;
		if (*s != c && *s)
			a[i++] = ft_substr(s, 0, len);
		if (len != 0 && !a[i - 1])
			return (a_free(a));
		s += len;
	}
	a[i] = NULL;
	return (a);
}
