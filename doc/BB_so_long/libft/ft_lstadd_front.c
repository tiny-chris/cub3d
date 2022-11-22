/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaillag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 12:51:53 by cgaillag          #+#    #+#             */
/*   Updated: 2021/12/29 13:25:13 by cgaillag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

/* DESCRIPTION
 * Ajoute l’élément ’new’ au début de la liste.
 * Param #1. L’adresse du pointeur vers le premier élément de la liste
 * Param #2. L’adresse du pointeur vers l’élément à rajouter à la liste
 * Valeur de retour : aucune
 * */

void	ft_lstadd_front(t_list **alst, t_list *new)
{
	if (alst == NULL || new == NULL)
		return ;
	(*new).next = *alst;
	*alst = new;
}
