/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaillag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 21:37:50 by cgaillag          #+#    #+#             */
/*   Updated: 2021/12/20 21:40:39 by cgaillag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

/* **DESCRIPTION**
 * Compte le nombre d’éléments de la liste.
 * Paramètre #1. Le début de la liste
 * Valeur de retour : taille de la liste
 * */

int	ft_lstsize(t_list *lst)
{
	int	lstsize;

	lstsize = 0;
	while (lst)
	{
		lstsize++;
		lst = lst->next;
	}
	return (lstsize);
}
