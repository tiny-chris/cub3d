/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_base_game.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaillag <cgaillag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 00:15:51 by cgaillag          #+#    #+#             */
/*   Updated: 2022/12/08 12:23:14 by cgaillag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_get_player_y(t_base *base)
{
	char	**map;
	int		i;
	int		j;

	map = base->map_base;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'W' \
				|| map[i][j] == 'E')
				return (i);
			j++;
		}
		i++;
	}
	return (-1);
}

static int	ft_get_player_x(t_base *base, int i)
{
	char	**map;
	int		j;

	map = base->map_base;
	j = 0;
	while (map[i][j])
	{
		if (map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'W' \
			|| map[i][j] == 'E')
			return (j);
		j++;
	}
	return (-1);
}

static unsigned long	ft_get_color_rgb(int *t)
{
	return (((t[0] & 0xff) << 16) + ((t[1] & 0xff) << 8) + (t[2] & 0xff));
}

static void	ft_get_game_elem(t_base *base)
{
	t_line	*line;

	line = base->list_base;
	while (line)
	{
		if (line->type == L_TEXTURE)
		{
			if (line->texture == NO)
				base->tex_no = line->tex_path;
			else if (line->texture == SO)
				base->tex_so = line->tex_path;
			else if (line->texture == WE)
				base->tex_we = line->tex_path;
			else if (line->texture == EA)
				base->tex_ea = line->tex_path;
		}
		else if (line->type == L_COLOR)
		{
			if (line->color == 'C')
				base->col_c_hex = ft_get_color_rgb(line->col_tab);
			else if (line->color == 'F')
				base->col_f_hex = ft_get_color_rgb(line->col_tab);
		}
		line = line->next;
	}
}

void	ft_update_t_base_game(t_base *base)
{
	ft_get_game_elem(base);
	dprintf(2, "val de c_col_hex = %lX\n", base->col_c_hex);
	dprintf(2, "val de f_col_hex = %lX\n", base->col_f_hex);
	base->rows = ft_lines_tabstr(base->map_base);
	base->cols = ft_strlen_spechar(base->map_base[0], '\n');
	base->map = ft_get_map_game_int(base);
	base->p_y = ft_get_player_y(base);
	base->p_x = ft_get_player_x(base, base->p_y);
	base->p_direction = base->map_base[base->p_y][base->p_x];
}
