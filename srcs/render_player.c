/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmelard <lmelard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 11:58:15 by lmelard           #+#    #+#             */
/*   Updated: 2022/12/14 18:11:48 by lmelard          ###   ########.fr       */
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
	else
		mapgridindex_x = floor(x / TILE_SIZE);
	if (y == 0)
		mapgridindex_y = 0;
	else
		mapgridindex_y = floor(y / TILE_SIZE);
	if (mapgridindex_x < data->base.cols && mapgridindex_y < data->base.rows \
		&& data->base.map[mapgridindex_y][mapgridindex_x] != 0)
		return (TRUE);
	if (mapgridindex_x >= data->base.cols && mapgridindex_y >= data->base.rows)
		return (TRUE);
	return (FALSE);
}

void	ft_forward_diagonal(t_data *d, t_player *newplayer)
{
	float	movestep;

	movestep = d->player.walk_direction * d->player.walk_speed;
	if (d->player.side_direction == 1)
	{
		newplayer->p.x = d->player.p.x + cos(d->player.rotation_angle \
			- (M_PI / 4)) * movestep;
		newplayer->p.y = d->player.p.y + sin(d->player.rotation_angle \
			- (M_PI / 4)) * movestep;
	}
	else if (d->player.side_direction == -1)
	{
		newplayer->p.x = d->player.p.x + cos(d->player.rotation_angle \
			+ (M_PI / 4)) * movestep;
		newplayer->p.y = d->player.p.y + sin(d->player.rotation_angle \
			+ (M_PI / 4)) * movestep;
	}
}

void	ft_backward_diagonal(t_data *d, t_player *newplayer)
{
	float	movestep;

	movestep = d->player.walk_direction * d->player.walk_speed;
	if (d->player.side_direction == 1)
	{
		newplayer->p.x = d->player.p.x + cos(d->player.rotation_angle \
			+ (M_PI / 4)) * movestep;
		newplayer->p.y = d->player.p.y + sin(d->player.rotation_angle \
			+ (M_PI / 4)) * movestep;
	}
	else if (d->player.side_direction == -1)
	{
		newplayer->p.x = d->player.p.x + cos(d->player.rotation_angle \
			- (M_PI / 4)) * movestep;
		newplayer->p.y = d->player.p.y + sin(d->player.rotation_angle \
			- (M_PI / 4)) * movestep;
	}
}

void	ft_straight_move(t_data *d, t_player *newplayer)
{
	float	movestep;

	movestep = d->player.walk_direction * d->player.walk_speed;
	newplayer->p.x = d->player.p.x + cos(d->player.rotation_angle) * movestep;
	newplayer->p.y = d->player.p.y + sin(d->player.rotation_angle) * movestep;
}

void	ft_side_move(t_data *d, t_player *newplayer)
{
	float	movestep;

	movestep = d->player.side_direction * d->player.walk_speed;
	newplayer->p.x = d->player.p.x + sin(d->player.rotation_angle) * movestep;
	newplayer->p.y = d->player.p.y - cos(d->player.rotation_angle) * movestep;
}

void	ft_update_player(t_data *d)
{
	t_player	newplayer;

	newplayer.p.x = 0;
	newplayer.p.y = 0;
	d->player.rotation_angle += d->player.turn_direction * d->player.turn_speed;
	if (d->player.walk_direction != 0 && d->player.side_direction != 0)
	{
		if (d->player.walk_direction == 1)
			ft_forward_diagonal(d, &newplayer);
		else if (d->player.walk_direction == -1)
			ft_backward_diagonal(d, &newplayer);
	}
	else if (d->player.walk_direction != 0)
		ft_straight_move(d, &newplayer);
	else if (d->player.side_direction != 0)
		ft_side_move(d, &newplayer);
	if (ft_check_wall(d, newplayer.p.x, newplayer.p.y) == FALSE)
	{
		d->player.p.x = newplayer.p.x;
		d->player.p.y = newplayer.p.y;
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
