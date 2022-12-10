/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaillag <cgaillag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 18:23:34 by lmelard           #+#    #+#             */
/*   Updated: 2022/12/10 00:42:06 by cgaillag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_draw_line(t_data *data, t_point p1, t_point p2, int color)
{
	t_point	delta;
	t_point	point;
	int		pixel;

	delta.x = fabs(p2.x - p1.x);
	delta.y = fabs(p2.y - p1.y);
	pixel = sqrt(delta.x * delta.x + delta.y * delta.y);
	delta.x /= (float) pixel;
	delta.y /= (float) pixel;
	point = p1;
	while (pixel)
	{
		if (point.x >= 0 && point.y >= 0
			&& point.x < WIN_WIDTH && point.y < WIN_HEIGHT)
			my_pixel_put(data, point.x, point.y, color);
		if (p1.x < p2.x)
			point.x += delta.x;
		else
			point.x -= delta.x;
		if (p1.y < p2.y)
			point.y += delta.y;
		else
			point.y -= delta.y;
		pixel --;
	}
}

void	ft_draw_line2(t_img img, t_point p1, t_point p2, int color)
{
	t_point	delta;
	t_point	point;
	int		pixel;

	delta.x = fabs(p2.x - p1.x);
	delta.y = fabs(p2.y - p1.y);
	pixel = sqrt(delta.x * delta.x + delta.y * delta.y);
	delta.x /= (float) pixel;
	delta.y /= (float) pixel;
	point = p1;
	while (pixel)
	{
		if (point.x >= 0 && point.y >= 0
			&& point.x < WIN_WIDTH && point.y < WIN_HEIGHT)
			my_pixel_put2(img, point.x, point.y, color);
		if (p1.x < p2.x)
			point.x += delta.x;
		else
			point.x -= delta.x;
		if (p1.y < p2.y)
			point.y += delta.y;
		else
			point.y -= delta.y;
		pixel --;
	}
}
