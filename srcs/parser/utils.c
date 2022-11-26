/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaillag <cgaillag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 19:10:42 by cgaillag          #+#    #+#             */
/*   Updated: 2022/11/26 04:21:38 by cgaillag         ###   ########.fr       */
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
	dprintf(2, "len_delspace_str = %d\n", len);
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

/*	***************************************************************************
 *	Function that can converts a string into a numeric value of 'int' type.
 *	(atoi = ASCII to integer)
 *
 *	Value of INT_MAX is +2147483647
 *	Value of INT_MIN is - 2147483648
 * */

static int	ft_isspace(char c)
{
	if (c == '\t' || c == '\n' || c == '\v' || c == '\f'
		|| c == '\r' || c == ' ')
		return (1);
	return (0);
}

static int	ft_update_sign(char c, int *neg_val)
{
	if (c == '+' || c == '-')
	{
		if (c == '-')
			*neg_val = -1;
		else
			*neg_val = 1;
		return (1);
	}
	return (0);
}

int	ft_atoi_cub(char *str)
{
	int	neg_val;
	int	nb;
	int	i;

	neg_val = 1;
	nb = 0;
	i = 0;
	while (str[i] && ft_isspace(str[i]))
		i++;
	if (ft_update_sign(str[i], &neg_val))
	{
		i++;
		if (str[i] == '\0')
			return (-1);
	}
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 0)
			return (-1);
		nb = nb * 10 + (str[i] - 48);
		i++;
	}
	return (neg_val * nb);
}
