/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_atoi_cub.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaillag <cgaillag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 10:15:06 by cgaillag          #+#    #+#             */
/*   Updated: 2022/11/28 10:15:15 by cgaillag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*	***************************************************************************
 *	Function that can converts a string into a numeric value of 'int' type.
 *	(atoi = ASCII to integer)
 *
 *	Value of INT_MAX is +2147483647
 *	Value of INT_MIN is - 2147483648
 * */

static int	ft_isspace(char c)
{
	if (c == '\t' || c == '\n' || c == '\v' || c == '\f'
		|| c == '\r' || c == ' ')
		return (1);
	return (0);
}

static int	ft_update_sign(char c, int *neg_val)
{
	if (c == '+' || c == '-')
	{
		if (c == '-')
			*neg_val = -1;
		else
			*neg_val = 1;
		return (1);
	}
	return (0);
}

int	ft_atoi_cub(char *str)
{
	int	neg_val;
	int	nb;
	int	i;

	neg_val = 1;
	nb = 0;
	i = 0;
	while (str[i] && ft_isspace(str[i]))
		i++;
	if (ft_update_sign(str[i], &neg_val))
	{
		i++;
		if (str[i] == '\0')
			return (-1);
	}
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 0)
			return (-1);
		nb = nb * 10 + (str[i] - 48);
		i++;
	}
	return (neg_val * nb);
}
