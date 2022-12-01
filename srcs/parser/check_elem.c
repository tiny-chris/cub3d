/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_elem.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaillag <cgaillag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 22:08:18 by cgaillag          #+#    #+#             */
/*   Updated: 2022/12/01 17:28:17 by cgaillag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* check textures
	- tant que espace, alors avancer
	- check les 2 premiers
	- check un espace --> si autres espaces, avancer
	-
*/
// void	ft_check_textures(t_line *line)
// {
// 	// 2.
// 	/*
// 		- check bien 1 de chaque

// 		- check que la texture existe(open) pas un directory
// 		- se termine par xpm (utiliser ft_check_filename...)
// 	*/
// }

/*
	- lire la liste

		- si range == 1

*/
void	ft_lstadd_elem(t_line **list_elem, t_line *line)
{
	t_line	*tmp;

	tmp = ft_magic_malloc(MALLOC + LST_LINE, NULL, 1);
	tmp->index = line->index;
	tmp->content = NULL;
	tmp->ref = line->ref;
	tmp->range = line->range;
	tmp->texture = line->texture;
	tmp->text_path = ft_strdup(line->text_path);
	ft_magic_malloc(ADD + TAB_STR1, tmp->text_path, 0);
	tmp->color = line->color;
	if (tmp->color == 'C' || tmp->color == 'F')
	{
		tmp->col_tab = ft_intdup(line->col_tab, 3);
		ft_magic_malloc(ADD + TAB_INT1, tmp->col_tab, 3);
	}
	else
		tmp->col_tab = NULL;
	tmp->next = NULL;
	ft_lstadd_back_line(list_elem, tmp);
}

t_line	*ft_get_elem_base(t_base *base)
{
	t_line	*line;
	t_line	*list_elem;
	int		i;

	line = base->list_base;
	list_elem = NULL;
	i = 1;
	while (i < 7)
	{
		while (line)
		{
			if (line->range == i)
				ft_lstadd_elem(&list_elem, line);
			line = line->next;
		}
		line = base->list_base;
		i++;
	}
	return (list_elem);
}

static int	ft_check_count_elem(t_base *base, int range)
{
	t_line	*line;
	int		count;

	count = 0;
	line = base->list_base;
	while (line)
	{
		if (line->range == range)
			count++;
		line = line->next;
	}
	if (count < 1)
		return (ft_err_msg_1(1, NULL, NULL, "one or more elements are missing"));
	else if (count > 1)
		return (ft_err_msg_1(1, NULL, NULL, "one or more duplicate elements"));
	return (0);
}

/*  ***** Parsing - check texture elements *****
**  *************************
**  <SUMMARY>	Check if path is not a directory
**	<RETURN>	- EXIT_FAILURE: if is a directory
**				- XIT_SUCCESS, otherwise
*/
int	ft_check_elem_err(t_base *base)
{
	int		i;
	t_line	*line;

	line = base->list_elem;
	i = 1;
	while (i < 7)
	{
		if (ft_check_count_elem(base, i))
			return (EXIT_FAILURE);//nettoyer
		i++;
	}
	while (line)
	{
		if (line->range >= 1 && line->range < 5)
		{
			if (!ft_check_filename(line->text_path, ".xpm"))
				exit (EXIT_FAILURE);//nettoyer !!
			if (ft_check_isdirectory(line->text_path))
				exit (EXIT_FAILURE);//nettoyer !!
		}
		line = line->next;
	}
	return (EXIT_SUCCESS);
}
