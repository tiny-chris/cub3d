/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmelard <lmelard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 20:11:02 by lmelard           #+#    #+#             */
/*   Updated: 2022/12/15 16:25:55 by lmelard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_draw_tile(t_data *data, int i, int j)
{
	int		color;
	t_point	tile;

	if (data->base.map[j][i] != -1)
	{
		if (data->base.map[j][i] == 1)
			color = COLOR_WHITE;
		else
			color = COLOR_BLACK;
		tile.x = i * MINI_TILE * data->minimap_scale;
		tile.y = j * MINI_TILE * data->minimap_scale;
		ft_draw_rect(data, tile, color, (MINI_TILE * data->minimap_scale));
	}
}

void	ft_render_map(t_data *data)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < data->base.cols)
	{
		while (j < data->base.rows)
		{
			ft_draw_tile(data, i, j);
			j++;
		}
		i++;
		j = 0;
	}
}

void	ft_render_minimap_2d(t_data *data)
{
	if (data->m2d.img)
		mlx_destroy_image(data->mlx_ptr, data->m2d.img);
	ft_init_t_img(data, &data->m2d, data->map2d_width, data->map2d_height);
	ft_render_map(data);
	ft_render_rays(data);
	ft_render_player(data);
}
