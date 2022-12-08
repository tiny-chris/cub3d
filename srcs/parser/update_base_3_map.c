/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_base_3_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaillag <cgaillag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 22:08:18 by cgaillag          #+#    #+#             */
/*   Updated: 2022/12/08 12:06:54 by cgaillag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_len_max_map(t_base *base, int *lines)
{
	t_line	*line;
	int		len_max;
	int		len;

	line = base->list_base;
	len_max = 0;
	len = 0;
	while (line && line->type != L_MAP)
		line = line->next;
	while (line && line->type == L_MAP)
	{
		len = ft_strlen_spechar(line->content, '\n');
		if (len > len_max)
			len_max = len;
		(*lines)++;
		line = line->next;
	}
	return (len_max);
}

static char	*ft_strncpy_map(char *str, int size)
{
	char	*copy_map;
	int		i;
	int		len;

	if (!str || size == 0)
		ft_exit_base(ft_msg_1(1, NULL, NULL, ER_MAP_ERR));
	copy_map = ft_magic_malloc(MALLOC + TAB_STR1, NULL, (size + 1));
	len = ft_strlen_spechar(str, '\n');
	i = 0;
	while (i < len)
	{
		copy_map[i] = str[i];
		i++;
	}
	if (len < size)
	{
		while (i < size)
			copy_map[i++] = ' ';
	}
	copy_map[i] = '\0';
	return (copy_map);
}

char	**ft_get_map_base(t_base *base)
{
	t_line	*line;
	char	**map_base;
	int		nb_lines;
	int		len_max;
	int		i;

	line = base->list_base;
	i = 0;
	nb_lines = 0;
	len_max = ft_len_max_map(base, &nb_lines);
	if (nb_lines == 0 || len_max == 0)
		ft_exit_base(ft_msg_1(1, NULL, NULL, ER_MAP_ERR));
	map_base = ft_magic_malloc(MALLOC + TAB_STR2, NULL, nb_lines + 1);
	while (line && line->type != L_MAP)
		line = line->next;
	while (line && line->type == L_MAP)
	{
		map_base[i] = ft_strncpy_map(line->content, len_max);
		i++;
		line = line->next;
	}
	map_base[i] = NULL;
	return (map_base);
}

int	**ft_get_map_game_int(t_base *base)
{
	int	**map;
	int	i;
	int	j;

	map = ft_magic_malloc(MALLOC + TAB_INT2, NULL, base->rows);
	i = 0;
	while (i < base->rows)
	{
		map[i] = ft_magic_malloc(MALLOC + TAB_INT1, NULL, base->cols);
		j = 0;
		while (j < base->cols)
		{
			if (base->map_base[i][j] == ' ')
				map[i][j] = -1;
			else if (base->map_base[i][j] == '1')
				map[i][j] = 1;
			else
				map[i][j] = 0;
			j++;
		}
		i++;
	}
	return (map);
}
