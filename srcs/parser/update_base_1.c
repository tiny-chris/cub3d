/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_base_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaillag <cgaillag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 23:44:29 by cgaillag          #+#    #+#             */
/*   Updated: 2022/12/15 09:58:20 by cgaillag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_lstadd_new_line(t_line **new_list, t_line *line)
{
	t_line	*tmp;

	tmp = ft_magic_malloc(MALLOC + LST_LINE, NULL, 1);
	tmp->index = line->index;
	tmp->rank = line->rank;
	tmp->content = line->content;
	tmp->type = line->type;
	tmp->range = line->range;
	tmp->texture = line->texture;
	tmp->tex_path = ft_strdup(line->tex_path);
	ft_magic_malloc(ADD + TAB_STR1, tmp->tex_path, 0);
	tmp->color = line->color;
	tmp->col_tab = NULL;
	if (tmp->color == 'C' || tmp->color == 'F')
	{
		tmp->col_tab = ft_intdup(line->col_tab, 3);
		ft_magic_malloc(ADD + TAB_INT1, tmp->col_tab, 3);
	}
	tmp->next = NULL;
	ft_lstadd_back_line(new_list, tmp);
}

static t_line	*ft_update_list_base(t_base *base)
{
	t_line	*line;
	t_line	*new_list;
	int		i;

	line = base->list_base;
	new_list = NULL;
	i = 1;
	while (i < 7)
	{
		while (line)
		{
			if (line->range == i)
				ft_lstadd_new_line(&new_list, line);
			line = line->next;
		}
		line = base->list_base;
		i++;
	}
	ft_magic_malloc(DELONE, base->list_base, 0);
	return (new_list);
}

/*  <SUMMARY>	Feed base elements (textures, colors and map)
**				to update linked list 'list_base' and allow checks
*/
void	ft_update_t_base(t_base *base)
{
	t_line	*line;

	line = base->list_base;
	while (line && line->type != L_MAP)
	{
		if (line->type == L_TEXTURE)
			ft_get_texture(&line);
		else if (line->type == L_COLOR)
			ft_get_color(&line);
		line = line->next;
	}
	base->map_base = ft_get_map_base(base);
	base->list_base = ft_update_list_base(base);
	return ;
}
