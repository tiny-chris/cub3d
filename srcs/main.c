/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmelard <lmelard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 11:21:42 by cgaillag          #+#    #+#             */
/*   Updated: 2022/11/29 17:31:50 by lmelard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_init_player(t_data *data)
{
	data->player.x = WIN_WIDTH / 2;
	data->player.y = WIN_HEIGHT / 2;
	data->player.width = 5;
	data->player.height = 5;
	data->player.turnDirection = 0;
	data->player.walkDirection = 0;
	data->player.rotationAngle = M_PI / 2;
	data->player.turnSpeed =  45 * (M_PI / 180); // 2 * (M_PI / 180) dans le js; 
	data->player.walkSpeed = 2.0;
}

void	ft_init_data(t_data *data)
{
	// init data mlx
	data->img.mlx_ptr = mlx_init();
	data->img.win_ptr = mlx_new_window(data->img.mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "CUB3D");
	data->img.img = mlx_new_image(data->img.mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	if (!data->img.img)
		return ; // On free ?
	data->img.addr = mlx_get_data_addr(data->img.img, &(data->img.bits_per_pixel), \
				&(data->img.line_lenght), &(data->img.endian));
	if (!data->img.addr)
		return ; // On free ?
	// init player
	ft_init_player(data);
	// tests points
	// data->p1.x = 10;
	// data->p1.y = 100;
	// data->p2.x = 10;
	// data->p2.y = 500;
}

void	ft_draw_rect(t_data *data, t_point tile)
{
	int		color;
	t_point	tile2;
	t_point	tile3;
	t_point	tile4;
	
	//map = data->base.game->map;
//	printf("map[tile.x][tile.y] = %d\n", map[tile.x][tile.y]);
	// if (map && map[tile.x][tile.y] == 1)
	// {
	// 	printf("test\n");
	// 	color = COLOR_MAP_WALL;
	// }
	// else
	// 	color = COLOR_MAP_NOWALL;
	color = COLOR_MAP_NOWALL;
	tile2.x = tile.x + TILE_SIZE;
	tile2.y = tile.y;
	tile3.x = tile.x;
	tile3.y = tile.y + TILE_SIZE;
	tile4.x = tile.x + TILE_SIZE;
	tile4.y = tile.y + TILE_SIZE;
	ft_draw_horizontal(data, tile, tile2, color);
	ft_draw_vertical(data, tile, tile3, color);
	ft_draw_horizontal(data, tile3, tile4, color);
	ft_draw_vertical(data, tile2, tile4, color);
}

void	ft_render_map(t_data *data)
{
	int		i;
	int		j;
	t_point	tile;
	int 	**map;

	i = 0;
	j = 0;
	tile.x = 0;
	tile.y = 0;
	map = data->base.game->map;
	while (i < data->base.game->cols)
	{
		while (j < data->base.game->rows)
		{
			printf("i = %d\n j = %d\n", i, j);
			printf("map[i][j] = %d\n", map[i][j]);
			tile.x = i * TILE_SIZE;
			tile.y = j * TILE_SIZE;
			ft_draw_rect(data, tile);
			j++;
		}
		i++;
		j = 0;
	}
}

int	ft_render_next_frame(t_data *data)
{
	mlx_destroy_image(data->img.mlx_ptr, data->img.img);
	data->img.img = mlx_new_image(data->img.mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	if (!data->img.img)
		return (0); // On free ?
	data->img.addr = mlx_get_data_addr(data->img.img, &data->img.bits_per_pixel, \
				&data->img.line_lenght, &data->img.endian);
	if (!data->img.addr)
		return (0); // On free ? 
	// render line
	ft_render_map(data);
	mlx_put_image_to_window(data->img.mlx_ptr, data->img.win_ptr, data->img.img, 0, 0);
	return (1);
}


/*
	CETTE FONCTION SERT UNIQUEMENT A L"AFFICHAGE DONC A SUPPRIMER ENSUITE
*/
void	ZZ_PRINT_BASE_DATA(t_base *base)
{
	t_line	*elem;

	elem = base->list_elem;
	dprintf(1, "ELEM : \n");
	while (elem)
	{
		if (elem->ref == L_TEXTURE)
			dprintf(1, "TEXTURE	--> ref %d: %d str = %s\n", elem->ref, elem->texture, elem->text_path);
		else if (elem->ref == L_COLOR)
		{
			dprintf(1, "COLOR	--> ref %d: %c str = %s\n", elem->ref, elem->color, elem->text_path);
			dprintf(1, "color tab = %d - %d - %d\n", elem->col_tab[0], elem->col_tab[1], elem->col_tab[2]);
		}
		elem = elem->next;
	}
	int i = 0;
	dprintf(1, "\n");
	dprintf(1, "MAP CHAR** : \n");
	while (base->map_base[i])
	{
		dprintf(1, "l.%d = %s\n", i, base->map_base[i]);
		i++;
	}
	dprintf(1, "\n");
	dprintf(1, "MAP INT** : \n");
	i = 0;
	int j;
	dprintf(1, "game->height = %d game->width = %d\n", base->game->height, base->game->width);
	dprintf(1, "player: y = %d, x = %d et position = %c\n", base->game->p_y, base->game->p_x, base->game->p_direction);
	while (i < base->game->height)
	{
		dprintf(1, "\n");
		j = 0;
		while (j < base->game->width)
		{
			dprintf(1, "%d ", base->game->map[i][j]);
			j++;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_data	data;

	// (void)argv;
	// (void)argc;
	if (ft_check_arg_err(argc, argv[1]))
		return (EXIT_FAILURE);
	ft_init_t_base_cub(argv[1], &data.base);
	if (ft_check_file_err(&data.base))
		return (EXIT_FAILURE);
	ft_init_t_game(&data.base);
	ZZ_PRINT_BASE_DATA(&data.base);
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
