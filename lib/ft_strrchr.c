/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjlem <mjlem@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 13:30:00 by mjlem             #+#    #+#             */
/*   Updated: 2022/07/01 21:18:37 by mjlem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		l;
	char	ch;

	ch = (char)c;
	l = ft_strlen(s);
	while (l >= 0)
	{
		if (s[l] == ch)
			return ((char *)&s[l]);
		l--;
	}
	return (NULL);
}
