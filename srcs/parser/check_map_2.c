/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaillag <cgaillag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 22:08:18 by cgaillag          #+#    #+#             */
/*   Updated: 2022/12/15 10:40:36 by cgaillag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*	<SUMMARY> 	check number of spawns (N, S, W, E) 
**				and verify there is only one from all 4
*/
int	ft_check_map_unique_player(char **map, int lines)
{
	int	i;
	int	count;

	i = 1;
	count = 0;
	while (map[i] && i < (lines - 1))
	{
		count += ft_count_isinset(map[i], 'N');
		count += ft_count_isinset(map[i], 'S');
		count += ft_count_isinset(map[i], 'W');
		count += ft_count_isinset(map[i], 'E');
		i++;
	}
	if (count == 0)
		return (ft_msg_1(0, ER_MAP_ERR, NULL, ER_PLY_MISS));
	if (count > 1)
		return (ft_msg_1(0, ER_MAP_ERR, NULL, ER_PLY_TOO));
	return (1);
}

static int	ft_cell_enclosed_by_charset(char **map, int i, int j, char *set)
{
	if (ft_is_in_set(set, map[i - 1][j]))
		return (0);
	if (ft_is_in_set(set, map[i][j - 1]))
		return (0);
	if (ft_is_in_set(set, map[i + 1][j]))
		return (0);
	if (ft_is_in_set(set, map[i][j + 1]))
		return (0);
	return (1);
}

int	ft_check_map_enclosed_by_walls(char **map, int lines, int len)
{
	int	i;
	int	j;

	i = 1;
	while (map[i] && i < (lines - 1))
	{
		j = 1;
		while (j < (len - 1) && map[i][j])
		{
			if (map[i][j] == '0' \
				&& !ft_cell_enclosed_by_charset(map, i, j, " "))
				return (ft_msg_1(0, ER_MAP_OPEN, NULL, ER_PLY_ZERO));
			else if ((map[i][j] == 'N' || map[i][j] == 'S' \
				|| map[i][j] == 'W' || map[i][j] == 'E') \
				&& !ft_cell_enclosed_by_charset(map, i, j, " "))
				return (ft_msg_1(0, ER_MAP_ERR, NULL, ER_PLY_ZERO));
			else if ((j < (len - 1) && map[i][j] == ' ') \
				&& !ft_cell_enclosed_by_charset(map, i, j, "0NSWE"))
				return (ft_msg_1(0, ER_MAP_OPEN, NULL, ER_PLY_ZERO));
			j++;
		}
		i++;
	}
	return (1);
}
