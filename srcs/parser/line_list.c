/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaillag <cgaillag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 11:53:34 by cgaillag          #+#    #+#             */
/*   Updated: 2022/12/01 14:18:51 by cgaillag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* <SUMMARY> Functions for linked list 't_line'
*/
t_line	*ft_lstlast_line(t_line *lst)
{
	t_line	*node;

	if (!lst)
		return (0);
	node = lst;
	while (node->next)
		node = node->next;
	return (node);
}

void	ft_lstadd_back_line(t_line **line, t_line *new)
{
	t_line	*last;

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

void	ft_lstadd_line(t_line **line, int index, char *str, t_line_type ref)
{
	t_line	*newline;

	newline = ft_magic_malloc(MALLOC + LST_LINE, NULL, 1);
	newline->index = index;
	newline->content = ft_strdup(str);//protéger
	newline->ref = ref;
	// dprintf(2, "ref = %d\n", ref);
	newline->range = -1;
	newline->texture = NO;
	newline->text_path = NULL;
	newline->color = 'X';
	newline->col_tab = NULL;
	newline->next = NULL;
	ft_lstadd_back_line(line, newline);
	// if (!(*line))
	// {
	// 	*line = newline;
	// 	return ;
	// }
	// if (!newline)
	// 	return ;
	// last = ft_lstlast_line(*line);
	// last->next = newline;
}

void	ft_lstdelone_line(t_line *node)
{
	if (!node)
		return ;
	node->next = NULL;
	free(node);
	node = NULL;
}

void	ft_lstdelone_line_bin(t_line *node)
{
	if (!node)
		return ;
	if (node->content)
		ft_magic_malloc(DELONE, node->content, 0);
	if (node->text_path)
		ft_magic_malloc(DELONE, node->text_path, 0);
	if (node->col_tab)
		ft_magic_malloc(DELONE, node->col_tab, 0);
	ft_magic_malloc(DELONE, node, 0);
}

void	ft_free_line(t_line **line)
{
	t_line	*tmp;
	t_line	*todel;

	tmp = NULL;
	todel = NULL;
	if (!*line)
		return ;
	while ((*line) != NULL)
	{
		todel = (*line);
		tmp = (*line)->next;
		ft_lstdelone_line_bin(todel);
		(*line) = tmp;
	}
	(*line) = NULL;
}
