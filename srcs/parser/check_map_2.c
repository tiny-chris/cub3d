/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaillag <cgaillag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 22:08:18 by cgaillag          #+#    #+#             */
/*   Updated: 2022/11/28 12:29:49 by cgaillag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
	check how many N / E / S / W
	verify only one from all 4
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
		return (ft_err_msg(1, NULL, "no player"));
	if (count > 1)
		return (ft_err_msg(1, NULL, "more than one player: not allowed"));
	//position du player = dans la map !! a checker
	return (0);
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
			if (map[i][j] == '0')
			{
				if (map[i - 1][j] == ' ' || map[i][j - 1] == ' '
					|| map[i][j + 1] == ' ' || map[i + 1][j + 1] == ' ')
					return (ft_err_msg(0, NULL, "not fully enclosed"));
			}
			j++;
		}
		i++;
	}
	return (1);
}
