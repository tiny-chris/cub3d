/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaillag <cgaillag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 16:48:15 by cgaillag          #+#    #+#             */
/*   Updated: 2022/11/25 13:26:57 by cgaillag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
		{
			ft_err_msg(1, "TBD 2", "autres éléments (text/col/unex) après la map");
			exit(EXIT_FAILURE);//nettoyer
		}
		while (line && line->ref == L_EMPTY)
			line = line->next;
		if (line && line->ref != L_EMPTY)
		{
			ft_err_msg(1, "TBD 3", "autres éléments (text/col/unex/map...) après empty");
			exit(EXIT_FAILURE);//nettoyer
		}
	}
	else//on est arrivé à la fin et il n'y a pas eu de map
	{
		ft_err_msg(1, "TBD 4", "pas de map");
		exit(EXIT_FAILURE);//nettoyer
	}
}

/*
	check 1 : elem en haut (tant qu'on n'a pas atteint la map)
		- si unexpected line --> error (commence par autre chose que les élém ou 1 ou vide)
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
int	ft_check_lines_order(t_base *base)
{
	t_line	*line;
	int		nb_text;
	int		nb_color;
	int		x = 0;//drpintf

	dprintf(2, "2e etape ****************\n");
	line = base->list_base;
	nb_text = 0;
	nb_color = 0;
	dprintf(2, "nb_text = %d et nb_color = %d\n", nb_text, nb_color);
	while (line && line->ref != L_MAP)
	{
		dprintf(2, "line->ref %d = %d\n", x++, line->ref);
		if (line->ref == L_UNEXPECT)
			exit(EXIT_FAILURE);//nettoyer
		else if (line->ref == L_TEXTURE)
			nb_text++;
		else if (line->ref == L_COLOR)
			nb_color++;
		line = line->next;
	}
	dprintf(2, "nb_text = %d et nb_color = %d\n", nb_text, nb_color);
	if (nb_text != 4 || nb_color != 2)
	{
		ft_err_msg(1, "TBD 1 - text or color", "nombre incorrect (détail text / col)");
		exit(EXIT_FAILURE);//nettoyer
	}
	if (line != NULL)
		dprintf(2, "bonus -- line->ref %d = %d\n", x++, line->ref);
	ft_check_lines_order_post_elem(&base, &line);
	return (0);
}



/* check textures
	- tant que espace, alors avancer
	- check les 2 premiers
	- check un espace --> si autres espaces, avancer
	-
*/
void	ft_check_textures(t_line *line)
{
	int		i;
	int		len;
	char	*tmp;

	i = 0;
	len = ft_strlen_spechar(line->content, '\n');
	//feed node and then check
	// 1.
	while (line->content[i] == ' ')
		i++;
	if (ft_strncmp(line->content + i, "NO ", 3) == 0)
		line->texture = NO;
	else if (ft_strncmp(line->content + i, "SO ", 3) == 0)
		line->texture = SO;
	else if (ft_strncmp(line->content + i, "WE ", 3) == 0)
		line->texture = WE;
	else if (ft_strncmp(line->content + i, "EA ", 3) == 0)
		line->texture = EA;
	i += 3;
	// while (line->content[i] == ' ')
	// 	i++;
	tmp = ft_substr(line->content, i, len - i);// +1 ??
	line->text_path = ft_strtrim(tmp, " ");
	// 2.
	/*
		- check bien 1 de chaque

		- check que la texture existe(open) pas un directory
		- se termine par xpm (utiliser ft_check_filename...)
	*/
}

// void	ft_check_colors(t_line *line)
// {
// 	int		i;
// 	int		len;
// 	char	*tmp;

// 	i = 0;
// 	len = ft_strlen_spechar(line->content, '\n');
// 	tmp = NULL;
// 	//feed node and then check
// 	// 1.
// 	while (line->content[i] == ' ')
// 		i++;
// 	if (ft_strncmp(line->content + i, "C ", 2) == 0)
// 		line->color = 'C';
// 	else if (ft_strncmp(line->content + i, "F ", 23) == 0)
// 	i += 2;
// 	// while (line->content[i] == ' ')
// 	// 	i++;
// 	line->text_path = ft_substr(line->content, i, len - i);// +1 ??
// 	tmp = ft_strtrim(line->text_path, " ");
// 	len = (int) ft_strlen(tmp);
// 	free(line->text_path);
// 	i = 0;
// 	while (tmp[i])
// 	{
// 		if (tmp[i] == ' ')
// 			len--;
// 		i++;
// 	}
// 	line->text_path = ft_malloc(TAB_STR1, len + 1);
// 	int	j;
// 	j = 0;
// 	while (tmp[i])
// 	{
// 		if (tmp[i] != ' ')
// 		{
// 			line->text_path[j] = tmp[i];
// 			j++;
// 		}
// 		i++;
// 	}
// 	line->text_path[j] = '\0';
// 	// découper pour mettre dans un tableau et checker val de 0 à 255
// 	char	**tab_str;

// 	tab_str = ft_split2(line->text_path, ',');
// 	// proteger
// 	// comme push_swap: verifier si nb uniquement et compris entre 0 et 255 inclus

// 	// 2.
// 	/*
// 		- check bien 1 de chaque

// 		- check que la color existe
// 	*/
// }

/*
	je parcours à nouveau ma liste pour checker :
	1. les textures + 'feed' et 'range'
	2. les colors + 'feed' et 'range'
	3. la map

	puis je copie dans les char ** respectifs
*/

// ZZZZZZZZZ_ JE DOIS REPRENDRE ICI !!!!!!!!
void	ft_get_file_base_detailed(t_base *base)
{
	t_line	*line;
	int		i;

	line = base->list_base;
	while (line && line->ref != L_MAP)
	{
		if (line->ref == L_TEXTURE)
			ft_get_texture(&line);
		else if (line-ref == L_COLOR)
			ft_get_color(&line);
		line = line->next;
	}
	ft_get_map_base(&line);
	return ;
}

int	ft_check_elem_err(char **elem_base)
{
	(void) elem_base;
	return (0);
}

int	ft_check_map_err(char **map_base)
{
	(void) map_base;
	return (0);
}

/*  ***** Parsing - ........ *****
**  *************************
**  <SUMMARY>
**
**	nb de lignes
**	position des elements et de la map
**
*/
int	ft_check_file_err(t_base *base)
{
	// (void) base;
	// dprintf(2, "test ici 1\n");
	ft_check_lines_order(base);
	// dprintf(2, "test ici 2\n");
	// ft_get_file_base_detailed(base);
	// dprintf(2, "test ici 3\n");
	// if (ft_check_map_err(base->map_base) || ft_check_elem_err(base->elem_base))
	// 	return (EXIT_FAILURE);
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
