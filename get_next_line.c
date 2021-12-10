/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudy <arudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 11:35:28 by arudy             #+#    #+#             */
/*   Updated: 2021/12/10 10:48:50 by arudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*make_line(char *stat)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	j = 0;
	while (stat && stat[i] != '\n')
		i++;
	line = malloc(sizeof(char *) * (i + 1));
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
	int			count;

	if (!stat)
		stat = malloc(sizeof(char) * 1);
	if (!stat || fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	count = 1;
	stat[0] = '\0';
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
	printf("stat : %s %ld\n", stat, ft_strlen(stat));
	return (make_line(stat));
}
