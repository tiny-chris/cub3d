/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lines_tabstr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaillag <cgaillag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 22:55:48 by cgaillag          #+#    #+#             */
/*   Updated: 2022/06/27 23:42:30 by cgaillag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*	Counts the number of strings of a char** 
*/
int	ft_lines_tabstr(char **tab_str)
{
	int		i;

	if (!tab_str)
		return (0);
	i = 0;
	while (tab_str[i])
		i++;
	return (i);
}
