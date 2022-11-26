/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cub_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaillag <cgaillag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 22:08:18 by cgaillag          #+#    #+#             */
/*   Updated: 2022/11/26 00:15:13 by cgaillag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*  ***** Initialising - get file content *****
**  *************************
**  <SUMMARY>	Get the file content in a char **
**				and fill it by readingthe file (1 string = 1 line)
*/

// AJOUTER LE DECOMPTE DU \n COMME DANS SO_LONG --> traité ailleurs !!
//int	ft_strlen_spechar(const char *str, char spe_c)

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
	// /*
	// **	DEBUT - affichage
	// */
	// i = 0;
	// while (i < lines)
	// {
	// 	dprintf(2, "line[%d] = %s\n", i, file_base[i]);
	// 	i++;
	// }
	// /*
	// **	FIN - affichage
	// */
	return (file_base);
}
