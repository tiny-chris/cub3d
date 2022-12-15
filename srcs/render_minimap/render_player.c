/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaillag <cgaillag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 11:58:15 by lmelard           #+#    #+#             */
/*   Updated: 2022/12/15 15:00:13 by cgaillag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_bool	ft_check_wall(t_data *data, float x, float y)
{
	int	mapgridindex_x;
	int	mapgridindex_y;

	mapgridindex_x = 0;
	mapgridindex_y = 0;
	if (x < 0 || x > data->base.cols * TILE_SIZE || y < 0 \
		|| y > data->base.rows * TILE_SIZE)
		return (TRUE);
	mapgridindex_x = floor(x / TILE_SIZE);
	mapgridindex_y = floor(y / TILE_SIZE);
	if (mapgridindex_x < data->base.cols && mapgridindex_y < data->base.rows \
		&& data->base.map[mapgridindex_y][mapgridindex_x] != 0)
		return (TRUE);
	if (mapgridindex_x >= data->base.cols && mapgridindex_y >= data->base.rows)
		return (TRUE);
	return (FALSE);
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

void	ft_render_player(t_data *data)
{
	t_point	p;
	t_point	p2;
	t_point	p_cpy;
	t_point	p2_cpy;

	p.x = (data->player.p.x);
	p.y = (data->player.p.y);
	p2.x = (p.x + (cos(data->player.rotation_angle) * DIR_LEN));
	p2.y = (p.y + (sin(data->player.rotation_angle) * DIR_LEN));
	p_cpy.x = p.x * MAP_SCALE;
	p_cpy.y = p.y * MAP_SCALE;
	p2_cpy.x = p2.x * MAP_SCALE;
	p2_cpy.y = p2.y * MAP_SCALE;
	ft_draw_rect(data, p_cpy, COLOR_RED, (data->player.width * MAP_SCALE));
	ft_draw_line(data, p_cpy, p2_cpy, COLOR_BLUE);
}
