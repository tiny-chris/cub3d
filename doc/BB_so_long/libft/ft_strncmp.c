/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaillag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 14:10:53 by cgaillag          #+#    #+#             */
/*   Updated: 2022/06/14 22:45:20 by cgaillag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

/*	Compares n char of 2 strings and returns an integer >, = or < to 0 
*/
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while ((i < n - 1) && s1[i] && s2[i] && s1[i] == s2[i])
	{	
		i++;
	}	
	return ((unsigned char) s1[i] - (unsigned char) s2[i]);
}
