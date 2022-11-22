/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaillag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 14:28:35 by cgaillag          #+#    #+#             */
/*   Updated: 2022/06/15 00:37:50 by cgaillag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

/*	Combines the 2 strings in the arguments list, and puts the result into the
**	returned string with dynamically allocated memory. 
*/
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	s1_len;
	int		i;

	if (!s1 && !s2)
		return (ft_strdup(""));
	if (!s1)
		return (ft_strdup((char *)s2));
	if (!s2)
		return (ft_strdup((char *)s1));
	s1_len = ft_strlen(s1);
	str = malloc(sizeof(char) * (s1_len + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	i = -1;
	while (s1[++i])
		str[i] = s1[i];
	i = -1;
	while (s2[++i])
		str[s1_len + (size_t) i] = s2[i];
	str[s1_len + (size_t) i] = '\0';
	free((char *)s1);
	return (str);
}
