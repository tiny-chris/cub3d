/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaillag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 22:02:39 by cgaillag          #+#    #+#             */
/*   Updated: 2021/12/20 22:18:22 by cgaillag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

/* **DESCRIPTION**
 * Itère sur la liste lst et applique la fonction f au contenu de chaque 
 * élément. Crée une nouvelle liste résultant des applications successives de f.
 * La fonction del est la pour detruire le contenu d un element si necessaire.
 * Valeur de retour : La nouvelle liste. NULL si l’allocation échoue.
 *
 * Tant que la liste lst existe, alors:
 * - j'alloue de la memoire a 'tmp' pour etre egal au 1er maillon de lst auquel
 *   est appliquee la fonction f
 * - puis, si l'allocation est ok, j'ajoute tmp a la fin de ma nouvelle liste 
 *   avec ft_lstadd_back
 * - enfin, je me deplace dans la liste lst->next pour mon prochain 'tmp' egal 
 *   au 2e maillon et ainsi de suite (jusqu'a lst->next NULL)
 * Si l'allocation fonctionne: je retourne 'new_lst'
 * Sinon, je retourne "NULL" et je supprime + free la new_lst
 * */

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*tmp;
	t_list	*new_lst;

	if (!f || !lst)
		return (NULL);
	new_lst = NULL;
	while (lst)
	{
		tmp = ft_lstnew(f(lst->content));
		if (!tmp)
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, tmp);
		lst = lst->next;
	}
	return (new_lst);
}
