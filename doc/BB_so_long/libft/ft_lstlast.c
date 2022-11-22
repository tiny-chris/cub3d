/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaillag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 21:42:23 by cgaillag          #+#    #+#             */
/*   Updated: 2021/12/29 14:03:12 by cgaillag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

/* **DESCRIPTION**
 * Renvoie le dernier élément de la liste
 * Paramètre #1. Le début de la liste
 * Valeur de retour : dernier élément de la liste
 *
 * Rappel : next = adresse du maillon suivant de la liste ou NULL si le maillon
 * est le dernier (utiliser une boucle: j'avance de '->next' jusqu'au pointeur
 * NULL, et alors je retourne la derniere valeur de lst
 * */

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*tmp;

	if (lst == NULL)
		return (NULL);
	tmp = lst;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}
