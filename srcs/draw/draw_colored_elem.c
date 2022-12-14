/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_colored_elem.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaillag <cgaillag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 15:35:11 by cgaillag          #+#    #+#             */
/*   Updated: 2022/12/14 15:39:53 by cgaillag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_draw_color_ceiling(t_data *data)
{
	t_point	start;
	t_point	end;

	start.x = 0;
	start.y = 0;
	end.x = 0;
	end.y = WIN_HEIGHT / 2;
	while (start.x < NUM_RAYS)
	{
		end.x = start.x;
		ft_draw_line2(data->cub, start, end, data->base.col_c_hex);
		start.x++;
	}
}

void	ft_draw_color_floor(t_data *data)
{
	t_point	start;
	t_point	end;

	start.x = 0;
	start.y = WIN_HEIGHT / 2;
	end.x = 0;
	end.y = WIN_HEIGHT;
	while (start.x < NUM_RAYS)
	{
		end.x = start.x;
		ft_draw_line2(data->cub, start, end, data->base.col_f_hex);
		start.x++;
	}
}
