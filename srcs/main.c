/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmelard <lmelard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 11:21:42 by cgaillag          #+#    #+#             */
/*   Updated: 2022/11/28 18:15:03 by lmelard          ###   ########.fr       */
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
