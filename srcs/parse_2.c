/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaillag <cgaillag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 16:48:15 by cgaillag          #+#    #+#             */
/*   Updated: 2022/11/24 18:08:34 by cgaillag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_check_nb_lines(t_base *base)
{
	int	i;

	i = 0;
	while (base->file_content[i])
		i++;
	base->nblines_base = i;
	dprintf(2, "nblines_base = %d\n", base->nblines_base);
	return (0);
}

t_line	*ft_lstlast_line(t_line *lst_line)
{
	t_line	*node;

	if (!lst_line)
		return (0);
	node = lst_line;
	while (node->next)
		node = node->next;
	return (node);
}

void	ft_lstadd_line(t_line **line, int index, char *str, t_line_type ref)
{
	t_line	*new;
	t_line	*last;

	new = malloc(sizeof(t_line) * 1);
	if (!new)
		return ;//a modif
	new->line_index = index;
	new->line_content = ft_strdup(str);
	new->line_ref = ref;
	new->next = NULL;
	if (!(*line))
	{
		*line = new;
		return ;
	}
	if (!new)
		return ;
	last = ft_lstlast_line(*line);
	last->next = new;
}

int	ft_check_lines_order(t_base *b)
{
	int		i;
	int		j;
	t_line	*line;

	i = 0;
	line = NULL;
	while (b->file_content[i])
	{
		j = 0;
		while (b->file_content[i][j] == ' ')
			j++;
		if (b->file_content[i][j] == '\0')
			ft_lstadd_line(&line, i, "", L_EMPTY);
		else if ((b->file_base[i][j] == 'N' && b->file_base[i][j + 1] == 'O')
		|| (b->file_base[i][j] == 'S' && b->file_base[i][j + 1] == 'O')
		|| (b->file_base[i][j] == 'W' && b->file_base[i][j + 1] == 'E')
		|| (b->file_base[i][j] == 'E' && b->file_base[i][j + 1] == 'A'))
			ft_lstadd_line(&line, i, b->file_base[i], L_TEXTURE);
		else if (b->file_content[i][j] == 'F' || b->file_content[i][j] == 'C')
			ft_lstadd_line(&line, i, b->file_base[i], L_COLOR);
		else
			ft_lstadd_line(&line, i, b->file_base[i], L_MAP);
		i++;
	}
	/*
	**	DEBUT - affichage
	*/
	// t_line	*tmp = line;
	// int		k = 0;
	// while (tmp)
	// {
		// dprintf(2, "k = %d, line[%d], type = %d\n", 0, line->line_index, line->line_ref);
		// dprintf(2, "k = %d, line[%d] = %s, type = %d\n", 0, tmp->line_index, tmp->line_content, tmp->line_ref);
		// tmp = tmp->next;
		// k++;
	// }
	/*	
	**	FIN - affichage
	*/
	return (0);
}

void	ft_get_file_content_detailed(t_base *base)
{
	char	*line;
	int		i;

	(void) base;
	i = 0;
	line = NULL;
	//while (i < )
	return ;
}

int	ft_check_map_err(char **map_base)
{
	(void) map_base;
	return (0);
}

int	ft_check_elem_err(char **elem_base)
{
	(void) elem_base;
	return (0);
}

/*  ***** Parsing - ........ *****
**  *************************
**  <SUMMARY>	
**	
**	nb de lignes
**	position des elements et de la map
**
*/
int	ft_check_file_err(t_base *base)
{
	ft_check_nb_lines(base);
	ft_check_lines_order(base);
	ft_get_file_content_detailed(base);
	if (ft_check_map_err(base->map_base) || ft_check_elem_err(base->elem_base))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

// t_bool	ft_check_cub(const char **specs)
// {
// 	int		height;

// 	height = 0;
// 	while (specs[height + 1])
// 		height++;
// 	if (*specs[height] == '\0')
// 	{
// 		ft_freetab ((void **)specs);
// 		return (write (2, "Error\nInvalid .cub map\n", 23) == 0);
// 	}
// 	if (ft_check_cub_elements(specs) == FALSE)
// 	{
// 		ft_freetab ((void **)specs);
// 		return (FALSE);
// 	}
// 	return (TRUE);
// }