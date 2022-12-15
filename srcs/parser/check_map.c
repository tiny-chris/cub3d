/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaillag <cgaillag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 22:08:18 by cgaillag          #+#    #+#             */
/*   Updated: 2022/12/15 10:42:26 by cgaillag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

int	ft_check_map_global_struct(t_base *b, char **map, int lines)
{
	int	i;

	i = 0;
	if (!ft_only_charset_in_str(map[i], "1 ")
		|| (ft_count_isinset(map[i], '1') < 1))
		return (ft_msg_2(0, ER_MAP_OPEN, "line ", ft_itoa2(b->map_ln + i)));
	i++;
	while (i < (lines - 1) && map[i])
	{
		if (!ft_only_spechar_at_str_ends(map[i], '1'))
		{
			return (ft_msg_2(0, ER_MAP_OPEN, "line ", ft_itoa2(b->map_ln + i)));
		}
		i++;
	}
	if (!ft_only_charset_in_str(map[i], "1 ")
		|| (ft_count_isinset(map[i], '1') < 1))
		return (ft_msg_2(0, ER_MAP_OPEN, "line ", ft_itoa2(b->map_ln + i)));
	return (1);
}

int	ft_check_map_only_set(t_base *b, char **map, int lines, const char *set)
{
	int	i;

	if (!map || !set || lines <= 0)
		return (ft_msg_1(0, NULL, NULL, ER_MAP_NONE));
	i = 0;
	while (map[i])
	{
		if (!ft_only_charset_in_str(map[i], set))
			return (ft_msg_2(0, ER_MAP_UNEX, "line ", ft_itoa2(b->map_ln + i)));
		i++;
	}
	return (1);
}

/*  ***** Parsing - check map content *****
**  *************************
**  <SUMMARY>	Check each case:
**				- map exists and is not empty
**				- map contains ONLY allowed characters from given set
**				- map outside characters are walls
**				- map has only one player
**				- map is closed
**	<RETURN>	- if all ok : 	0 (EXIT_SUCCESS)
**				- if not :		1 (EXIT_FAILURE) + error message
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
	if (!ft_check_map_only_set(base, map, len, "01 NSEW"))
		return (EXIT_FAILURE);
	if (!ft_check_map_global_struct(base, map, lines))
		return (EXIT_FAILURE);
	if (!ft_check_map_unique_player(map, lines))
		return (EXIT_FAILURE);
	if (!ft_check_map_enclosed_by_walls(map, lines, len))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
