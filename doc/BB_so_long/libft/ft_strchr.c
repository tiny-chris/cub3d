/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaillag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 15:34:16 by cgaillag          #+#    #+#             */
/*   Updated: 2021/12/20 21:23:53 by cgaillag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

char	*ft_strchr(const char *s, int c)
{
	int				i;
	char			*string;
	unsigned char	uc;

	i = 0;
	uc = (unsigned char) c;
	string = (char *) s;
	while (string[i])
	{
		if (string[i] == uc)
			return (&string[i]);
		i++;
	}
	if (uc == '\0' && string[i] == '\0')
		return (&string[i]);
	return (0);
}
