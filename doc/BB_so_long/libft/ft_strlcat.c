/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaillag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 14:15:15 by cgaillag          #+#    #+#             */
/*   Updated: 2021/12/20 21:19:31 by cgaillag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

size_t	ft_strlen(const char *s);

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t			src_len;
	unsigned long	i;
	unsigned long	j;

	src_len = ft_strlen(src);
	i = 0;
	j = 0;
	if (size == 0)
		return (src_len);
	while (dst[i] != '\0' && i < size)
		i++;
	while (src[j] != '\0' && (i + j) < (size - 1))
	{
		dst[i + j] = src [j];
		j++;
	}
	if (i < size)
		dst[i + j] = '\0';
	return (i + src_len);
}
