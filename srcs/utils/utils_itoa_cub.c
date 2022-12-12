/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_itoa_cub.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaillag <cgaillag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 22:01:08 by cgaillag          #+#    #+#             */
/*   Updated: 2022/12/13 00:16:42 by cgaillag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static size_t	ft_count(long long int n)
{
	int						c;
	unsigned long long int	nb;

	c = 1;
	nb = 0;
	if (n < 0)
	{
		nb = -n;
		c++;
		while (nb > 9)
		{
			c++;
			nb = nb / 10;
		}
	}
	else if (n >= 0)
	{
		while (n > 9)
		{
			c++;
			n = n / 10;
		}
	}
	return (c);
}

static unsigned long long int	ft_define_nb(long long int n)
{
	unsigned long long int	nb;

	nb = 0;
	if (n >= 0)
		nb = n;
	else if (n < 0)
		nb = -n;
	return (nb);
}

char	*ft_itoa2(long long int n)
{
	char					*str;
	int						len;
	unsigned long long int	nb;

	nb = 0;
	str = ft_magic_malloc(MALLOC + TAB_STR1, NULL, (ft_count(n) + 1));
	len = ft_count(n);
	nb = ft_define_nb(n);
	str[len] = '\0';
	len--;
	if (nb == 0)
		str[len] = nb + 48;
	while (nb)
	{
		str[len] = (nb % 10) + 48;
		nb = nb / 10;
		len--;
	}
	if (n < 0)
		str[len] = '-';
	return (str);
}
