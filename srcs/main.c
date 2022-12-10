/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaillag <cgaillag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 11:21:42 by cgaillag          #+#    #+#             */
/*   Updated: 2022/12/10 03:25:53 by cgaillag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
	CETTE FONCTION SERT UNIQUEMENT A L"AFFICHAGE DONC A SUPPRIMER ENSUITE
*/
void	ZZ_PRINT_BASE_DATA(t_base *base)
{
	t_line	*elem;

	elem = base->list_base;
	dprintf(1, "ELEM : \n");
	while (elem)
	{
		if (elem->type == L_TEXTURE)
			dprintf(1, "TEXTURE	--> type %d: %d str = %s\n", elem->type,
					elem->texture, elem->tex_path);
		else if (elem->type == L_COLOR)
		{
			dprintf(1, "COLOR	--> type %d: %c str = %s\n", elem->type,
					elem->color, elem->tex_path);
			dprintf(1, "color tab = %d - %d - %d\n", elem->col_tab[0],
					elem->col_tab[1], elem->col_tab[2]);
		}
		elem = elem->next;
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

	// PART 1: parsing
	if (ft_check_arg_err(argc, argv[1]))
		ft_exit_base(EXIT_FAILURE);
	ft_init_t_base(argv[1], &data.base);
	if (ft_check_file_err(&data.base))
		ft_exit_base(EXIT_FAILURE);
	ft_update_t_base_game(&data.base);
	ZZ_PRINT_BASE_DATA(&data.base);
	// ft_exit_base(0);// à replacer/ajuster correctement
	// --> pour tester le parsing
	// PART 2: game
	ft_init_data(&data);
	mlx_hook(data.win_ptr, 17, 1L << 17, (void *)ft_quit, &data); // clic croix
	mlx_hook(data.win_ptr, 2, 1L << 0, (void *)ft_key_hook, &data);
	mlx_hook(data.win_ptr, 3, 1L << 1, (void *)ft_key_release, &data);
	mlx_loop_hook(data.mlx_ptr, ft_render_next_frame, &data);
	//
	mlx_loop(data.mlx_ptr);
	return (0);
}
