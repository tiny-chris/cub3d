/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmelard <lmelard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 13:51:56 by lmelard           #+#    #+#             */
/*   Updated: 2022/12/08 18:25:19 by lmelard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_draw_rect(t_data *data, t_point tile, int color, int size)
{
	t_point	tile2;
	t_point	tile_cpy;
	t_point	tile2_cpy;
	int		count;

	tile2.x = tile.x + size - 1;
	tile2.y = tile.y;
	tile_cpy.x = tile.x;
	tile_cpy.y = tile.y;
	tile2_cpy.x = tile2.x;
	tile2_cpy.y = tile2.y;
	count = 0;
	while (count < size)
	{
		ft_draw_horizontal(data, tile_cpy, tile2_cpy, color);
		tile_cpy.y += 1;
		tile2_cpy.y += 1;
		count++;
	}
}

void	ft_render_map(t_data *data)
{
	int		i;
	int		j;
	t_point	tile;
	int		**map;
	int		color;

	i = 0;
	j = 0;
	tile.x = 0;
	tile.y = 0;
	map = data->base.map;
	while (i < data->base.cols)
	{
		while (j < data->base.rows)
		{
			if (map[j][i] != -1)
			{
				if (map[j][i] == 1)
					color = COLOR_WHITE;
				else
					color = COLOR_BLACK;
				tile.x = i * TILE_SIZE * MAP_SCALE;
				tile.y = j * TILE_SIZE * MAP_SCALE;
				ft_draw_rect(data, tile, color, (TILE_SIZE * MAP_SCALE));
			}
			j++;
		}
		i++;
		j = 0;
	}
}

int	ft_render_next_frame(t_data *data)
{
	int	strip_id;

	strip_id = 0;
	if (data->player.turn_direction != 0 || data->player.walk_direction != 0 || data->player.side_direction != 0)
		ft_update_player(data);
	mlx_destroy_image(data->img.mlx_ptr, data->img.img);
	data->img.img = mlx_new_image(data->img.mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	if (!data->img.img)
		return (0); // On free ?
	data->img.addr = mlx_get_data_addr(data->img.img, &data->img.bits_per_pixel, \
				&data->img.line_lenght, &data->img.endian);
	if (!data->img.addr)
		return (0); // On free ? 
	// render line
	ft_render_map(data);
	ft_cast_all_rays(data);
	// render rays
	while (strip_id < WIN_WIDTH)
	{
		ft_draw_line(data, data->player.p, data->rays[strip_id].wall_hit, COLOR_RED);
		strip_id += 1;
	}
	ft_render_player(data);
	mlx_put_image_to_window(data->img.mlx_ptr, data->img.win_ptr, data->img.img, 0, 0);
	return (1);
}
