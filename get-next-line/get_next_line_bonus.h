/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjlem <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 21:53:57 by mjlem             #+#    #+#             */
/*   Updated: 2021/12/05 21:54:06 by mjlem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*ft_read_bonus(int fd, char *tmp);
char	*get_rest_bonus(char *tmp);
char	*get_line_bonus(char *tmp);
int		ft_strchr_bonus(char	*tmp, char c);
char	*ft_strjoin_bonus(char *s1, char *s2);
int		ft_strlen_bonus(char *s);
char	*ft_strdup_bonus(char *s1);

#endif
