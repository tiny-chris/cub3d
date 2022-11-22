/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_round_half.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaillag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 23:06:52 by cgaillag          #+#    #+#             */
/*   Updated: 2022/06/14 23:07:47 by cgaillag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* 	Rounding of the float value towards int type
*/
int	ft_round_half(float x)
{
	int	n;

	n = (int)x;
	if ((x - n) >= 0.5)
		return ((int)x + 1);
	return ((int)x);
}
