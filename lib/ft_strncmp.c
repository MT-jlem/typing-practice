/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjlem <mjlem@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 14:50:26 by mjlem             #+#    #+#             */
/*   Updated: 2022/07/01 21:18:44 by mjlem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*s3;
	unsigned char	*s4;

	i = 0;
	s3 = (unsigned char *) s1;
	s4 = (unsigned char *) s2;
	while (n > i)
	{
		if (s3[i] != s4[i])
			return (s3[i] - s4[i]);
		else if (s3[i] == '\0' && s4[i] == '\0')
			return (0);
		i++;
	}
	return (0);
}
