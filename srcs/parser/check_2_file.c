/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_2_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaillag <cgaillag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 16:48:15 by cgaillag          #+#    #+#             */
/*   Updated: 2022/11/28 12:52:39 by cgaillag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// QUESTION - REVOIR POUR * ou **
// penser à nettoyer !!!!!!! après le 'exit(1)...'
static void	ft_check_lines_order_post_elem(t_base **base, t_line **list_base)
{
	t_line	*line;

	(void) base;
	line = (*list_base);
	if (line)
		dprintf(2, "line->ref = %d\n", line->ref);
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

/*
	check 1 : elem en haut (tant qu'on n'a pas atteint la map)
		- si unexpected line --> error (commence par autre chose que les élém 
		ou 1 ou vide)
		- si texture --> ajouter au nb de textures
		- si color --> ajouter au nb de colors
		- si nb text est différent de 4 --> erreur
		- si nb color est différent de 2 --> erreur
**	check 2 : si j'atteinds la map
		- tant que ce sont des L_MAP --> on avance
		- si on rencontre ensuite un L_TEXTURE ou L_COLOR ou L_UNEXPECT --> erreur
		- si on a un L_EMPTY, tant qu'on a des L_EMPTY --> on avance
		- si on a encore des lignes (pas L_EMPTY) --> erreur
**	check 3 : map non atteinte --> pas de map
		--> erreur
*/
// !!!!!!!!!!!!!!!
//
//	supprimer la variable "x" pour le dprintf
//
//	penser à nettoyer !!!!!!! après le 'exit(1)...'
//
// !!!!!!!!!!!!!!!
int	ft_check_lines_order_err(t_base *base)
{
	t_line	*line;
	int		nb_text;
	int		nb_color;

	dprintf(2, "2e etape ****************\n");
	line = base->list_base;
	nb_text = 0;
	nb_color = 0;
	while (line && line->ref != L_MAP)
	{
		if (line->ref == L_UNEXPECT)
			exit(EXIT_FAILURE);
		else if (line->ref == L_TEXTURE)
			nb_text++;
		else if (line->ref == L_COLOR)
			nb_color++;
		line = line->next;
	}
	if (nb_text != 4 || nb_color != 2)
		exit(ft_err_msg(1, "TBD 1 - text or color", "à preciser ? nb incorr"));
	ft_check_lines_order_post_elem(&base, &line);
	return (0);
}

/*
	je parcours à nouveau ma liste pour checker :
	1. les textures + 'feed' et 'range'
	2. les colors + 'feed' et 'range'
	3. la map

	puis je copie dans les char ** respectifs
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


/*  ***** Parsing - ........ *****
**  *************************
**  <SUMMARY>
**
**	nb de lignes
**	position des elements et de la map

	/!\ à la pace de 'return (EXIT_FAILURE);
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
	if (ft_check_texture_err(base))
		return (EXIT_FAILURE);
	// if (ft_check_color_err(base))
	// 	return (EXIT_FAILURE);
	if (ft_check_map_err(base))
		return (EXIT_FAILURE);
	ft_get_map_tabint(base->map_base);
	return (EXIT_SUCCESS);
}

// t_bool	ft_check_cub(const char **specs)
// {
// 	int		height;

// 	height = 0;
// 	while (specs[height + 1])
// 		height++;
// 	if (*specs[height] == '\0')
// 	{
// 		ft_freetab ((void **)specs);
// 		return (write (2, "Error\nInvalid .cub map\n", 23) == 0);
// 	}
// 	if (ft_check_cub_elements(specs) == FALSE)
// 	{
// 		ft_freetab ((void **)specs);
// 		return (FALSE);
// 	}
// 	return (TRUE);
// }

// int	ft_check_lines_order(t_base *b)
// {
// 	int		i;
// 	int		j;
// 	t_line	*line;

// 	i = 0;
// 	line = NULL;
// 	while (b->file_base[i])
// 	{
// 		dprintf(2, "test là 1\n");
// 		j = 0;
// 		while (b->file_base[i][j] == ' ')
// 			j++;
// 		dprintf(2, "test là 2\n");
// 		dprintf(2, "b->file_base[%d][%d] = %c\n", i, j, b->file_base[i][j]);
// 		dprintf(2, "b->file_base[%d][%d] = %c\n", i, j + 1, b->file_base[i][j + 1]);
// 		if (b->file_base[i][j] == '\0')
// 		{
// 			dprintf(2, "test là 3\n");
// 			ft_lstadd_line(&line, i, "", L_EMPTY);
// 		}
// 		else if ((b->file_base[i][j] == 'N' && b->file_base[i][j + 1] == 'O')
// 		|| (b->file_base[i][j] == 'S' && b->file_base[i][j + 1] == 'O')
// 		|| (b->file_base[i][j] == 'W' && b->file_base[i][j + 1] == 'E')
// 		|| (b->file_base[i][j] == 'E' && b->file_base[i][j + 1] == 'A'))
// 		{
// 			dprintf(2, "test là 4\n");
// 			ft_lstadd_line(&line, i, b->file_base[i], L_TEXTURE);
// 			dprintf(2, "test là 5\n");
// 		}
// 		else if (b->file_base[i][j] == 'F' || b->file_base[i][j] == 'C')
// 			ft_lstadd_line(&line, i, b->file_base[i], L_COLOR);
// 		else
// 			ft_lstadd_line(&line, i, b->file_base[i], L_MAP);
// 		i++;
// 	}
// 	/*
// 	**	DEBUT - affichage
// 	*/
// 	t_line	*tmp = line;
// 	int		k = 0;
// 	while (tmp)
// 	{
// 		dprintf(2, "k = %d, tmp[%d] = %s, type = %d\n", k, tmp->line_index, tmp->line_content, tmp->line_ref);
// 		tmp = tmp->next;
// 		k++;
// 	}
// 	/*
// 	**	FIN - affichage
// 	*/
// 	return (0);
// }
