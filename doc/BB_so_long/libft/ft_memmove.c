/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaillag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 11:17:22 by cgaillag          #+#    #+#             */
/*   Updated: 2022/06/15 00:33:04 by cgaillag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*	Copies 'len' bytes from memory area 'src' to memory area 'dst'.  The memory 
**	areas may overlap: copying takes place as though the bytes in 'src' are 
**	first copied into a temporary array that does not overlap src or dst, and 
**	the bytes are then copied from the temporary array to dst.
*/
void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*d_str;
	char	*s_str;

	d_str = (char *) dst;
	s_str = (char *) src;
	if (!dst && !src)
		return (NULL);
	if (s_str < d_str)
	{
		while (len > 0)
		{
			d_str[len - 1] = s_str[len - 1];
			len--;
		}
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
