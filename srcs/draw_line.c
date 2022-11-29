/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmelard <lmelard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 18:23:34 by lmelard           #+#    #+#             */
/*   Updated: 2022/11/29 15:14:07 by lmelard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_draw_vertical(t_data *data, t_point p1, t_point p2, int color)
{
	if (p1.y > p2.y)
	{
		while (p2.y <= p1.y)
		{
			my_pixel_put(data, p1.x, p1.y, color);
			p1.y -= 1;
		}
	}
	else
	{
		while (p1.y <= p2.y)
		{
			my_pixel_put(data, p1.x, p1.y, color);
			p1.y += 1;
		}
	}
}

void	ft_draw_horizontal(t_data *data, t_point p1, t_point p2, int color)
{
	if (p1.x > p2.x)
	{
		while (p2.x <= p1.x)
		{
			my_pixel_put(data, p1.x, p1.y, color);
			p1.x -= 1;
		}
	}
	else
	{
		while (p1.x <= p2.x)
		{
			my_pixel_put(data, p1.x, p1.y, color);
			p1.x += 1;
		}
	}
}
