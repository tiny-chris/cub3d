/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmelard <lmelard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 13:51:56 by lmelard           #+#    #+#             */
/*   Updated: 2022/11/30 14:57:14 by lmelard          ###   ########.fr       */
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

void	ft_render_player(t_data *data)
{
	t_point	p;

	p.x = data->player.x;
	p.y = data->player.y;
	ft_draw_rect(data, p, COLOR_RED, data->player.width);
}

void	ft_render_map(t_data *data)
{
	int		i;
	int		j;
	t_point	tile;
	int 	**map;
	int		color;

	i = 0;
	j = 0;
	tile.x = 0;
	tile.y = 0;
	map = data->base.game->map;
	while (i < data->base.game->cols)
	{
		while (j < data->base.game->rows)
		{
			if (map[j][i] != -1)
			{
				if (map[j][i] == 1)
					color = COLOR_WHITE;
				else
					color = COLOR_BLACK;
				tile.x = i * TILE_SIZE;
				tile.y = j * TILE_SIZE;
				ft_draw_rect(data, tile, color, TILE_SIZE);
			}
			j++;
		}
		i++;
		j = 0;
	}
}

int	ft_render_next_frame(t_data *data)
{
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
	ft_render_player(data);
	mlx_put_image_to_window(data->img.mlx_ptr, data->img.win_ptr, data->img.img, 0, 0);
	return (1);
}
