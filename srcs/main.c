/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmelard <lmelard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 11:21:42 by cgaillag          #+#    #+#             */
/*   Updated: 2022/11/29 14:18:46 by lmelard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*	***** Parsing cub3D *****
**
**	1. check number of argc: executable + map only
**	2. check file: name (extension), empty file, accessible...

**	3. check map content: values, textures --> TODO
	- creer une structure pour la map
	- recup la map dans un char **
	- 0 toujours entoure : pas a cote de vide ou \0
		- ligne 1 : pas de 0 (car sinon map pas fermee)
		- colonne 1 : pas de 0
	- Player: verif pas en dehors de la map (a l'interieur des murs)

	- si le nom de la texture finit par .xpm mais n’est pas un fichier
		(plutot un folder… directory, donc erreur)
		- protéger texture (open O_DIRECTORY et bien close) => comme pour file

	- check env -i


	autres notes hors parsing:
		- attention aux coins
		- mettre un peu d’espace entre les murs et le joueurs (ex: 5 pixels)
*/

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

void	ft_render_map(t_data *data)
{
	int	i;
	int	j;
	int	tilex;
	int	tiley;

	i = 0;
	j = 0;
	tilex = 0;
	tiley = 0;
	while (i < data->base.nbrows)
	{
		while (j < data->base.nblines_base)
		{
			tilex = ;
			tiley = ;
			j++;
		}
		i++;
		j = 0;
	}
}

// version javascript

// render() {
// 		for (var i = 0; i < MAP_NUM_ROWS; i++) {
// 			for (var j = 0; j < MAP_NUM_COLS; j++) {
// 				var tileX = j * TILE_size;
// 				var tileY = i * TILE_size;
// 				var tileColor = this.grid[i][j] == 1 ? "#222" : "#fff";
// 				stroke("#222");
// 				fill(tileColor);
// 				rect(MINIMAP_SCALE_FACTOR * tileX, MINIMAP_SCALE_FACTOR * tileY, MINIMAP_SCALE_FACTOR * TILE_size, MINIMAP_SCALE_FACTOR * TILE_size);
// 			}
// 		}
// 	}

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
	char	**map_content;
	t_data	data; 

	(void)argv;
	(void)argc;
	map_content = NULL;	
	ft_init_data(&data);
	mlx_key_hook(data.img.win_ptr, key_hook, &data); 
	mlx_hook(data.img.win_ptr, 17, 1L << 17, (void *)ft_quit, &data); // clic sur la croix
	mlx_loop_hook(data.img.mlx_ptr, ft_render_next_frame, &data);
	mlx_loop(data.img.mlx_ptr);
	return (0);
}

// main pour parsing
//	**************
// int	main(int argc, char **argv)
// {
// 	t_base	base;

// 	if (ft_check_arg_err(argc, argv[1]))
// 		return (EXIT_FAILURE);
// 	ft_init_t_base_cub(argv[1], &base);
// 	if (ft_check_file_err(&base))
// 		return (EXIT_FAILURE);
// 	printf("pour l'instant tout est ok\n");
// 	return (0);
// }
