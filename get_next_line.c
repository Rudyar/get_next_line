/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudy <arudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 11:35:28 by arudy             #+#    #+#             */
/*   Updated: 2021/12/09 17:39:52 by arudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*stat;
	char		*buff;
	char 		*line;
	int			count;

	stat = malloc(sizeof(char) * 1);
	if (!stat)
		retrun (NULL);
	count = 1;
	stat[0]= 0;
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
	// line = // creer la ligne jusquau \n
}
