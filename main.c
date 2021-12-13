/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudy <arudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 11:35:23 by arudy             #+#    #+#             */
/*   Updated: 2021/12/13 13:31:20 by arudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int		fd;
	char	*str;

	fd = open("main.c", O_RDONLY);
	if (fd < 0)
		printf("Error\n");
	while (1)
	{
		str = get_next_line(fd);
		if (str == NULL)
			return (0);
		printf("%s", str);
		free(str);
	}
	close(fd);
}
