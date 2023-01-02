/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjlem <mjlem@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 21:21:58 by mjlem             #+#    #+#             */
/*   Updated: 2022/07/01 21:18:34 by mjlem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
char	*ft_strchr(const char *s, int c);

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	end;

	if (!s1)
		return (NULL);
	while (*s1 && ft_strchr(set, *s1) != NULL)
		s1++;
	end = (ft_strlen(s1));
	while (end && ft_strchr(set, s1[end]) != NULL)
		end--;
	return (ft_substr(s1, 0, end + 1));
}
