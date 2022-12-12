/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaillag <cgaillag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 14:58:11 by cgaillag          #+#    #+#             */
/*   Updated: 2022/12/13 00:14:32 by cgaillag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_init_t_base_0(t_base *base)
{
	base->file_base = NULL;
	base->map_base = NULL;
	base->list_base = NULL;
	base->nblines_base = -1;
	base->no.path = NULL;
	base->no.img = NULL;
	base->so.path = NULL;
	base->so.img = NULL;
	base->we.path = NULL;
	base->we.img = NULL;
	base->ea.path = NULL;
	base->ea.img = NULL;
	base->col_c_hex = 0;
	base->col_f_hex = 0;
	base->map = NULL;
	base->rows = -1;
	base->cols = -1;
	base->p_y = -1;
	base->p_x = -1;
	base->p_direction = '\0';
}

/*  ***** Initialising - get file content *****
**  *************************
**  <SUMMARY>	Get the file content in a char **
**				and fill it by reading the file (1 string = 1 line)
*/
static char	**ft_get_file_base(char	*file)
{
	char	**file_base;
	int		fd;
	int		lines;
	int		i;

	fd = ft_open_read(file);
	lines = ft_count_lines_gnl(file);
	if (!file || lines == 0)
		ft_exit_base(ft_msg_1(1, file, NULL, ER_FIL_EMPTY));
	i = 0;
	file_base = ft_magic_malloc(MALLOC + TAB_STR2, NULL, (lines + 1));
	file_base[i] = get_next_line(fd);
	while (file_base[i])
	{
		ft_magic_malloc(ADD + TAB_STR1, file_base[i], 0);
		i++;
		file_base[i] = get_next_line(fd);
	}
	file_base[i] = NULL;
	close (fd);
	if (!file_base)
		ft_exit_base(ft_msg_1(1, file, NULL, ER_FIL_EMPTY));
	return (file_base);
}

static void	ft_get_type(char **list, int *i, int *j, t_line_type *type)
{
	if ((list[*i][*j] == 'N' && list[*i][*j + 1] == 'O')
		|| (list[*i][*j] == 'S' && list[*i][*j + 1] == 'O')
		|| (list[*i][*j] == 'W' && list[*i][*j + 1] == 'E')
		|| (list[*i][*j] == 'E' && list[*i][*j + 1] == 'A'))
		*type = L_TEXTURE;
	else if ((list[*i][*j] == 'F' && list[*i][*j + 1] == ' ')
	|| (list[*i][*j] == 'C' && list[*i][*j + 1] == ' '))
		*type = L_COLOR;
	else if (list[*i][*j] == '1')
		*type = L_MAP;
}

static void	ft_get_list_base(t_base *b, t_line_type type)
{
	int			i;
	int			j;

	i = 0;
	while (b->file_base[i])
	{
		j = 0;
		if (b->file_base[i][j] == '\0' || b->file_base[i][j] == '\n')
			type = L_EMPTY;
		else
		{
			if (b->file_base[i][j] == ' ')
			{
				while (b->file_base[i][j] == ' ')
					j++;
				if (b->file_base[i][j] != '\0' && b->file_base[i][j] != '\n')
					ft_get_type(b->file_base, &i, &j, &type);
			}
			else
				ft_get_type(b->file_base, &i, &j, &type);
		}
		ft_lstadd_line(&(b->list_base), i, b->file_base[i], type);
		type = L_UNEXPECT;
		i++;
	}
}

/*  ***** Initialisation - base structure *****
**  *************************
**  <SUMMARY>	Initialise the base structure that will:
**				-
**				- ...
**				(run mlx, hold images and contain the structure for the game)
*/
void	ft_init_t_base(char *file, t_base *base)
{
	int	i;

	i = 0;
	ft_init_t_base_0(base);
	base->file_base = ft_get_file_base(file);
	if (!base->file_base)
		ft_exit_base(ft_msg_1(1, file, NULL, ER_FIL_EMPTY));
	while (base->file_base[i])
		i++;
	base->nblines_base = i;
	ft_get_list_base(base, L_UNEXPECT);
}
