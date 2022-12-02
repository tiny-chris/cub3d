/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_slope.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmelard <lmelard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 16:35:43 by lmelard           #+#    #+#             */
/*   Updated: 2022/12/02 19:42:37 by lmelard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_decreasing_x(t_data *data, t_point p1, t_point p2, int color, float m)
{
	float	error;
	float	y;
	float	b;

	error = 0;
	b = p1.y - (m * p1.x);
	while (p2.x <= p1.x)
	{
		my_pixel_put(data, p1.x, p1.y, color);
		y = (m * p1.x + 1) + b;
		if (p1.y < p2.y) // increasing y
		{
			error = p1.y + 1 - y;
			if (ft_abs(error) <= 0.5)
				p1.y += 1;
		}
		else // decreasing y
		{
			error = p1.y - 1 - y;
			if (ft_abs(error) <= 0.5)
				p1.y -= 1;
		}
		p1.x -= 1;
	}
}

static void	ft_increasing_x(t_data *data, t_point p1, t_point p2, int color, float m)
{
	float	error;
	float	y;
	float	b;

	error = 0;
	b = p1.y - (m * p1.x);
	while (p1.x <= p2.x)
	{
		my_pixel_put(data, p1.x, p1.y, color);
		y = (m * p1.x + 1) + b;
		if (p1.y < p2.y) // increasing y
		{
			//error = y - p1.y + 1;
			error = p1.y + 1 - y;
			if (ft_abs(error) <= 0.5)
				p1.y += 1;
		}
		else // decreasing y
		{
			error = p1.y - 1 - y;
			if (ft_abs(error) <= 0.5)
				p1.y -= 1;
		}
		p1.x += 1;
	}
}

void	ft_small_slope(t_data *data, t_point p1, t_point p2, int color, float m)
{
	if (p1.x > p2.x)
		ft_decreasing_x(data, p1, p2, color, m);
	else
		ft_increasing_x(data, p1, p2, color, m);
}

