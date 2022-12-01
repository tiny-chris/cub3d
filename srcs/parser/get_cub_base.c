/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cub_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaillag <cgaillag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 22:08:18 by cgaillag          #+#    #+#             */
/*   Updated: 2022/12/01 17:23:46 by cgaillag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*  ***** Initialising - get file content *****
**  *************************
**  <SUMMARY>	Get the file content in a char **
**				and fill it by reading the file (1 string = 1 line)
*/
char	**ft_get_file_base(char	*file)
{
	char	**file_base;
	int		fd;
	int		lines;
	int		i;

	fd = ft_open_read(file);
	lines = ft_count_lines_gnl(file);
	if (lines == 0)
		exit (ft_err_msg_1(1, "TBD", NULL, NULL));
	i = 0;
	file_base = ft_magic_malloc(MALLOC + TAB_STR2, NULL, (lines + 1));
	file_base[i] = get_next_line(fd);
	while (file_base[i])
	{
		i++;
		file_base[i] = get_next_line(fd);
	}
	file_base[i] = NULL;
	close (fd);
	if (!file_base)
	{
		ft_err_msg_1(EXIT_FAILURE, file, ER_MAP_EMPTY, NULL);
		exit (ft_clean(1));
	}
	return (file_base);
}

int	ft_get_player_y(t_base *base)
{
	char	**map;
	int		i;
	int		j;

	map = base->map_base;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'W' \
				|| map[i][j] == 'E')
				return (i);
			j++;
		}
		i++;
	}
	return (-1);
}

int	ft_get_player_x(t_base *base, int i)
{
	char	**map;
	int		j;

	map = base->map_base;
	j = 0;
	while (map[i][j])
	{
		if (map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'W' \
			|| map[i][j] == 'E')
			return (j);
		j++;
	}
	return (-1);
}
