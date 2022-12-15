/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaillag <cgaillag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 14:58:11 by cgaillag          #+#    #+#             */
/*   Updated: 2022/12/15 12:04:11 by cgaillag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_init_t_base_0(t_base *base)
{
	base->file_base = NULL;
	base->map_base = NULL;
	base->list_base = NULL;
	base->map_ln = -1;
	ft_init_t_img_0(&(base->no));
	ft_init_t_img_0(&(base->so));
	ft_init_t_img_0(&(base->we));
	ft_init_t_img_0(&(base->ea));
	base->col_c_hex = 0;
	base->col_f_hex = 0;
	base->map = NULL;
	base->rows = -1;
	base->cols = -1;
	base->p_y = -1;
	base->p_x = -1;
	base->p_direction = '\0';
}

/*  <SUMMARY>	Initialising part
**	Get the file content in a char ** and fill it by reading the file 
**	(1 string = 1 line)
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
	if (list[*i][*j + 1]
		&& ((list[*i][*j] == 'N' && list[*i][*j + 1] == 'O')
		|| (list[*i][*j] == 'S' && list[*i][*j + 1] == 'O')
		|| (list[*i][*j] == 'W' && list[*i][*j + 1] == 'E')
		|| (list[*i][*j] == 'E' && list[*i][*j + 1] == 'A'))
		&& (list[*i][*j + 2] && list[*i][*j + 2] == ' '))
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

/*  <SUMMARY>	Initialising part
**	Pre-initialise the base structure
**	and get base elements (file_base, list_base, start line of map)
*/
void	ft_init_t_base(char *file, t_base *base)
{
	int		i;
	t_line	*line;

	i = 0;
	line = NULL;
	ft_init_t_base_0(base);
	base->file_base = ft_get_file_base(file);
	if (!base->file_base)
		ft_exit_base(ft_msg_1(1, file, NULL, ER_FIL_EMPTY));
	ft_get_list_base(base, L_UNEXPECT);
	line = base->list_base;
	while (line)
	{
		if (line->type == L_MAP)
			break ;
		i++;
		line = line->next;
	}
	base->map_ln = i + 1;
}
