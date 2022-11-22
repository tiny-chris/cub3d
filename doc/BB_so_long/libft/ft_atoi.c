/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaillag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 13:56:47 by cgaillag          #+#    #+#             */
/*   Updated: 2021/12/20 20:50:55 by cgaillag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

/* **DESCRIPTION**
 * La fonction atoi permet de transformer une chaîne de caractères, représentant
 * une valeur entière, en une valeur numérique de type int. Le terme d'atoi est
 * un acronyme signifiant : ASCII to integer. 
 * Valeur de retour : valeur 0 si la chaîne de caractères ne contient pas une 
 * représentation de valeur numérique (il n'est pas possible de distinguer la 
 * chaîne "0" d'une chaîne ne contenant pas un nombre entier - autrement, 
 * veuillez préférer l'utilisation de la fonction strtol qui permet bien de 
 * distinguer les deux cas.
 *
 * Ma fonction est operationnelle pour les valeurs contenues entre min & max INT
 * Pour les valeurs superieures, la fonction de reference atoi() renvoie elle
 * -meme vers strtol (vers entier de type long)
 * */

int	ft_atoi(const char *str)
{
	int	i;
	int	neg_val;
	int	number;

	i = 0;
	neg_val = 1;
	number = 0;
	while (str[i] && (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
			|| str[i] == '\f' || str[i] == '\r' || str[i] == ' '))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
		{
			neg_val = -1;
			number = -number;
		}
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		number = number * 10 + str[i] - 48;
		i++;
	}
	return (neg_val * number);
}
