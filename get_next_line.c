/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudy <arudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 11:35:28 by arudy             #+#    #+#             */
/*   Updated: 2021/12/10 16:54:42 by arudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_trim_stat(char *s)
{
	size_t	i;
	size_t	j;
	char	*dst;

	i = 0;
	dst = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!dst)
		return (NULL);
	dst = ft_strcpy(dst, s);
	while (s && s[i] != '\n')
		i++;
	i++;
	s = malloc(sizeof(char) * (ft_strlen(dst) - i));
	if (!s)
		return (NULL);
	j = 0;
	while (s && dst && j < ft_strlen(dst))
	{
		s[j] = dst[i];
		j++;
		i++;
	}
	s[j] = '\0';
	return (s);
}

char	*make_line(char *stat)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	j = 0;
	while (stat && stat[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 1));
	if (!line)
	{
		free(stat);
		return (NULL);
	}
	while (j <= i)
	{
		line[j] = stat[j];
		j++;
	}
	line[j] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*stat;
	char		*buff;
	char		*line;
	int			count;

	if (!stat)
	{
		stat = malloc(sizeof(char) * 1);
		stat[0] = '\0';
	}
	if (!stat || fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	count = 1;
	while (!(ft_strchr(stat, '\n')) && count != 0)
	{
		buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buff)
		{
			free(stat);
			return (NULL);
		}
		count = read(fd, buff, BUFFER_SIZE);
		stat = ft_strjoin(stat, buff);
		free(buff);
	}
	stat = ft_trim_stat(stat);
	line = make_line(stat);
	return (line);
}
