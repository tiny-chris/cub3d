/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_elem.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaillag <cgaillag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 22:08:18 by cgaillag          #+#    #+#             */
/*   Updated: 2022/11/26 22:41:37 by cgaillag         ###   ########.fr       */
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

	tmp = malloc(sizeof(t_line));//protéger
	tmp->index = line->index;
	tmp->content = NULL;
	tmp->ref = line->ref;
	tmp->range = line->range;
	tmp->texture = line->texture;
	tmp->text_path = ft_strdup(line->text_path);
	tmp->color = line->color;
	dprintf(2, "je checke ici =========================\n");
	if (tmp->color == 'C' || tmp->color == 'F')
		tmp->col_tab = ft_intdup(line->col_tab, 3);
	else
		tmp->col_tab = NULL;
	dprintf(2, "je checke ici 3 =========================\n");
	tmp->next = NULL;
	dprintf(2, "je checke ici 2 =========================\n");
	ft_lstadd_back_line(list_elem, tmp);
}

t_line	*ft_get_elem_base(t_base *base)
{
	t_line	*line;
	t_line	*list_elem;
	int		i;

	line = base->list_base;
	dprintf(2, "xxxxxxxxxxx list_base->index = %d\n", base->list_base->index);
	dprintf(2, "xxxxxxxxxxx line->index = %d\n", line->index);
	list_elem = NULL;
	i = 1;
	while (i < 7)
	{
		while (line)
		{
			dprintf(2, "xxxxxxxxxxx val de i = %d\n", i);
			dprintf(2, "line->index = %d\n", line->index);
			dprintf(2, "line->range = %d\n", line->range);
			if (line->range == i)
			{
				dprintf(2, "line->text_path = %s\n", line->text_path);
				ft_lstadd_elem(&list_elem, line);
			}
			line = line->next;
		}
		line = base->list_base;
		i++;
	}
	dprintf(2, "TESSSSSSSSSSSSST ICIIIIIIIIII\n");
	t_line *tmp;
	tmp = list_elem;
	if (tmp)
		dprintf(2, "list_elem start path = %s\n", tmp->text_path);
	else
		dprintf(2, "tmp vide\n");
	return (list_elem);
}
// 	dprintf(2, "TESSSSSSSSSSSSST ICIIIIIIIIII #1\n");
// 	i = 1;
// 	while (i < 7)
// 	{
// 		dprintf(2, "i = %d\n", i);
// 		while (line)
// 		{
// 			dprintf(2, "line->index = %d\n", line->index);
// 			dprintf(2, "line->range = %d\n", line->range);
// 			if (line->range == i)
// 				ft_lstadd_line(&list_elem, line->index, line->content, line);
// 			line = line->next;
// 		}
// 		line = (*list_base);
// 		i++;
// 	}
// 	dprintf(2, "TESSSSSSSSSSSSST ICIIIIIIIIII\n");
// 	return (list_elem);
// }

static int	ft_check_count_elem(t_base *base, int range)
{
	t_line	*line;
	int		count;

	count = 0;
	line = base->list_base;
	// dprintf(2, "********line->index check count elem = %d\n", line->index);
	while (line)
	{
		if (line->range == range)
			count++;
		line = line->next;
	}
	if (count < 1)
		return (ft_err_msg(1, NULL, "one or more elements are missing"));
	else if (count > 1)
		return (ft_err_msg(1, NULL, "one or more duplicate elements"));
	return (0);
}

int	ft_check_elem_err(t_base *base)
{
	int	i;

	i = 1;
	dprintf(2, "**///******line->index check elem err = %d\n", base->list_base->index);
	while (i < 7)
	{
		dprintf(2, "et la ? et la, et la...\n");
		if (ft_check_count_elem(base, i))
		{
			//nettoyer
			return (1);
		}
		i++;
	}
	return (0);
}
