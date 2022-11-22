/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaillag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 21:49:51 by cgaillag          #+#    #+#             */
/*   Updated: 2021/12/29 14:04:08 by cgaillag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

/* **DESCRIPTION**
 * Ajoute l’élément ’new’ à la fin de la liste.
 * Param #1. L’adresse du pointeur vers le premier élément de la liste
 * Param #2. L’adresse du pointeur vers l’élément à rajouter à la liste
 * Valeur de retour : aucune
 *
 * En partant du pointeur du 1er element de la liste, tant que le pointeur n'est
 * pas NULL alors avancer au prochain pointeur *alst->next et affecter 
 * *alst = *alst->next
 * Si *alst == NULL, alors affecter *alst = new (pointeur NULL par defaut)
 * */

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*tmp;

	if (!new)
		return ;
	if (*alst == NULL)
	{
		*alst = new;
		return ;
	}
	tmp = ft_lstlast(*alst);
	tmp->next = new;
}
