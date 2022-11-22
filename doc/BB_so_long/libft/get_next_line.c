/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaillag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 09:43:24 by cgaillag          #+#    #+#             */
/*   Updated: 2022/02/27 13:35:58 by cgaillag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
//#include "../includes/get_next_line.h"
#include "../libft/libft.h"
#include <unistd.h>
#include <stdlib.h>

/*	******************************************************************
 *	********************* Function get_next_line *********************
 *	******************************************************************
 *	Prototype:		char *get_next_line(int fd);
 *	Description:	returns a line read from a file descriptor
 *	Return values:
 *	 - read line for correct behavior
 *	 - NULL when there is nothing else to read or if an error occurred
 *	******************************************************************
 */

// /* 	Function that checks if there is a '\n' in the 'tmp' string and returns
//  *  1 for yes and 0 for no (for the read loop in main fucntion). */
// static int	ft_find_nl(char *tmp, char nl)
// {
// 	int	i;

// 	i = 0;
// 	if (!tmp)
// 		return (0);
// 	while (tmp[i])
// 	{
// 		if (tmp[i] == nl)
// 			return (1);
// 		i ++;
// 	}
// 	return (0);
// }

/* 	Function - locally operational - that updates the 'tmp' value by keeping
 *  only text after the 1st '\n' (remaining text available in 'tmp' after
 *  extracting the 'line' via 'static char *ft_new_linei()' function). */
static char	*ft_new_tmp(char *tmp)
{
	size_t	i;
	size_t	strlen;
	char	*new_tmp;

	i = 0;
	while (tmp[i] && tmp[i] != '\n')
		i++;
	if (tmp[i] && tmp[i] == '\n')
		i++;
	if (!tmp[i])
	{
		free(tmp);
		return (NULL);
	}
	strlen = ft_strlen((const char *) tmp);
	new_tmp = ft_substr((const char *) tmp, (unsigned int) i, strlen - i);
	if (!new_tmp)
	{
		free(new_tmp);
		return (NULL);
	}
	free(tmp);
	tmp = NULL;
	return (new_tmp);
}

/* 	Function - locally operational - that returns the 'next' line read from
 *  the file descriptor and extracted from the static variable tmp (same start
 *  as tmp and end of line with first '\n'). */
static char	*ft_new_line(char *tmp)
{
	size_t	i;
	char	*line;

	i = 0;
	if (!tmp[0])
		return (NULL);
	while (tmp[i] && tmp[i] != '\n')
		i++;
	if (tmp[i] && tmp[i] == '\n')
		i++;
	line = ft_substr((const char *) tmp, 0, i);
	if (!line)
		return (NULL);
	return (line);
}

/*	Initial function to launch 'get_next_line' that allows to read
 *	the text file pointed to by the file descriptor, one line at a time. */
char	*get_next_line(int fd)
{
	int			rv_read;
	char		*buf;
	char		*line;
	static char	*tmp = NULL;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	rv_read = 1;
	while ((ft_is_in_set((const char *) tmp, '\n') == 0) && rv_read != 0)
	{
		rv_read = read(fd, buf, BUFFER_SIZE);
		if (rv_read == -1)
			return (free(buf), NULL);
		buf[rv_read] = '\0';
		tmp = ft_strjoin((const char *) tmp, (const char *) buf);
	}
	free(buf);
	if (!tmp)
		return (NULL);
	line = ft_new_line(tmp);
	tmp = ft_new_tmp(tmp);
	return (line);
}
