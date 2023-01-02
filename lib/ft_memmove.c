/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjlem <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 00:08:55 by mjlem             #+#    #+#             */
/*   Updated: 2021/11/14 00:49:13 by mjlem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*d;
	char	*s;
	size_t	i;

	d = (char *)dst;
	s = (char *)src;
	i = 0;
	if (!dst && !src)
		return (0);
	else if (s > d)
		ft_memcpy(d, s, len);
	else
	{
		i = len - 1;
		while (len)
		{
			d[i] = s[i];
			i--;
			len--;
		}
	}
	return (d);
}
