/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaillag <cgaillag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 11:53:34 by cgaillag          #+#    #+#             */
/*   Updated: 2022/12/10 00:14:37 by cgaillag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* <SUMMARY> Functions for linked list 't_line'
*/
static t_line	*ft_lstlast_line(t_line *lst)
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

void	ft_lstadd_line(t_line **line, int index, char *str, t_line_type type)
{
	t_line	*newline;
	int		len;

	if (str)
		len = ft_strlen_spechar(str, '\n');
	else
		len = ft_strlen(str);
	newline = ft_magic_malloc(MALLOC + LST_LINE, NULL, 1);
	newline->index = index;
	newline->content = ft_substr(str, 0, len);
	ft_magic_malloc(ADD + TAB_STR1, newline->content, 0);
	newline->type = type;
	newline->range = -1;
	newline->texture = NO;
	newline->tex_path = NULL;
	newline->color = 'X';
	newline->col_tab = NULL;
	newline->next = NULL;
	ft_lstadd_back_line(line, newline);
}

void	ft_lstdelone_line(t_line *node)
{
	if (!node)
		return ;
	node->next = NULL;
	free(node);
	node = NULL;
}
