/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaillag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 10:24:16 by cgaillag          #+#    #+#             */
/*   Updated: 2021/12/20 21:33:25 by cgaillag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

/* DEFINITION
 * Alloue (avec malloc(3)) et renvoie un nouvel élément. La variable content est
 * initialisée à l’aide de la valeur du paramètre content. La variable ’next’ 
 * est initialisée à NULL.
 * Paramètre #1. Le contenu du nouvel élément
 * Valeur de retour : le nouvel element
 * */
// MAILLON !!!
/* La description des champs de la structure t_list est la suivante :
 * - content : La donnée contenue dans le maillon. Le void * permet de stocker 
 *   une donnée de n’importe quel type.
 * - next : L’adresse du maillon suivant de la liste ou NULL si le maillon est 
 *   le dernier.
 *   */

t_list	*ft_lstnew(void *content)
{
	t_list	*lstnew;

	lstnew = malloc(sizeof(t_list));
	if (lstnew == NULL)
		return (NULL);
	(*lstnew).content = content;
	(*lstnew).next = NULL;
	return (lstnew);
}
