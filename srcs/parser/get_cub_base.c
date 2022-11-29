/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cub_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaillag <cgaillag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 22:08:18 by cgaillag          #+#    #+#             */
/*   Updated: 2022/11/29 11:43:43 by cgaillag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*  ***** Initialising - get file content *****
**  *************************
**  <SUMMARY>	Get the file content in a char **
**				and fill it by readingthe file (1 string = 1 line)
*/
char	**ft_get_file_base(char	*file)
{
	char	**file_base;
	int		fd;
	int		lines;
	int		i;

	lines = ft_count_lines_gnl(file);
	fd = open(file, O_RDONLY);
	if (fd < 0 || lines == 0)
		return (NULL);//adjust en erreur et on exit
	i = 0;
	file_base = ft_malloc(TAB_STR2, (lines + 1));
	file_base[i] = get_next_line(fd);
	while (file_base[i])
	{
		i++;
		file_base[i] = get_next_line(fd);
	}
	file_base[i] = NULL;
	close (fd);
	if (!file_base)
		return (ft_err_msg(EXIT_FAILURE, file, ER_MAP_EMPTY), NULL);
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
