/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaillag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 22:00:00 by cgaillag          #+#    #+#             */
/*   Updated: 2021/12/20 22:02:22 by cgaillag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

/* **DESCRIPTION**
 * Itère sur la liste lst et applique la fonction f au contenu chaque élément.
 * Paramètre #1 L’adresse du pointeur vers un élément
 * Paramètre #2. L’adresse de la fonction à appliquer
 * Valeur de retour : aucune
 * */

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (f == NULL)
		return ;
	while (lst != NULL)
	{
		f(lst->content);
		lst = lst->next;
	}
}
