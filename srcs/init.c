/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaillag <cgaillag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 16:48:15 by cgaillag          #+#    #+#             */
/*   Updated: 2022/11/22 16:26:18 by cgaillag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*  ***** Initialisation - structure data *****
**  *************************
**  <SUMMARY>	Initialise the reference structure that will:
**				- 
**				- ...
**				(run mlx, hold images and contain the structure for the game)
*/
void	ft_init_t_data_cub(char *file, t_data *data)
{
	data->file_content = NULL;
	data->map_base = NULL;
	data->elem_base = NULL;
	data->file_content = ft_get_file_content(file);
}

/*  ***** Initialising - get file content *****
**  *************************
**  <SUMMARY>	Get the file content in a char **
**				and fill it by readingthe file (1 string = 1 line)
*/
char	**ft_get_file_content(char	*file)
{
	char	**file_base;
	int		fd;
	int		lines;
	int		i;

	lines = ft_count_lines_gnl(file);
	fd = open(file, O_RDONLY);
	if (fd < 0 || lines == 0)
		return (NULL);//adjust
	i = 0;
	file_base = ft_malloc(TAB_STR2, (lines + 1));
	//check si pb malloc
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
