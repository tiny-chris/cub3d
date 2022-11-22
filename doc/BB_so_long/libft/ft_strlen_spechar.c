/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_spechar.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaillag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 13:25:14 by cgaillag          #+#    #+#             */
/*   Updated: 2022/06/21 13:33:28 by cgaillag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*	Calculates the length of the string pointed to by str, excluding the
**	termination null byte ('\0') and provided character (e.g. '\n')
*/
int	ft_strlen_spechar(const char *str, char spe_c)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] == spe_c)
			return (i);
		i++;
	}
	return (i);
}
