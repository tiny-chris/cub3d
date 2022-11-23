/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmelard <lmelard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 11:21:42 by cgaillag          #+#    #+#             */
/*   Updated: 2022/11/23 17:17:57 by lmelard          ###   ########.fr       */
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

/*
	fonction aui ne prend q'un seul argument peut etre qu'il faudra que la structure
	envoyee en paramettre pointe vers d'autres structures pour tout free avant d'exit
	ou bien faire un garbage collector aussiiiiii
*/ 
void	ft_quit(t_img *img)
{
	mlx_destroy_image(img->mlx_ptr, img->img);
	mlx_destroy_window(img->mlx_ptr, img->win_ptr);
	mlx_loop_end(img->mlx_ptr);
	mlx_destroy_display(img->mlx_ptr);
	free(img->mlx_ptr);
	exit(0);
}

int	key_hook(int keycode, t_img *img)
{
	if (keycode == 65307)
		ft_quit(img);
	return (0);
}

int	main(int argc, char **argv)
{
	char	**map_content;
	t_img	img;

	(void)argv;
	(void)argc;
	map_content = NULL;
	// commente pour tester l'ouverture de la fenetre
	// if (ft_check_argc(argc) != 2)
	// 	return (EXIT_FAILURE);
	// if (ft_check_file(argv[1]))
	// 	return (EXIT_FAILURE);

	// init la map dans une structure data 
	// map_content = ft_get_map_cub(argv[1]);	
	// creer la map + init ?
	// check 3.
	
	img.mlx_ptr = mlx_init();
	img.win_ptr = mlx_new_window(img.mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "CUB3D");
	img.img = mlx_new_image(img.mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	mlx_key_hook(img.win_ptr, key_hook, &img);
	mlx_hook(img.win_ptr, 17, 1L << 17, (void *)ft_quit, &img);
	mlx_loop(img.mlx_ptr);
	printf("pour l'instant tout est ok");
	return (0);
}
