/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudy <arudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 11:35:26 by arudy             #+#    #+#             */
/*   Updated: 2021/12/09 17:06:34 by arudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <unistd.h>
# include <stdio.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
#endif
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H


char	*get_next_line(int fd);
int		ft_strchr(char *s, char c);

#endif
