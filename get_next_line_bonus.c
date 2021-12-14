/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudy <arudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 11:35:28 by arudy             #+#    #+#             */
/*   Updated: 2021/12/14 13:58:18 by arudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_free(char *s)
{
	free(s);
	return (NULL);
}

char	*ft_trim_stat(char *s)
{
	size_t	i;
	size_t	j;
	char	*dst;

	i = 0;
	j = 0;
	while (s[i] != '\0' && s[i] != '\n')
		i++;
	if (s[i] == '\0')
		return (ft_free(s));
	dst = malloc(sizeof(char) * (ft_strlen(s) - i + 1));
	if (!dst)
		return (NULL);
	i++;
	while (s[i] != '\0')
		dst[j++] = s[i++];
	dst[j] = '\0';
	free(s);
	return (dst);
}

char	*make_line(char *stat)
{
	size_t	i;
	size_t	j;
	char	*line;

	i = 0;
	j = 0;
	if (stat[i] == '\0')
		return (NULL);
	while (stat[i] != '\0' && stat[i] != '\n')
		i++;
	if (stat[i] == '\0')
		line = malloc(sizeof(char) * (i + 1));
	else
		line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (ft_free(stat));
	while (stat[j] != '\0' && stat[j] != '\n')
	{
		line[j] = stat[j];
		j++;
	}
	if (stat[j] == '\n')
		line[j++] = '\n';
	line[j] = '\0';
	return (line);
}

char	*read_line(int fd, char *stat)
{
	int			count;
	char		*buff;

	count = 1;
	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	while (ft_strchr(stat, '\n') == 0 && count > 0)
	{
		count = read(fd, buff, BUFFER_SIZE);
		if (count < 0)
			break ;
		buff[count] = '\0';
		stat = ft_strjoin(stat, buff);
	}
	free(buff);
	return (stat);
}

char	*get_next_line(int fd)
{
	static char	*stat[1024];
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	if (!stat[fd])
	{
		stat[fd] = malloc(sizeof(char) * 1);
		if (!stat[fd])
			return (NULL);
		stat[fd][0] = '\0';
	}
	stat[fd] = read_line(fd, stat[fd]);
	if (!stat[fd])
		return (NULL);
	line = make_line(stat[fd]);
	stat[fd] = ft_trim_stat(stat[fd]);
	return (line);
}
