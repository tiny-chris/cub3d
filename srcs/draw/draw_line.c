/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmelard <lmelard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 18:23:34 by lmelard           #+#    #+#             */
/*   Updated: 2022/12/14 20:09:17 by lmelard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_draw_rect(t_data *data, t_point tile, int color, int size)
{
	t_point	tile2;
	t_point	tile_cpy;
	t_point	tile2_cpy;
	int		count;

	tile2.x = tile.x + size;
	tile2.y = tile.y;
	tile_cpy.x = tile.x;
	tile_cpy.y = tile.y;
	tile2_cpy.x = tile2.x;
	tile2_cpy.y = tile2.y;
	count = 0;
	while (count < size)
	{
		ft_draw_line(data, tile_cpy, tile2_cpy, color);
		tile_cpy.y += 1;
		tile2_cpy.y += 1;
		count++;
	}
}

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
