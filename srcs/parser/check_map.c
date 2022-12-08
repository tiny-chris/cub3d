/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaillag <cgaillag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 22:08:18 by cgaillag          #+#    #+#             */
/*   Updated: 2022/12/08 12:04:01 by cgaillag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// int	ft_only_spechar_at_str_ends(char **map, char c)
// {
// 	int	i;
// 	int	j;
// 	int	len;

// 	i = 1;
// 	len = (int) ft_strlen(map[0]);
// 	while (map[i])
// 	{
// 		j = 0;
// 		while (map[i][j] && map[i][j] == ' ')
// 			j++;
// 		if (map[i][j] != c)
// 			return (0);
// 		j = len - 1;
// 		while (map[i][j] && map[i][j] == ' ')
// 			j--;
// 		if (map[i][j] != c)
// 			return (0);
// 		i++;
// 	}
// 	return (1);
// }

static int	ft_only_spechar_at_str_ends(char *map, char c)
{
	int	i;

	i = 0;
	while (map[i] && map[i] == ' ')
		i++;
	if (map[i] != c)
		return (0);
	i = (int) ft_strlen(map) - 1;
	while (map[i] && map[i] == ' ')
		i--;
	if (map[i] != c)
		return (0);
	return (1);
}

/*  ***** Check - line only contains a set of allowed characters *****
**	Checks if ONLY allowed characters (defined in set) are in the line
**	- if yes    --> return 1
**  - if no     --> return 0
*/
static int	ft_only_charset_in_str(char *str, const char *set)
{
	int	i;
	int	len;

	if (!str || !set)
		return (0);
	len = ft_strlen_spechar(str, '\n');
	i = 0;
	while (i < len)
	{
		if (!ft_is_in_set(set, str[i]))
			return (0);
		i++;
	}
	return (1);
}

// 1ere ligne = que des 1 ou ' ' mais rien d'autre, au moins un '1'
// idem derniere ligne (1ere ligne)
// inside : commence par un 1 et finit par un 1
int	ft_check_map_global_struct(char **map, int lines)
{
	int	i;

	i = 0;
	if (!ft_only_charset_in_str(map[i], "1 ")
		|| (ft_count_isinset(map[i], '1') < 1))
		return (ft_msg_1(0, ER_MAP_ERR, ER_WAL_MISS, ER_MAP_FIRST));
	i++;
	while (i < (lines - 1) && map[i])
	{
		if (!ft_only_spechar_at_str_ends(map[i], '1'))
			return (ft_msg_1(0, ER_MAP_ERR, ER_WAL_MISS, ER_MAP_MIDDLE));
		i++;
	}
	if (!ft_only_charset_in_str(map[i], "1 ")
		|| (ft_count_isinset(map[i], '1') < 1))
		return (ft_msg_1(0, ER_MAP_ERR, ER_WAL_MISS, ER_MAP_LAST));
	return (1);
}

/*  ***** Check - map only contains a set of allowed characters *****
**	Checks if ONLY allowed characters (defined in set) are in the map
**	- if yes    --> return 1
**  - if no     --> return 0
*/
int	ft_check_map_only_set(char **map, int lines, const char *set)
{
	int	i;

	if (!map || !set || lines <= 0)
		return (ft_msg_1(0, ER_MAP_ERR, NULL, ER_MAP_NONE));
	i = 0;
	while (map[i])
	{
		if (!ft_only_charset_in_str(map[i], set))
			return (ft_msg_1(0, ER_MAP_ERR, map[i], ER_MAP_UNEX));
		i++;
	}
	return (1);
}

/*

*/
int	ft_check_map_err(t_base *base)
{
	char	**map;
	int		lines;
	int		len;

	map = base->map_base;
	lines = ft_lines_tabstr(map);
	len = ft_strlen(map[0]);
	if (!map)
		return (EXIT_FAILURE);
	if (!ft_check_map_only_set(map, len, "01 NSEW"))
		return (EXIT_FAILURE);
	if (!ft_check_map_global_struct(map, lines))
		return (EXIT_FAILURE);
	if (!ft_check_map_unique_player(map, lines))
		return (EXIT_FAILURE);
	if (!ft_check_map_enclosed_by_walls(map, lines, len))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
