/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjlem <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 01:01:30 by mjlem             #+#    #+#             */
/*   Updated: 2021/11/14 19:53:16 by mjlem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
char	*ft_strdup(const char *s1);

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	l;
	char	*p;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	l = ft_strlen(s);
	if (start >= l)
		return (ft_strdup(""));
	if (len > l)
		p = (char *) malloc (l - start + 1);
	else
		p = (char *) malloc (len + 1);
	if (!p)
		return (NULL);
	else
	{
		while (len-- && s[start])
			p[i++] = s[start++];
		p[i] = '\0';
	}
	return (p);
}
