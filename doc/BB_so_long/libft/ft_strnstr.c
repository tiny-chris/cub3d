/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaillag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 14:09:32 by cgaillag          #+#    #+#             */
/*   Updated: 2021/12/07 12:51:11 by cgaillag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned long	i;
	unsigned long	j;
	char			*str;

	str = (char *)haystack;
	if (needle[0] == '\0')
		return (str);
	if (len > 0)
	{	
		i = 0;
		while (haystack[i])
		{
			j = 0;
			while (((i + j) <= (len - 1))
				&& (haystack[i + j] == needle[j]))
			{
				j++;
				if (needle[j] == '\0')
					return (&str[i]);
			}
			i++;
		}
	}
	return (0);
}
