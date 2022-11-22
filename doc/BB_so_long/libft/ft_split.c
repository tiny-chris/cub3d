/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaillag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 14:36:42 by cgaillag          #+#    #+#             */
/*   Updated: 2022/06/14 23:45:09 by cgaillag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

/*	******** FT_SPLIT ********
 *	**************************
 *	Function that splits a string into a table of strings by using a defined 
 *	separator (char).
 *
 *	Actions:
 *	- calculate the number of future strings (words)
 *	- malloc the char ** (table of string) with number of words + 1
 *	- malloc each new words string
 *	- fill each words with correct content
 *	- plan a free function if allocation is not possible
 *	**************************
 *
 * Static - Counts the number of words in the string when using separator 'c' 
*/
static int	ft_word_count(char const *str, char c)
{
	int	i;
	int	word;

	i = 0;
	word = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c)
		{
			while (str[i] != c && str[i])
				i++;
			word++;
		}
		else
			i++;
	}
	return (word);
}

/*	Two actions in this static function:
**	1. malloc each string that represents a word (nb of char + 1 for '\0')
**	2. and then return this new string (create string 1 by 1)
*/
static char	*ft_malloc_word(char const *str, char c)
{
	int		i;
	char	*new_word;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	new_word = (char *) malloc(sizeof(char) * (i + 1));
	if (!new_word)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != c)
	{
		new_word[i] = str[i];
		i++;
	}
	new_word[i] = '\0';
	return (new_word);
}

/* Main function 
*/
char	**ft_split(char const *str, char c)
{
	char	**tab;
	int		i;

	if (!str)
		return (NULL);
	tab = (char **) malloc(sizeof(char *) * (ft_word_count(str, c) + 1));
	if (tab == NULL)
		return (free(tab), NULL);
	i = 0;
	while (*str)
	{
		if (*str != c)
		{
			tab[i++] = ft_malloc_word(str, c);
			if (!tab[i - 1])
				ft_free_tabstr(tab, i);
			while (*str != c && *str)
				str++;
		}
		else
			str++;
	}
	tab[i] = 0;
	return (tab);
}
