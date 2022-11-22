/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaillag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 14:44:53 by cgaillag          #+#    #+#             */
/*   Updated: 2021/12/20 21:15:10 by cgaillag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	start;
	size_t	count_trim;
	size_t	s1_len;

	if (!s1 || !set)
		return (NULL);
	s1_len = ft_strlen(s1);
	start = 0;
	while (s1[start] && ft_is_in_set(set, s1[start]))
		start++;
	if (start == s1_len)
		return (ft_strdup(""));
	while ((s1_len > start) && ft_is_in_set(set, s1[s1_len - 1]))
		s1_len--;
	count_trim = s1_len - start;
	str = (char *) malloc(sizeof(*s1) * (count_trim + 1));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1 + start, (count_trim + 1));
	return (str);
}
