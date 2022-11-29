/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaillag <cgaillag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 22:08:18 by cgaillag          #+#    #+#             */
/*   Updated: 2022/11/29 11:44:37 by cgaillag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_len_max_map(t_line *list_base, int *lines)
{
	t_line	*line;
	int		len_max;
	int		len;

	line = list_base;
	len_max = 0;
	len = 0;
	while (line && line->ref != L_MAP)
		line = line->next;
	while (line && line->ref == L_MAP)
	{
		len = ft_strlen_spechar(line->content, '\n');
		if (len > len_max)
			len_max = len;
		(*lines)++;
		line = line->next;
	}
	return (len_max);
}

char	*ft_strncpy_map(char *str, int width)
{
	char	*copy_map;
	int		i;
	int		len;

	if (!str || width == 0)
		return (NULL);//revoir
	copy_map = ft_malloc(TAB_STR1, (width + 1));
	len = ft_strlen_spechar(str, '\n');
	i = 0;
	while (i < len)
	{
		copy_map[i] = str[i];
		i++;
	}
	if (len < width)
	{
		while (i < width)
			copy_map[i++] = ' ';
	}
	copy_map[i] = '\0';
	return (copy_map);
}

/*
	on commence à range 7 ou bien L_MAP

*/
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
	len_max = ft_len_max_map(line, &nb_lines);
	map_base = ft_malloc(TAB_STR2, nb_lines + 1);
	//protégé
	while (line && line->ref != L_MAP)
		line = line->next;
	while (line && line->ref == L_MAP)
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

	map = ft_malloc(TAB_INT2, base->game->height);
	i = 0;
	while (i < base->game->height)
	{
		map[i] = ft_malloc(TAB_INT1, base->game->width);
		j = 0;
		while (j < base->game->width)
		{
			if (base->map_base[i][j] == ' ')
				map[i][j] = -1;
			else if (base->map_base[i][j] == '0')
				map[i][j] = 0;
			else if (base->map_base[i][j] == '1')
				map[i][j] = 1;
			else
				map[i][j] = 2;
			j++;
		}
		i++;
	}
	return (map);
}
