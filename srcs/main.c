/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaillag <cgaillag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 11:21:42 by cgaillag          #+#    #+#             */
/*   Updated: 2022/11/29 14:04:44 by cgaillag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_init_data(t_data *data)
{
	data->img.mlx_ptr = mlx_init();
	data->img.win_ptr = mlx_new_window(data->img.mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "CUB3D");
	data->img.img = mlx_new_image(data->img.mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	if (!data->img.img)
		return ; // On free ?
	data->img.addr = mlx_get_data_addr(data->img.img, &(data->img.bits_per_pixel), \
				&(data->img.line_lenght), &(data->img.endian));
	if (!data->img.addr)
		return ; // On free ? 
	data->p1.x = 10;
	data->p1.y = 100;
	data->p2.x = 10;
	data->p2.y = 500;
}

int	ft_render_next_frame(t_data *data)
{
	// update line
	data->p1.x += 5;
	data->p2.x += 5;
	mlx_destroy_image(data->img.mlx_ptr, data->img.img);
	data->img.img = mlx_new_image(data->img.mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	if (!data->img.img)
		return (0); // On free ?
	data->img.addr = mlx_get_data_addr(data->img.img, &data->img.bits_per_pixel, \
				&data->img.line_lenght, &data->img.endian);
	if (!data->img.addr)
		return (0); // On free ? 
	// render line
	ft_draw_vertical(data, data->p1, data->p2);
	mlx_put_image_to_window(data->img.mlx_ptr, data->img.win_ptr, data->img.img, 0, 0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_data	data; 

	(void)argv;
	(void)argc;
	ft_init_data(&data);
	mlx_key_hook(data.img.win_ptr, key_hook, &data); 
	mlx_hook(data.img.win_ptr, 17, 1L << 17, (void *)ft_quit, &data); // clic sur la croix
	mlx_loop_hook(data.img.mlx_ptr, ft_render_next_frame, &data);
	mlx_loop(data.img.mlx_ptr);
	return (0);
}

/*
	CETTE FONCTION SERT UNIQUEMENT A L"AFFICHAGE DONC A SUPPRIMER ENSUITE
*/
// void	ZZ_PRINT_BASE_DATA(t_base *base)
// {
// 	t_line	*elem;

// 	elem = base->list_elem;
// 	dprintf(1, "ELEM : \n");
// 	while (elem)
// 	{
// 		if (elem->ref == L_TEXTURE)
// 			dprintf(1, "TEXTURE	--> ref %d: %d str = %s\n", elem->ref, elem->texture, elem->text_path);
// 		else if (elem->ref == L_COLOR)
// 		{
// 			dprintf(1, "COLOR	--> ref %d: %c str = %s\n", elem->ref, elem->color, elem->text_path);
// 			dprintf(1, "color tab = %d - %d - %d\n", elem->col_tab[0], elem->col_tab[1], elem->col_tab[2]);
// 		}
// 		elem = elem->next;
// 	}
// 	int i = 0;
// 	dprintf(1, "\n");
// 	dprintf(1, "MAP CHAR** : \n");
// 	while (base->map_base[i])
// 	{
// 		dprintf(1, "l.%d = %s\n", i, base->map_base[i]);
// 		i++;
// 	}
// 	dprintf(1, "\n");
// 	dprintf(1, "MAP INT** : \n");
// 	i = 0;
// 	int j;
// 	dprintf(1, "game->height = %d game->width = %d\n", base->game->height, base->game->width);
// 	dprintf(1, "player: y = %d, x = %d et position = %c\n", base->game->p_y, base->game->p_x, base->game->p_direction);
// 	while (i < base->game->height)
// 	{
// 		dprintf(1, "\n");
// 		j = 0;
// 		while (j < base->game->width)
// 		{
// 			dprintf(1, "%d ", base->game->map[i][j]);
// 			j++;
// 		}
// 		i++;
// 	}
// }

// // main pour parsing
// // 	**************
// int	main(int argc, char **argv)
// {
// 	t_base	base;

// 	if (ft_check_arg_err(argc, argv[1]))
// 		return (EXIT_FAILURE);
// 	ft_init_t_base_cub(argv[1], &base);
// 	if (ft_check_file_err(&base))
// 		return (EXIT_FAILURE);
// 	ft_init_t_game(&base);
// 	ZZ_PRINT_BASE_DATA(&base);
// 	printf("pour l'instant tout est ok\n");
// 	return (0);
// }
