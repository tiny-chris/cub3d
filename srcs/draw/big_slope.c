/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_slope.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmelard <lmelard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 16:35:13 by lmelard           #+#    #+#             */
/*   Updated: 2022/12/02 19:14:56 by lmelard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_decreasing_y(t_data *data, t_point p1, t_point p2, int color, float m)
{
	float	error;
	float	x;
	float	b;

	error = 0.0;
	b = p1.y - (m * p1.x);
	while (p2.y <= p1.y)
	{
		my_pixel_put(data, p1.x, p1.y, color);
		x = ((p1.y - 1) - b) / m;
		if (p1.x < p2.x) // increasing x
		{
			error = p1.x + 1 - x;
			if (ft_abs(error) <= 0.5)
				p1.x += 1;
		}
		else // decreasing x
		{
			error = p1.x - 1 - x;
			if (ft_abs(error) <= 0.5)
				p1.x -= 1;
		}
		p1.y -= 1;
	}
}

static void	ft_increasing_y(t_data *data, t_point p1, t_point p2, int color, float m)
{
	float	error;
	float	x;
	float	b;

	error = 0;
	b = p1.y - (m * p1.x);
	while (p1.y <= p2.y)
	{
		my_pixel_put(data, p1.x, p1.y, color);
		x = ((p1.y + 1) - b) / m;
		if (p1.x < p2.x) // increasing x
		{
			error = p1.x + 1 - x;
			if (ft_abs(error) <= 0.5)
				p1.x += 1;	
		}
		else // decreasing x
		{
			error = p1.x - 1 - x;
			if (ft_abs(error) <= 0.5)
				p1.x -= 1;	
		}
		p1.y += 1; 
	}
}

void	ft_big_slope(t_data *data, t_point p1, t_point p2, int color, float m)
{
	if (p1.y > p2.y)
		ft_decreasing_y(data, p1, p2, color, m);
	else
		ft_increasing_y(data, p1, p2, color, m);
}
