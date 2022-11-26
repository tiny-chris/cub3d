/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaillag <cgaillag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 11:53:34 by cgaillag          #+#    #+#             */
/*   Updated: 2022/11/26 05:32:01 by cgaillag         ###   ########.fr       */
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

	newline = malloc(sizeof(t_line) * 1);
	if (!newline)
		return ;//a modif
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

