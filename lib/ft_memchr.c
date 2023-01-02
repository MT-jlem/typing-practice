/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjlem <mjlem@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 18:07:49 by mjlem             #+#    #+#             */
/*   Updated: 2022/07/01 21:19:45 by mjlem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char			*ss;
	size_t			i;

	ss = (char *) s;
	i = 0;
	while (n > i)
	{
		if ((unsigned char)ss[i] == (unsigned char)c)
			return (&ss[i]);
		i++;
	}
	return (NULL);
}
