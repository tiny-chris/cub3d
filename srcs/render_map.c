/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaillag <cgaillag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 13:51:56 by lmelard           #+#    #+#             */
/*   Updated: 2022/12/12 20:46:01 by cgaillag         ###   ########.fr       */
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

void	ft_render_rays(t_data *data)
{
	int		strip_id;
	t_point	player;
	t_point	wall_hit;

	strip_id = 0;
	while (strip_id < WIN_WIDTH)
	{
		player.x = data->player.p.x * MAP_SCALE;
		player.y = data->player.p.y * MAP_SCALE;
		wall_hit.x = data->rays[strip_id].wall_hit.x * MAP_SCALE;
		wall_hit.y = data->rays[strip_id].wall_hit.y * MAP_SCALE;
		ft_draw_line(data, player, wall_hit, COLOR_RED);
		strip_id += 1;
	}
}

void	ft_render_minimap_2d(t_data *data)
{
	if (data->m2d.img)
		mlx_destroy_image(data->mlx_ptr, data->m2d.img);
	ft_init_t_img(data, &data->m2d, data->map2d_width, data->map2d_height);//size a revoir
	ft_render_map(data);
	ft_render_rays(data);
	ft_render_player(data);
}

/*	<SUMMARY> Steps to render game window and minimap window

	- update player position when he moves
		(update coordinates depending on walk direction and rotation angle)
	- destroy images + reinitialise image (ou peut etre pas necessaire ??????????)
	- cast all rays
	- generate 3D projection
	- put image cub to window
	- display minimap to 2nd window if condition is TRUE
		- create a condition (TRUE/FALSE)
		- render minimap
		- clear window : map2d_win_ptr
		- put image map2d to map2d_win_ptr
	- display player
*/
int	ft_render_next_frame(t_data *data)
{
	if (data->player.turn_direction != 0 || data->player.walk_direction != 0 \
		|| data->player.side_direction != 0)
		ft_update_player(data);
	ft_cast_all_rays(data);
	// render cub game
	mlx_destroy_image(data->mlx_ptr, data->cub.img);
	ft_init_t_img(data, &(data->cub), WIN_WIDTH, WIN_WIDTH);
	ft_generate_3d_projection(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->cub.img, 0, 0);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 20, 20, COLOR_WHITE, \
		"press 'm' for minimap");
	// render minimap
	if (data->map2d_display == TRUE)
	{
		ft_render_minimap_2d(data);
		mlx_clear_window(data->mlx_ptr, data->map2d_win_ptr);
		mlx_put_image_to_window(data->mlx_ptr, data->map2d_win_ptr, \
			data->m2d.img, 0, 0); // possible de modifier la taille
	}
	return (1);
}

/*
int	ft_render_next_frame(t_data *data)
{
	if (data->player.turn_direction != 0 || data->player.walk_direction != 0 || data->player.side_direction != 0)
		ft_update_player(data);
	mlx_destroy_image(data->img.mlx_ptr, data->img.img);
	data->img.img = mlx_new_image(data->img.mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	if (!data->img.img)
		return (0); // On free ?
	data->img.addr = mlx_get_data_addr(data->img.img, &data->img.bits_per_pixel, \
				&data->img.line_length, &data->img.endian);
	if (!data->img.addr)
		return (0); // On free ?
	ft_cast_all_rays(data);
	ft_render_map(data);
	ft_render_rays(data);
	ft_render_player(data);
	mlx_put_image_to_window(data->img.mlx_ptr, data->img.win_ptr, data->img.img, 0, 0);
	return (1);
}
*/
