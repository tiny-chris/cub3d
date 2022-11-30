/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_slope.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmelard <lmelard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 16:35:43 by lmelard           #+#    #+#             */
/*   Updated: 2022/11/30 17:27:07 by lmelard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_decreasing_x(t_data *data, t_point p1, t_point p2, int color, float m)
{
	float	error;

	error = 0.0;
	while (p2.x <= p1.x)
	{
		my_pixel_put(data, p1.x, p1.y, color);
		error = error + m;
		if (error >= 0.5)
		{
			if (p1.y < p2.y)
			{
				p1.y += 1;
				error = error - 1.0;
			}
			else
			{
				p1.y -= 1;
				error = error + 1.0;
			}
		}
		p1.x -= 1;
	}
}

static void	ft_increasing_x(t_data *data, t_point p1, t_point p2, int color, float m)
{
	float	error;

	error = 0.0;
	while (p1.x <= p2.x)
	{
		my_pixel_put(data, p1.x, p1.y, color);
		error = error + m;
		if (error >= 0.5)
		{
			if (p1.y < p2.y)
			{
				p1.y += 1;
				error = error - 1.0;
			}
			else
			{
				p1.y -= 1;
				error = error + 1.0;
			}
		}
		p1.x += 1;
	}
}

void	ft_small_slope(t_data *data, t_point p1, t_point p2, int color, float m)
{
	if (p1.x > p2.x)
		ft_decreasing_x(data, p1, p2, color, m);
	else if (p1.x < p2.x)
		ft_increasing_x(data, p1, p2, color, m);
}

