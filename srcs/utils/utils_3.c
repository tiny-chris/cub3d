/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmelard <lmelard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 19:10:42 by cgaillag          #+#    #+#             */
/*   Updated: 2022/12/02 15:55:51 by lmelard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_key_release(int keycode, t_data *data)
{
	if (keycode == KEY_UP) // UP
	{
		data->player.walkDirection = 0;
		//printf("walkdir %d\n", data->player.walkDirection);
	}
	else if (keycode == KEY_DOWN) // DOWN
	{
		data->player.walkDirection = 0;
		//printf("walkdir %d\n", data->player.walkDirection);
	}
	else if (keycode == KEY_LEFT) // LEFT
	{
		data->player.turnDirection = 0;
		//printf("turndir %d\n", data->player.turnDirection);
	}
	else if (keycode == KEY_RIGHT) // RIGHT
	{
		data->player.turnDirection = 0;
		//printf("turndir %d\n", data->player.turnDirection);
	}
	return (0);
}

int	key_hook(int keycode, t_data *data)
{
	if (keycode == KEY_ESC)
		ft_quit(data);
	else if (keycode == KEY_UP) // UP
	{
		data->player.walkDirection = 1;
		//printf("walkdir %d\n", data->player.walkDirection);
	}
	else if (keycode == KEY_DOWN) // DOWN
	{
		data->player.walkDirection = -1;
		//printf("walkdir %d\n", data->player.walkDirection);
	}
	else if (keycode == KEY_LEFT) // LEFT
	{
		data->player.turnDirection = -1;
		//printf("turndir %d\n", data->player.turnDirection);
	}
	else if (keycode == KEY_RIGHT) // RIGHT
	{
		data->player.turnDirection = 1;
		//printf("turndir %d\n", data->player.turnDirection);
	}
	return (0);
}

void	my_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->img.addr + (y * data->img.line_lenght + x * (data->img.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
