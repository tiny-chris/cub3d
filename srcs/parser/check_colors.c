/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaillag <cgaillag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 22:08:18 by cgaillag          #+#    #+#             */
/*   Updated: 2022/11/26 04:45:03 by cgaillag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	dprintf(2, "str_color = %s, ft_strlen = %d\n", str_color, (int) ft_strlen(str_color));
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
	dprintf(2, "*//**//**//**line->index get color = %d\n", line->index);
	dprintf(2, "\nlen (line->content) = %d\n", (int) ft_strlen(line->content));
	len = ft_strlen_spechar(line->content, '\n');
	dprintf(2, "len spechar (line->content) = %d\n", len);
	i = 0;
	while (line->content[i] == ' ')
		i++;
	dprintf(2, "i (après espaces début) = %d\n", i);
	dprintf(2, "line->content + %d = %s\n", i, line->content + i);
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
	dprintf(2, "line->color ('C'=67 ou 'F'=70) = %d\n", line->color);
	i += 2;
	dprintf(2, "i (après += 2) = %d\n", i);
	line->text_path = ft_substr(line->content, i, len - i);
	//proteger
	line->text_path = ft_get_str_color(line, i, len);
	line->col_tab = ft_get_tab_int(line->text_path);
	// // DEBUT PRINT
	// dprintf(2, "line->text_path = %s\n", line->text_path);
	// i = 0;
	// while (i < 3)
	// {
	// 	dprintf(2, "val col_tab[%d] = %d\n", i, line->col_tab[i]);
	// 	i++;
	// }
	// // FIN PRINT
}


// void	ft_check_colors(t_line *line)
// {
// 	// 2.
// 	/*
// 		- check bien 1 de chaque

// 		- check que la color existe
// 	*/
// }


int	ft_check_color_err(t_base *base)
{
	(void) base;
	return (0);
}
