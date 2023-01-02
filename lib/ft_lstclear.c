/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjlem <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 19:21:01 by mjlem             #+#    #+#             */
/*   Updated: 2021/11/26 11:37:08 by mjlem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*p;

	p = NULL;
	if (!*lst)
		return ;
	while (*lst)
	{
		p = *lst;
		*lst = (*lst)-> next;
		del(p -> content);
		free(p);
	}
}
