/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_2_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaillag <cgaillag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 16:48:15 by cgaillag          #+#    #+#             */
/*   Updated: 2022/11/29 11:37:54 by cgaillag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*  ***** Parsing - check lines order (subpart) *****
**  *************************
**  <SUMMARY>	Check if there are other line types than 'L_MAP' between first 
**	and last L_MAP lines (only L_EMPTY lines are allowed after L_MAP lines)
**	<RETURN>	none
**				if error --> only exit 
*/
static void	ft_check_lines_order_post_elem(t_base **base, t_line **list_base)
{
	t_line	*line;

	(void) base;
	line = (*list_base);
	if (line && (line->ref) == L_MAP)
	{
		line->range = 7;
		while (line && line->ref == L_MAP)
			line = line->next;
		if (line && (line->ref == L_TEXTURE || line->ref == L_COLOR \
			|| line->ref == L_UNEXPECT))
			exit(ft_err_msg(1, "TBD 2", "élém (text/col/unex) après map"));
		while (line && line->ref == L_EMPTY)
			line = line->next;
		if (line && line->ref != L_EMPTY)
			exit(ft_err_msg(1, "TBD 3", "pb text/col/unex/map... après empty"));
	}
	else
		exit(ft_err_msg(1, "TBD 4", "pas de map"));
}

/*  ***** Parsing - check lines order *****
**  *************************
**  <SUMMARY>	Check number of textures & colors and if they are before map line
**	<RETURN>	- if error		--> return 1 + display error message
**  			- if no error	--> return 0 
*/
int	ft_check_lines_order_err(t_base *base)
{
	t_line	*line;
	int		nb_text;
	int		nb_color;

	line = base->list_base;
	nb_text = 0;
	nb_color = 0;
	while (line && line->ref != L_MAP)
	{
		if (line->ref == L_UNEXPECT)
			exit(EXIT_FAILURE);//
		else if (line->ref == L_TEXTURE)
			nb_text++;
		else if (line->ref == L_COLOR)
			nb_color++;
		line = line->next;
	}
	if (nb_text != 4 || nb_color != 2)
		exit(ft_err_msg(1, "TBD 1 - text or color", "à preciser ? nb incorr"));//
	ft_check_lines_order_post_elem(&base, &line);
	return (0);
}

/*  ***** Parsing - check lines order *****
**  *************************
**  <SUMMARY>	Feed base structure with file content to facilitate check:
**				- on elements (textures + colors)
**				- on map 
*/
void	ft_get_file_base_detailed(t_base *base)
{
	t_line	*line;

	line = base->list_base;
	while (line && line->ref != L_MAP)
	{
		if (line->ref == L_TEXTURE)
			ft_get_texture(&line);
		else if (line->ref == L_COLOR)
			ft_get_color(&line);
		line = line->next;
	}
	base->list_elem = ft_get_elem_base(base);
	base->map_base = ft_get_map_base(base);
	return ;
}
/*
	pour tester l'affichage de la liste d'elem (t_line)

	// DEBUT AFFICHAGE - à supprimer
	t_line	*tmp;
	int		nb = 0;
	tmp = base->list_elem;
	while (tmp)
	{
		dprintf(2, "list_elem[%d] text_path = %s\n", ++nb, tmp->text_path);
		if (tmp->color == 'F' || tmp->color == 'C')
			dprintf(2, "col_tab[%d] col_tab[0] = %d\n", nb, tmp->col_tab[0]);
		tmp = tmp->next;
	}
	// FIN AFFICHAGE

*/

/*  ***** Parsing - check file content *****
**  *************************
**  <SUMMARY>	Main checking function on detailed content of the file
**	<RETURN>	- EXIT_FAILURE if any error
**				- EXIT_SUCCESS to continue the program
*/
/*  *************************
**
	/!\ à la place de 'return (EXIT_FAILURE);
	//protéger et exit
**
*/
int	ft_check_file_err(t_base *base)
{
	if (ft_check_lines_order_err(base))
		return (EXIT_FAILURE);
	ft_get_file_base_detailed(base);
	if (ft_check_elem_err(base))
		return (EXIT_FAILURE);
	if (ft_check_map_err(base))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
