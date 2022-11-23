/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmelard <lmelard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 18:23:34 by lmelard           #+#    #+#             */
/*   Updated: 2022/11/23 18:40:19 by lmelard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_draw_vertical(t_point *p1, t_point *p2, t_img *img)
{
	if (p1->y > p2->y)
	{
		while (p2->y <= p1->y)
		{
			my_pixel_put(img, p1->x, p1->y, COLOR_LOW);
			p1->y -= 1;
		}
	}
	else
	{
		while (p1->y <= p2->y)
		{
			my_pixel_put(img, p1->x, p1->y, COLOR_LOW);
			p1->y += 1;
		}
	}
}
