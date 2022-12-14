/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_base_2_elem.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaillag <cgaillag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 22:08:18 by cgaillag          #+#    #+#             */
/*   Updated: 2022/12/14 15:17:35 by cgaillag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_get_list_range(t_line **list_base, int i)
{
	t_line	*line;

	line = (*list_base);
	if (ft_strncmp(line->content + i, "NO ", 3) == 0)
	{
		line->texture = NO;
		line->range = 1;
	}
	else if (ft_strncmp(line->content + i, "SO ", 3) == 0)
	{
		line->texture = SO;
		line->range = 2;
	}
	else if (ft_strncmp(line->content + i, "WE ", 3) == 0)
	{
		line->texture = WE;
		line->range = 3;
	}
	else if (ft_strncmp(line->content + i, "EA ", 3) == 0)
	{
		line->texture = EA;
		line->range = 4;
	}
}

void	ft_get_texture(t_line **list_base)
{
	int		i;
	int		len;
	char	*tmp;
	t_line	*line;

	line = (*list_base);
	tmp = NULL;
	len = ft_strlen_spechar(line->content, '\n');
	i = 0;
	while (line->content[i] == ' ')
		i++;
	ft_get_list_range(&line, i);
	i += 3;
	tmp = ft_substr(line->content, i, len - i);
	ft_magic_malloc(ADD + TAB_STR1, tmp, 0);
	if (tmp)
		line->tex_path = ft_strtrim(tmp, " ");
	ft_magic_malloc(ADD + TAB_STR1, line->tex_path, 0);
	ft_magic_malloc(DELONE, tmp, 0);
	tmp = NULL;
}

static char	*ft_get_str_color(t_line *line, int i, int len)
{
	char	*str_color;
	char	*tmp;

	tmp = ft_substr(line->content, i, len - i);
	ft_magic_malloc(ADD + TAB_STR1, tmp, 0);
	str_color = ft_strtrim(tmp, " ");
	ft_magic_malloc(ADD + TAB_STR1, str_color, 0);
	ft_magic_malloc(DELONE, tmp, 0);
	tmp = NULL;
	return (str_color);
}

/*
	- creates a table of strings using ft_split
	- check if the number of strings == 3 (3 colors), if not: error
	- create a table of int, malloc it (size 3) + protect
	- check if each string can be converted to an int
		if so: put the converted string into the table of int
		if at least, 1 string cannot be converted: error
*/
static int	*ft_get_tab_int_color(char *tex_path)
{
	char	**tab_str;
	int		*tab;
	int		i;
	int		n;

	i = -1;
	tab = NULL;
	tab_str = ft_split2(tex_path, ',');
	ft_magic_malloc(ADD + TAB_STRS, tab_str, 0);
	if (ft_lines_tabstr(tab_str) != 3)
		ft_exit_base(ft_msg_2(1, 0, ER_COL_FOR, USAGE_COL));
	tab = ft_magic_malloc(MALLOC + TAB_INT1, NULL, 3);
	while (++i < 3)
	{
		n = ft_atoi_cub(tab_str[i]);
		if (n < 0 || n > 255)
			ft_exit_base(ft_msg_2(1, 0, ER_COL_VAL, USAGE_COL));
		tab[i] = n;
	}
	ft_magic_malloc(DELONE, tab_str, 0);
	tab_str = NULL;
	return (tab);
}

void	ft_get_color(t_line **list_base)
{
	int		i;
	int		len;
	t_line	*line;

	line = (*list_base);
	len = ft_strlen_spechar(line->content, '\n');
	i = 0;
	while (line->content[i] == ' ')
		i++;
	if (ft_strncmp(line->content + i, "C ", 2) == 0)
	{
		line->color = 'C';
		line->range = 5;
	}
	else if (ft_strncmp(line->content + i, "F ", 2) == 0)
	{
		line->color = 'F';
		line->range = 6;
	}
	i += 2;
	line->tex_path = ft_substr(line->content, i, len - i);
	ft_magic_malloc(ADD + TAB_STR1, line->tex_path, 0);
	line->tex_path = ft_get_str_color(line, i, len);
	line->col_tab = ft_get_tab_int_color(line->tex_path);
}
