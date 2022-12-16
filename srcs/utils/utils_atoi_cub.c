/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_atoi_cub.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaillag <cgaillag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 10:15:06 by cgaillag          #+#    #+#             */
/*   Updated: 2022/12/16 19:13:02 by cgaillag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*    Convert a string into a numeric value of 'int' type.
**    (atoi = ASCII to integer)
**
**    Value of INT_MAX is +2147483647
**    Value of INT_MIN is - 2147483648
*/
int	ft_atoi_cub(char *str)
{
	int	neg_val;
	int	nb;
	int	i;

	neg_val = 1;
	nb = 0;
	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 0)
			return (-1);
		nb = nb * 10 + (str[i] - 48);
		i++;
	}
	return (neg_val * nb);
}
