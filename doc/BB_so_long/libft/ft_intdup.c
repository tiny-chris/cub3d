/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaillag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 23:09:51 by cgaillag          #+#    #+#             */
/*   Updated: 2022/06/14 23:11:17 by cgaillag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

/*	Allocates sufficient memory for a copy of a table of int, does the copy
**  and returns a pointer to it.
**	i.e. duplicate a table of int
*/
int	*ft_intdup(int *tab, int size)
{
	int	i;
	int	*copy;

	i = 0;
	copy = (int *)malloc(sizeof(int) * size);
	if (copy == NULL)
		return (0);
	while (i < size)
	{
		copy[i] = tab[i];
		i++;
	}
	return (copy);
}
