/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaillag <cgaillag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 22:08:18 by cgaillag          #+#    #+#             */
/*   Updated: 2022/11/28 14:39:32 by cgaillag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_only_spechar_at_str_ends(char **map, char c)
{
	int	i;
	int	j;
	int	len;

	i = 1;
	len = (int) ft_strlen(map[0]);
	while (map[i])
	{
		j = 0;
		while (map[i][j] && map[i][j] == ' ')
			j++;
		if (map[i][j] != c)
			return (0);
		j = len - 1;
		while (map[i][j] && map[i][j] == ' ')
			j--;
		if (map[i][j] != c)
			return (0);
		i++;
	}
	return (1);
}

/*  ***** Check - line only contains a set of allowed characters *****
**	Checks if ONLY allowed characters (defined in set) are in the line
**	- if yes    --> return 1
**  - if no     --> return 0
*/
int	ft_only_charset_in_str(char *str, const char *set)
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

	i = 1;
	if (!ft_only_charset_in_str(map[0], "1 "))
		return (ft_err_msg(0, NULL, "map's 1st line is incorrect"));
	if (ft_count_isinset(map[0], '1') < 1)
		return (ft_err_msg(0, NULL, "map's 1st line is incorrect"));
	if (!ft_only_charset_in_str(map[lines - 1], "1 "))
		return (ft_err_msg(0, NULL, "map's last line is incorrect"));
	if (ft_count_isinset(map[lines - 1], '1') < 1)
		return (ft_err_msg(0, NULL, "map's last line is incorrect"));
	if (!ft_only_spechar_at_str_ends(map, '1'))
		return (ft_err_msg(0, NULL, "map's middle lines are incorrect"));
	return (1);
}

/*  ***** Check - map only contains a set of allowed characters *****
**	Checks if ONLY allowed characters (defined in set) are in the map
**	- if yes    --> return 1
**  - if no     --> return 0
*/
int	ft_check_map_only_allowed_set(char **map, int lines, const char *set)
{
	int	i;

	if (!map || !set || lines <= 0)
		return (ft_err_msg(0, NULL, "map is empty / set is empty"));
	i = 0;
	while (map[i])
	{
		if (!ft_only_charset_in_str(map[i], set))
			return (ft_err_msg(0, NULL, "map does contain not allowed char"));
		i++;
	}
	return (1);
}

/*
	/!\ à la pace de 'return (EXIT_FAILURE);

	mettre le message adequat...
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
	if (!ft_check_map_only_allowed_set(map, len, "01 NSEW"))
		return (EXIT_FAILURE);
	if (!ft_check_map_global_struct(map, lines))
		return (EXIT_FAILURE);
	if (!ft_check_map_unique_player(map, lines))
		return (EXIT_FAILURE);
	if (!ft_check_map_enclosed_by_walls(map, lines, len))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
