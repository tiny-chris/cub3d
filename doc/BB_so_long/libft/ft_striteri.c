/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaillag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 17:20:33 by cgaillag          #+#    #+#             */
/*   Updated: 2021/12/20 21:21:10 by cgaillag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

/* *Description*
 * Applique la fonction f à chaque caractère de la chaîne de caractères 
 * transmise comme argument, et en passant son index comme premier argument. 
 * Chaque caractère est transmis par adresse à f pour être modifié si nécess.
 * Param #1. La chaine de caractères sur laquelle itérer
 * Param #2. La fonction à appliquer à chaque caractère 
 * Valeur de retour : aucune
*/

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
	return ;
}
