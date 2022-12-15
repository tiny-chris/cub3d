/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaillag <cgaillag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 11:21:42 by cgaillag          #+#    #+#             */
/*   Updated: 2022/12/15 12:39:59 by cgaillag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
	CETTE FONCTION SERT UNIQUEMENT A L"AFFICHAGE DONC A SUPPRIMER ENSUITE
*/
void	ZZ_PRINT_BASE_DATA(t_base *base)
{
	dprintf(1, "ELEMENTS : \n");

	dprintf(1, "TEXTURE	--> NO = %s\n", base->no.path);
	dprintf(1, "TEXTURE	--> SO = %s\n", base->so.path);
	dprintf(1, "TEXTURE	--> WE = %s\n", base->we.path);
	dprintf(1, "TEXTURE	--> EA = %s\n", base->ea.path);

	t_line	*line;

	line = base->list_base;
	while (line)
	{
		if (line->type == L_COLOR)
		{
			dprintf(1, "COLOR	--> type %d: %c str = %s\n", line->type,
					line->color, line->tex_path);
			dprintf(1, "        color tab = %d - %d - %d\n", line->col_tab[0],
					line->col_tab[1], line->col_tab[2]);
		}
		line = line->next;
	}

	int	i = 0;
	dprintf(1, "\n");
	dprintf(1, "MAP CHAR** : \n");
	while (base->map_base[i])
	{
		int l = 0;
		if (i < 10)
			dprintf(1, "l.%d%d = %s\n", l, i, base->map_base[i]);
		else
			dprintf(1, "l.%d = %s\n", i, base->map_base[i]);
		i++;
	}
	dprintf(1, "\n");
	dprintf(1, "MAP INT** : \n");
	i = 0;
	int j;
	dprintf(1, "game->rows = %d game->cols = %d\n", base->rows, base->cols);
	dprintf(1, "player: y = %d, x = %d et position = %c\n", base->p_y,
			base->p_x, base->p_direction);
	while (i < base->rows)
	{
		dprintf(1, "\n");
		j = 0;
		while (j < base->cols)
		{
			dprintf(1, "%d ", base->map[i][j]);
			j++;
		}
		i++;
	}
	dprintf(1, "\nAll seems ok\n");
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (ft_check_arg_err(argc, argv[1]))
		ft_exit_base(EXIT_FAILURE);
	ft_init_t_base(argv[1], &data.base);
	if (ft_check_file_err(&data.base))
		ft_exit_base(EXIT_FAILURE);
	ft_update_t_base_game(&data.base);
	ZZ_PRINT_BASE_DATA(&data.base);
	ft_init_data(&data);
	mlx_hook(data.win_ptr, 17, 1L << 17, ft_quit, &data);
	mlx_hook(data.win_ptr, 2, 1L << 0, ft_key_hook, &data);
	mlx_hook(data.win_ptr, 3, 1L << 1, ft_key_release, &data);
	mlx_loop_hook(data.mlx_ptr, ft_render_next_frame, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
