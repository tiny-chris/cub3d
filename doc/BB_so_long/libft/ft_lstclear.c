/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaillag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 21:57:28 by cgaillag          #+#    #+#             */
/*   Updated: 2021/12/20 21:59:28 by cgaillag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

/* **DESCRIPTION**
 * Supprime et libère la mémoire de l’élément passé en paramètre, et de tous les
 * élements qui suivent, à l’aide de del et de free(3).
 * Enfin, le pointeur initial doit être mis à NULL.
 * Paramètre #1. L’adresse du pointeur vers un élément
 * Paramètre #2. L’adresse de la fonction permettant de supprimer le contenu
 * d’un élément
 * Valeur de retour : aucune
 * */

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;

	if (!del || !lst || !*lst)
		return ;
	while (lst && *lst)
	{
		tmp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = tmp;
	}
}
