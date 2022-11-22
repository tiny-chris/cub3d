/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_checks_map2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaillag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 00:06:30 by cgaillag          #+#    #+#             */
/*   Updated: 2022/06/28 00:06:39 by cgaillag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../libft/libft.h"

/*  ***** Check - map is rectangular *****
**	Checks if all the lines have the same length
**	- if yes    --> return 1
**  - if no     --> return 0
*/
int	ft_check_rect_len_sl(char **map)
{
	int	i;
	int	len_line;

	if (!map)
		return (0);
	i = 1;
	len_line = ft_strlen_spechar(map[0], '\n');
	while (map[i])
	{
		if (ft_strlen_spechar(map[i], '\n') != len_line)
			return (0);
		i++;
	}
	return (1);
}

/*  ***** Check - map contains a given character *****
**	Checks if char 'c' is in the map and how many times
**	- if yes    --> return 1
**  - if no     --> return 0
**	Useful for:
**	- unique player P
** 	- min of 1 collectible
**	- min of 1 exit
*/
int	ft_count_char_sl(char **map, int lines, char c)
{
	int				i;
	int				j;
	int				len_lines;
	int				c_count;
	unsigned char	uc;

	if (!map)
		return (0);
	i = 0;
	len_lines = ft_strlen_spechar(map[0], '\n');
	c_count = 0;
	uc = (unsigned char) c;
	while (i < lines)
	{
		j = 0;
		while (j < len_lines)
		{
			if (map[i][j] == uc)
				c_count++;
			j++;
		}
		i++;
	}
	return (c_count);
}

/*  ***** Check - map only contains a set of allowed characters *****
**	Checks if ONLY allowed characters (defined in set) are in the map
**	- if yes    --> return 1
**  - if no     --> return 0
*/
int	ft_check_allw_char_sl(char **map, int lines, const char *set)
{
	int	i;
	int	j;
	int	len_lines;

	if (!map || !set || lines <= 0)
		return (0);
	len_lines = ft_strlen_spechar(map[0], '\n');
	i = 0;
	while (i < lines)
	{
		j = 0;
		while (j < len_lines)
		{
			if (!ft_is_in_set(set, map[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

/*  ***** Check - lines or columns are only walls *****
**	Sub function that counts, depending on the provided axis (x or y),
**	how many characters of the line or column are '1' (wall) 
**	Return values: count of '1'
*/

int	ft_is_wall_sl(char **map, int lines, char axis, int i)
{
	int	len_lines;
	int	ax;
	int	count;

	count = 0;
	ax = -1;
	if (axis == 'y')
	{
		while (++ax < lines)
		{
			if (map[ax][i] == '1')
				count++;
		}
	}
	else if (axis == 'x')
	{
		len_lines = ft_strlen_spechar(map[0], '\n');
		while (++ax < len_lines)
		{
			if (map[i][ax] == '1')
				count++;
		}
	}
	return (count);
}

/*  ***** Check - map is surrounded by walls *****
**	Checks if the map is closed by walls (everywhere) 
**	- if yes    --> return 1
**  - if no     --> return 0
*/
int	ft_check_walls_sl(char **map, int lines)
{
	int	len_lines;

	if (!map || lines <= 0)
		return (0);
	len_lines = ft_strlen_spechar(map[0], '\n');
	if ((ft_is_wall_sl(map, lines, 'x', 0) != len_lines)
		|| (ft_is_wall_sl(map, lines, 'x', (lines - 1)) != len_lines)
		|| (ft_is_wall_sl(map, lines, 'y', 0) != lines)
		|| (ft_is_wall_sl(map, lines, 'y', (len_lines - 1)) != lines))
		return (0);
	return (1);
}
