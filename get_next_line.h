/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudy <arudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 11:35:26 by arudy             #+#    #+#             */
/*   Updated: 2021/12/10 18:02:08 by arudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

char	*get_next_line(int fd);
char	*ft_strcpy(char *dest, char *src);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strchr(char *s, char c);
char	*ft_trim_stat(char *s);
size_t	ft_strlen(char *str);

#endif
