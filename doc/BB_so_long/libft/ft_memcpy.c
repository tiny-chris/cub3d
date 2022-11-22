/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaillag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 11:19:54 by cgaillag          #+#    #+#             */
/*   Updated: 2021/12/20 21:08:58 by cgaillag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h" 

/* **DESCRIPTION**
 * La fonction memcpy() copie n octets depuis la zone mémoire 'src' vers la zone 
 * mémoire 'dst'. 
 * Les deux zones ne doivent pas se chevaucher. Si c'est le cas, utilisez plutôt
 * memmove(3).
 *
 * 1) si les 2 params* sont NULL (et qq soit 'n') --> renvoyer NULL
 * 2) si le 1er param 'dst' est NULL et pas 'src' --> segfault a prevoir 
 * 3) si le 2e param 'src' est NULL et pas 'dst' --> segfault a prevoir
 * 4) si n > size de src, alors return 'dst' = src
 * 5) si n <= size de src, alors return 'dst' = src tronque jusqu'a n-1 
 * 		caracteres (yc le '\0') puis la suite de 'dst' d'origine
 * */

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*d_str;
	char	*s_str;

	i = 0;
	d_str = (char *) dst;
	s_str = (char *) src;
	if (dst == NULL && src == NULL)
		return (NULL);
	while (i < n)
	{
		d_str[i] = s_str[i];
		i ++;
	}
	return (dst);
}
