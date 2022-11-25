/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaillag <cgaillag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 16:48:15 by cgaillag          #+#    #+#             */
/*   Updated: 2022/11/25 12:22:23 by cgaillag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_init_t_base_cub_0(t_base *base)
{
	base->file_base = NULL;
	base->map_base = NULL;
	base->elem_base = NULL;
	base->nblines_base = -1;
	base->list_base = NULL;
	base->index_start_map = -1;
}

static void	ft_init_list_base(t_base *b, t_line_type ref)
{
	int			i;
	int			j;

	i = 0;
	while (b->file_base[i])
	{
		j = 0;
		while (b->file_base[i][j] == ' ')
			j++;
		if (b->file_base[i][j] == '\0' || b->file_base[i][j] == '\n')
			ref = L_EMPTY;
		else if ((b->file_base[i][j] == 'N' && b->file_base[i][j + 1] == 'O')
		|| (b->file_base[i][j] == 'S' && b->file_base[i][j + 1] == 'O')
		|| (b->file_base[i][j] == 'W' && b->file_base[i][j + 1] == 'E')
		|| (b->file_base[i][j] == 'E' && b->file_base[i][j + 1] == 'A'))
			ref = L_TEXTURE;
		else if (b->file_base[i][j] == 'F' || b->file_base[i][j] == 'C')
			ref = L_COLOR;
		else if (b->file_base[i][j] == '1')
			ref = L_MAP;
		ft_lstadd_line(&(b->list_base), i, b->file_base[i], ref);
		ref = L_UNEXPECT;
		i++;
	}
}

/*  ***** Initialisation - base structure *****
**  *************************
**  <SUMMARY>	Initialise the reference structure that will:
**				-
**				- ...
**				(run mlx, hold images and contain the structure for the game)
*/
void	ft_init_t_base_cub(char *file, t_base *base)
{
	int	i;

	i = 0;
	ft_init_t_base_cub_0(base);
	base->file_base = ft_get_file_base(file);
	if (!base->file_base)
		exit (EXIT_FAILURE);//nettoyer et mesg erreur
	while (base->file_base[i])
		i++;
	base->nblines_base = i;
	dprintf(2, "nblines_base = %d\n", base->nblines_base);
	ft_init_list_base(base, L_UNEXPECT);
}

/*  ***** Initialising - get file content *****
**  *************************
**  <SUMMARY>	Get the file content in a char **
**				and fill it by readingthe file (1 string = 1 line)
*/


// AJOUTER LE DECOMPTE DU \n COMME DANS SO_LONG
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
	/*
	**	DEBUT - affichage
	*/
	i = 0;
	while (i < lines)
	{
		dprintf(2, "line[%d] = %s\n", i, file_base[i]);
		i++;
	}
	/*
	**	FIN - affichage
	*/
	return (file_base);
}
