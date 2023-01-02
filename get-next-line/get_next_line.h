/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjlem <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 16:12:04 by mjlem             #+#    #+#             */
/*   Updated: 2021/12/05 21:48:24 by mjlem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"

#define BUFFER_SIZE 1000

char	*get_next_line(int fd);
char	*ft_read(int fd, char *tmp);
char	*get_rest(char *tmp);
int		ft_strchr(char	*tmp, char c);
char	*ft_strjoin(char *s1, char *s2);
// int		ft_strlen(char *s);
char	*ft_strdup(char *s1);

#endif
