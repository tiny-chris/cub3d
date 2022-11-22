/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_diff_abs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaillag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 23:03:21 by cgaillag          #+#    #+#             */
/*   Updated: 2022/06/14 23:03:56 by cgaillag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*	Get the absolute value of the difference between 2 integers
*/
long	ft_diff_abs(int x, int y)
{
	long	result;

	result = (long)x - (long)y;
	if (result < 0)
		result = -1 * result;
	return (result);
}
