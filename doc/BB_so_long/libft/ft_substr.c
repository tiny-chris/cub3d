/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaillag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 12:15:49 by cgaillag          #+#    #+#             */
/*   Updated: 2022/06/14 23:27:33 by cgaillag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

/*	Allocates (with malloc(3)) and returns a substring from the initial 'str' 
**	string. This new string begins at 'start' index and its maximal length is 
**	'len' (can be smaller if the length of the original string is less than
**	'start + length').
*/
char	*ft_substr(const char *str, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	str_len;
	char	*new_str;

	if (!str)
		return (NULL);
	str_len = ft_strlen(str);
	if ((size_t)start >= str_len)
		return (ft_strdup(""));
	if (len + start > str_len)
		new_str = malloc(sizeof(char) * (str_len - start));
	else
		new_str = malloc(sizeof(char) * (len + 1));
	if (!new_str)
		return (NULL);
	i = start;
	j = 0;
	while (i < str_len && j < len)
		new_str[j++] = str[i++];
	new_str[j] = '\0';
	return (new_str);
}
