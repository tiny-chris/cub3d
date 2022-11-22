/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaillag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 17:26:20 by cgaillag          #+#    #+#             */
/*   Updated: 2021/12/12 18:41:06 by cgaillag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

/* *Description*
 * Applique la fonction ’f’ à chaque caractère de la chaine de caractères 
 * passée en argument pour créer une nouvelle chaine de caractères 
 * (avec malloc(3)) résultant des applications successives de ’f’.
 * Param #1. La chaine de caractères sur laquelle itérer
 * Param #2. La fonction à appliquer à chaque caractère 
 * Valeur de retour :
 * - La chaine de caractères résultant des applications successives de f. 
 *   - Retourne NULL si l’allocation échoue.
*/

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	size_t	len;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	len = ft_strlen(s);
	str = (char *) malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	while (s[i])
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
