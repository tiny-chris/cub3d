/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaillag <cgaillag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 11:21:42 by cgaillag          #+#    #+#             */
/*   Updated: 2022/11/22 11:15:16 by cgaillag         ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	char	**map_content;

	map_content = NULL;
	if (ft_check_argc(argc) != 2)
		return (EXIT_FAILURE);
	if (ft_check_file(argv[1]))
		return (EXIT_FAILURE);
	// map_content = ft_get_map_cub(argv[1]);	
	//creer la map + init ?
	// check 3.
	printf("pour l'instant tout est ok");
	return (0);
}
