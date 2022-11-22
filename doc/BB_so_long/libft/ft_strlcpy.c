/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaillag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 14:05:32 by cgaillag          #+#    #+#             */
/*   Updated: 2021/12/20 21:18:32 by cgaillag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

/* **DESCRIPTION**
 * La fonction strlcpy() copie des chaines de caracteres. Elle prend en 
 * consideration la taille de 'dst' et garantie un caractere nul final au 
 * resultat (tant que size > 0, i.e. tant qu'il y a assez de place).
 * NB:	Un byte pour le carctere NUL doit etre inclus dans la taille 'size'.
 * 		strlcpy() ne fonctionne que sur des chaines de caracteres sur "C", i.e.
 *		la chaine de caracteres 'src' doit se terminer par un caractere nul.
 * La fonction strlcpy() copie jusqu'a 'size -1' caracteres de 'src' vers 'dst',
 * en terminant le resultat par un caractere nul si la taille n'est pas 0.
 * Valeur de retour : la longueur de 'src', cela permet d'identifier si il y a 
 * eu troncature (c'est le cas si la valeur de retour >= size).
 * 
 * Note: si 'dst' ou 'src' est NULL, le cas n'est pas gere --> segfault
 * */

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (size > 0)
	{
		while (src[i] != '\0' && j < (size - 1))
		{
			dst[j] = src[i];
			j++;
			i++;
		}
		dst[j] = '\0';
	}
	while (src[i] != '\0')
		i++;
	return (i);
}
