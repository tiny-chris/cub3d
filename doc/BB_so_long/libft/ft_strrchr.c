/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaillag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 15:34:16 by cgaillag          #+#    #+#             */
/*   Updated: 2021/12/20 17:35:21 by cgaillag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

/* **DESCRITPION**
 * Rechercher un caractère dans une chaîne
 * La fonction strrchr() renvoie un pointeur sur la dernière occurrence du 
 * caractère c dans la chaîne s. 
 * NB: « caractère » signifie « octet » (ne fonctionne pas avec des caractères 
 * larges ou multi-octets).
 * Valeur de retour : un pointeur sur le caractère correspondant, ou NULL si le
 * caractère n'a pas été trouvé.
 *
 * 1) parcours de la chaine copiee 'string' avec le pointeur jusqu'a \0 inclus
 * 2) tant que le pointeur 'string' n'atteint pas le pointeur 's', on continue
 *    avec condition a l'interieur : si la valeur 'string' au niveau du pointeur
 *    == c, alors retour de l'adresse du pointeur 'string'
 * 3) traitement du cas ou la chaine est vide et cas ou c == 1ere lettre de s
 * */

char	*ft_strrchr(const char *s, int c)
{
	char			*string;
	unsigned char	uc;

	string = (char *) s;
	uc = (unsigned char) c;
	while (*string)
		string++;
	while (string != s)
	{
		if (*string == uc)
			return (string);
		string--;
	}
	if (*string == uc)
		return (string);
	return (NULL);
}
