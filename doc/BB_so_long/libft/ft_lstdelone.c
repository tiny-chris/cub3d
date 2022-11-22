/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaillag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 12:42:44 by cgaillag          #+#    #+#             */
/*   Updated: 2021/12/20 21:56:57 by cgaillag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

/* **DESCRIPTION**
 * Libère la mémoire de l’élément passé en argument en utilisant la fonction del
 * puis avec free(3). La mémoire de next ne doit pas être free.
 * Paramètre #1. L’élément à free
 * Paramètre #2. L’adresse de la fonction permettant de supprimer le contenu de
 * l'élément
 * Valeur de retour : aucune
 *
 *
 * */

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (lst && del)
	{
		del(lst->content);
		free(lst);
	}
}
