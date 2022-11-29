/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaillag <cgaillag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 22:08:18 by cgaillag          #+#    #+#             */
/*   Updated: 2022/11/29 11:39:30 by cgaillag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// 	/*
// 		- check bien 1 de chaque

// 		- check que la color existe
// 	*/
char	*ft_get_str_color(t_line *line, int i, int len)
{
	char	*str_color;
	char	*tmp;

	str_color = ft_substr(line->content, i, len - i);
	//protéger
	tmp = ft_strtrim(str_color, " ");
	//protéger
	free (str_color);//DELONE
	str_color = ft_malloc(TAB_STR1, ft_len_delspace_str(tmp) + 1);
	i = 0;
	len = 0;
	while (tmp[i])
	{
		if (tmp[i] != ' ')
		{
			str_color[len] = tmp[i];
			len++;
		}
		i++;
	}
	str_color[len] = '\0';
	return (str_color);
}

/*
	- creates a table of strings using ft_split
	- check if the number of strings == 3 (3 colors), if not: error
	- create a table of int, malloc it (size 3) + protect
	- check if each string can be converted to an int
		if so: put the converted string into the table of int
		if at least, 1 string cannot be converted: error
*/
int	*ft_get_tab_int(char *text_path)
{
	char	**tab_str;
	int		*tab;
	int		i;
	int		n;

	i = -1;
	tab = NULL;
	tab_str = ft_split2(text_path, ',');
	//protéger
	if (ft_lines_tabstr(tab_str) != 3)
	{
		ft_err_msg(1, NULL, "error on nb of colors references");
		exit (EXIT_FAILURE);//nettoyer
	}
	tab = ft_malloc(TAB_INT1, 3);//protégé
	while (++i < 3)
	{
		n = ft_atoi_cub(tab_str[i]);
		if (n < 0 || n > 255)
		{
			ft_err_msg(1, NULL, "error on colors values");
			exit (EXIT_FAILURE);//nettoyer
		}
		tab[i] = n;
	}
	free(tab_str);//DELONE
	tab_str = NULL;
	return (tab);
}

void	ft_get_color(t_line **list_base)
{
	int		i;
	int		len;
	t_line	*line;

	line = (*list_base);
	len = ft_strlen_spechar(line->content, '\n');
	i = 0;
	while (line->content[i] == ' ')
		i++;
	if (ft_strncmp(line->content + i, "C ", 2) == 0)
	{
		line->color = 'C';
		line->range = 5;
	}
	else if (ft_strncmp(line->content + i, "F ", 2) == 0)
	{
		line->color = 'F';
		line->range = 6;
	}
	i += 2;
	line->text_path = ft_substr(line->content, i, len - i);
	//proteger
	line->text_path = ft_get_str_color(line, i, len);
	line->col_tab = ft_get_tab_int(line->text_path);
}
