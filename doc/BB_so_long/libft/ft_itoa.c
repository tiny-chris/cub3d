/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaillag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 21:29:31 by cgaillag          #+#    #+#             */
/*   Updated: 2021/12/20 20:54:45 by cgaillag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

/* 	*Description* : int to alpha
 * 	Alloue (avec malloc(3)) et retourne une chaine de caractères 
 * 	représentant l’integer reçu en argument.
 * 	Les nombres négatifs doivent être gérés.
 * 	Param #1. l’integer à convertir.
 * 	Valeur de retour : 
 * 		La chaine de caractères représentant l’integer.
 * 		NULL si l’allocation échoue.
*/

/* *ACTION* : compter le nb de chiffres + le signe a include si n negatif 
 * pour avoir la longueur de la chaine
*/
static int	ft_nb_size(int n)
{
	int	size;

	size = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		size++;
	while (n != 0)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

/* *ACTION* : multiplier n par -1 si n est negatif pour traiter en unsigned */
static size_t	ft_neg_sign(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

/* *ACTION* : definir le debut de la chaine pour la boucle (le 'start')
 * + prendre la valeur absolue de n car si n < 0 --> signe '-' rm str[0]
*/
static size_t	ft_sign_val(int n)
{
	if (n < 0)
		return (1);
	return (0);
}

/* *ACTION* : reecrire en char * le int (n) */
char	*ft_itoa(int n)
{
	size_t	len;
	char	*str;
	int		number;
	size_t	start;

	number = n;
	if (n == INT_MIN)
		return (ft_strdup("-2147483648"));
	len = ft_nb_size(n);
	str = (char *) malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	number = ft_neg_sign(n);
	start = ft_sign_val(n);
	if (n < 0)
		str[0] = '-';
	while (len > start)
	{
		str[len - 1] = number % 10 + '0';
		number = number / 10;
		len--;
	}
	str[ft_nb_size(n)] = '\0';
	return (str);
}
