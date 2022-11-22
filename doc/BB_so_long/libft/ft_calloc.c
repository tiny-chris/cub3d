/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaillag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 10:42:36 by cgaillag          #+#    #+#             */
/*   Updated: 2021/12/20 20:53:15 by cgaillag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

void	ft_bzero(void *s, size_t n);

void	*ft_calloc(size_t nb, size_t size)
{
	void	*tab;

	tab = malloc(size * nb);
	if (tab == NULL)
		return (NULL);
	ft_bzero(tab, size * nb);
	return (tab);
}
