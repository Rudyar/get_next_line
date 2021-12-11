/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudy <arudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 11:35:23 by arudy             #+#    #+#             */
/*   Updated: 2021/12/11 11:43:31 by arudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int	main(void)
{
	int	fd;

	fd = open("test.txt", O_RDONLY);
	printf("Ligne 1 : %s", get_next_line(fd));
	printf("Ligne 2 : %s", get_next_line(fd));
	printf("Ligne 3 : %s", get_next_line(fd));
	printf("Ligne 4 : %s", get_next_line(fd));
	printf("Ligne 5 : %s", get_next_line(fd));
	printf("Ligne 6 : %s", get_next_line(fd));
	printf("Ligne 7 : %s", get_next_line(fd));
	printf("Ligne 8 : %s", get_next_line(fd));
	return (0);
}
