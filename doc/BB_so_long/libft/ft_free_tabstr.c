/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_tabstr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaillag <cgaillag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 22:52:31 by cgaillag          #+#    #+#             */
/*   Updated: 2022/06/27 23:37:12 by cgaillag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*	Frees each string of the table char** and then free the table of strings 
*/
void	*ft_free_tabstr(char **tab_str, int lines)
{
	while (lines >= 0)
	{
		free(tab_str[lines]);
		lines--;
	}
	free(tab_str);
	tab_str = NULL;
	return (NULL);
}
