/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmelard <lmelard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 19:10:42 by cgaillag          #+#    #+#             */
/*   Updated: 2022/11/28 16:43:05 by lmelard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*	<SUMMARY> 	Open a file on "read only" mode
**
**	<PARAM>		char *file (to open)
**	<RETURN>	a file descriptor or -1, if could not open the file
*/
int	ft_open_read(const char *file)
{
	int	fd;
	int	val_exit;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		val_exit = errno;
		ft_putendl_fd(strerror(errno), 2);
		ft_putendl_fd("fd: ", 2);
		perror(file);
		exit(val_exit); // ou exit(errno);
	}
	return (fd);
}

/*	Calculates the length of the string pointed to by str, excluding the
**	termination null byte ('\0') and provided character (e.g. '\n')
*/
int	ft_strlen_spechar(const char *str, char spe_c)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] == spe_c)
			return (i);
		i++;
	}
	return (i);
}

int	ft_len_delspace_str(char *str)
{
	int	i;
	int	len;

	len = (int) ft_strlen(str);
	i = 0;
	if (!str || len == 0)
		return (0);
	while (str[i])
	{
		if (str[i] == ' ')
			len--;
		i++;
	}
	return (len);
}

/*	Counts the number of strings of a char**
*/
int	ft_lines_tabstr(char **tab_str)
{
	int		i;

	if (!tab_str)
		return (0);
	i = 0;
	while (tab_str[i])
		i++;
	return (i);
}

/*	Allocates sufficient memory for a copy of a table of int, does the copy
**  and returns a pointer to it.
**	i.e. duplicate a table of int
*/
int	*ft_intdup(int *tab, int size)
{
	int	i;
	int	*copy;

	i = 0;
	copy = (int *)malloc(sizeof(int) * size);
	if (copy == NULL)
		return (0);
	while (i < size)
	{
		copy[i] = tab[i];
		i++;
	}
	return (copy);
}