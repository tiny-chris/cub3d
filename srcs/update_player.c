/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaillag <cgaillag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 19:47:28 by lmelard           #+#    #+#             */
/*   Updated: 2022/12/15 14:38:21 by cgaillag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_forward_diagonal(t_data *d, t_player *newplayer)
{
	float	movestep;

	movestep = d->player.walk_direction * d->player.walk_speed;
	if (d->player.side_direction == 1)
	{
		newplayer->p.x = d->player.p.x + cos(d->player.rotation_angle \
			- (PI / 4)) * movestep;
		newplayer->p.y = d->player.p.y + sin(d->player.rotation_angle \
			- (PI / 4)) * movestep;
	}
	else if (d->player.side_direction == -1)
	{
		newplayer->p.x = d->player.p.x + cos(d->player.rotation_angle \
			+ (PI / 4)) * movestep;
		newplayer->p.y = d->player.p.y + sin(d->player.rotation_angle \
			+ (PI / 4)) * movestep;
	}
}

void	ft_backward_diagonal(t_data *d, t_player *newplayer)
{
	float	movestep;

	movestep = d->player.walk_direction * d->player.walk_speed;
	if (d->player.side_direction == 1)
	{
		newplayer->p.x = d->player.p.x + cos(d->player.rotation_angle \
			+ (PI / 4)) * movestep;
		newplayer->p.y = d->player.p.y + sin(d->player.rotation_angle \
			+ (PI / 4)) * movestep;
	}
	else if (d->player.side_direction == -1)
	{
		newplayer->p.x = d->player.p.x + cos(d->player.rotation_angle \
			- (PI / 4)) * movestep;
		newplayer->p.y = d->player.p.y + sin(d->player.rotation_angle \
			- (PI / 4)) * movestep;
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
