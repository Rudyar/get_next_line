/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudy <arudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 11:35:28 by arudy             #+#    #+#             */
/*   Updated: 2021/12/11 13:52:07 by arudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_trim_stat(char *s)
{
	size_t	i;
	size_t	j;
	char	*dst;

	i = 0;
	j = 0;
	while (s && s[i] != '\n')
		i++;
	i++;
	dst = malloc(sizeof(char) * (ft_strlen(s) - i + 1));
	if (!dst)
		return (NULL);
	while (s[i])
	{
		dst[j] = s[i];
		j++;
		i++;
	}
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
	while (stat[i] && stat[i] != '\n')
		i++;
	if (stat[i] == '\n')
		line = malloc(sizeof(char) * (i + 2));
	else
		line = malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	i++;
	while (stat[j] && stat[j] != '\n')
	{
		line[j] = stat[j];
		j++;
	}
	if (stat[j] == '\n')
		line[j++] = '\n';
	line[j] = '\0';
	return (line);
}

char	*ft_error(char *buff, char *stat)
{
	free(buff);
	free(stat);
	return (NULL);
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
		count = read(fd, buff, BUFFER_SIZE);
		if (count == -1 || !buff)
			return (ft_error(buff, stat));
		stat = ft_strjoin(stat, buff);
		// printf("%s\n", buff);
		free(buff);
	}
	line = make_line(stat);
	stat = ft_trim_stat(stat);
	return (line);
}
