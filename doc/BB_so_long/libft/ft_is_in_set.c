/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_in_set.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaillag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 13:11:38 by cgaillag          #+#    #+#             */
/*   Updated: 2022/06/21 13:20:51 by cgaillag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*  Checks if char 'c' is in the defined 'set' string
**	- if yes    --> return 1
**  - if no     --> return 0
** 	Checks if there is a char 'c' in the defined 'set' string 
**	and returns 1 for yes and 0 for no 
**	nb: useful for the read loop in gnl main function
*/
size_t	ft_is_in_set(const char *set, char c)
{
	size_t	i;

	if (!set)
		return (0);
	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i ++;
	}
	return (0);
}
