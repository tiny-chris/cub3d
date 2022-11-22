/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaillag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 10:34:09 by cgaillag          #+#    #+#             */
/*   Updated: 2022/06/15 00:35:00 by cgaillag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

/*	Allocates sufficient memory for a copy of the string 'str', does the copy
**  and returns a pointer to it.
*/
char	*ft_strdup(char *src)
{
	size_t	i;
	size_t	size;
	char	*copy;

	i = 0;
	size = ft_strlen(src);
	copy = (char *) malloc(sizeof(*copy) * (size + 1));
	if (copy == NULL)
		return (0);
	while (i < size)
	{
		copy[i] = src[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}
