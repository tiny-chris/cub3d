/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaillag <cgaillag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 19:10:42 by cgaillag          #+#    #+#             */
/*   Updated: 2022/11/28 12:20:31 by cgaillag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

/*  Checks if char 'c' is in the defined 'set' string
	Returns how many times
*/
int	ft_count_isinset(char *str, char c)
{
	size_t	i;
	int		count;

	if (!str)
		return (0);
	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			count++;
		i ++;
	}
	return (count);
}
