/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_free_tabs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaillag <cgaillag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 16:48:15 by cgaillag          #+#    #+#             */
/*   Updated: 2022/12/08 12:01:34 by cgaillag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	*ft_free_tabint2(int **tab_int, int size, int type)
{
	int	i;

	i = 0;
	if (tab_int == NULL)
		return (NULL);
	if (type != TAB_INT2)
	{
		while (i < size)
		{
			free(tab_int[i]);
			tab_int[i] = NULL;
			i++;
		}
	}
	free(tab_int);
	tab_int = NULL;
	return (NULL);
}

void	ft_free_strs(char *str1, char *str2, char *str3)
{
	if (str1 != NULL)
	{
		free(str1);
		str1 = NULL;
	}
	if (str2 != NULL)
	{
		free(str2);
		str2 = NULL;
	}
	if (str3 != NULL)
	{
		free(str3);
		str3 = NULL;
	}
}

void	ft_free_ints(int *t_int1, int *t_int2, int *t_int3)
{
	if (t_int1 != NULL)
	{
		free(t_int1);
		t_int1 = NULL;
	}
	if (t_int2 != NULL)
	{
		free(t_int2);
		t_int2 = NULL;
	}
	if (t_int3 != NULL)
	{
		free(t_int3);
		t_int3 = NULL;
	}
}

/*	<SUMMARY> Deletes char ** depending on the given type:
**	- if type == TAB_STR2: only the char ** (and not char *)
**	- if type == TAB_STRS/else: deletes char ** AND char*
*/
void	*ft_free_tabstr2(char **tab_str, int type)
{
	int	i;

	i = 0;
	if (tab_str != NULL)
	{
		if (type != TAB_STR2)
		{
			while (tab_str[i])
			{
				free(tab_str[i]);
				tab_str[i] = NULL;
				i++;
			}
		}
		free(tab_str);
		tab_str = NULL;
	}
	return (NULL);
}
