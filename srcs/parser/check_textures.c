/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaillag <cgaillag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 22:08:18 by cgaillag          #+#    #+#             */
/*   Updated: 2022/11/28 12:34:20 by cgaillag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* check textures
	- tant que espace, alors avancer
	- check les 2 premiers
	- check un espace --> si autres espaces, avancer
	-
*/
// void	ft_check_textures(t_line *line)
// {
// 	// 2.
// 	/*
// 		- check bien 1 de chaque

// 		- check que la texture existe(open) pas un directory
// 		- se termine par xpm (utiliser ft_check_filename...)
// 	*/
// }

/*
	- lire la liste

		- si range == 1

*/
void	ft_get_list_range(t_line **list_base, int i)
{
	t_line	*line;

	line = (*list_base);
	if (ft_strncmp(line->content + i, "NO ", 3) == 0)
	{
		line->texture = NO;
		line->range = 1;
	}
	else if (ft_strncmp(line->content + i, "SO ", 3) == 0)
	{
		line->texture = SO;
		line->range = 2;
	}
	else if (ft_strncmp(line->content + i, "WE ", 3) == 0)
	{
		line->texture = WE;
		line->range = 3;
	}
	else if (ft_strncmp(line->content + i, "EA ", 3) == 0)
	{
		line->texture = EA;
		line->range = 4;
	}
}

void	ft_get_texture(t_line **list_base)
{
	int		i;
	int		len;
	char	*tmp;
	t_line	*line;

	line = (*list_base);
	tmp = NULL;
	len = ft_strlen_spechar(line->content, '\n');
	i = 0;
	while (line->content[i] == ' ')
		i++;
	ft_get_list_range(&line, i);
	i += 3;
	tmp = ft_substr(line->content, i, len - i);
	//protéger
	if (tmp)
	line->text_path = ft_strtrim(tmp, " ");
	//proteger
	free(tmp);//DELONE
	tmp = NULL;
}

int	ft_check_texture_err(t_base *base)
{
	t_line	*line;

	line = base->list_elem;
	while (line)
	{
		if (line->range >= 1 && line->range < 5)
		{
			if (!ft_check_filename(line->text_path, ".xpm"))
				exit (EXIT_FAILURE);//nettoyer !!
			if (ft_check_isdirectory(line->text_path))
				exit (EXIT_FAILURE);//nettoyer !!
		}
		line = line->next;
	}
	return (EXIT_SUCCESS);
}
