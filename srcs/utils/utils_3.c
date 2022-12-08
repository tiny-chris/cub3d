/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmelard <lmelard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 19:10:42 by cgaillag          #+#    #+#             */
/*   Updated: 2022/12/06 19:16:02 by lmelard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_key_release(int keycode, t_data *data)
{
	if (keycode == KEY_MOVING_UP)
		data->player.walk_direction = 0;
	else if (keycode == KEY_MOVING_DOWN)
		data->player.walk_direction = 0;
	else if (keycode == KEY_MOVING_RIGHT)
		data->player.side_direction = 0;
	else if (keycode == KEY_MOVING_LEFT)
		data->player.side_direction = 0;
	else if (keycode == KEY_CAMERA_LEFT)
		data->player.turn_direction = 0;
	else if (keycode == KEY_CAMERA_RIGHT)
		data->player.turn_direction = 0;
	return (0);
}

int	ft_key_hook(int keycode, t_data *data)
{
	if (keycode == KEY_ESC)
		ft_quit(data);
	else if (keycode == KEY_MOVING_UP)
	{
		data->player.walk_direction = 1;
		//printf("up = %d\n", data->player.walk_direction);
	}
	else if (keycode == KEY_MOVING_DOWN)
	{
		data->player.walk_direction = -1;
		//printf("down = %d\n", data->player.walk_direction);
	}
	else if (keycode == KEY_MOVING_RIGHT)
	{
		data->player.side_direction = -1;
		//printf("right = %d\n", data->player.side_direction);
	}
	else if (keycode == KEY_MOVING_LEFT)
	{
		data->player.side_direction = 1;
		//printf("left = %d\n",data->player.side_direction);
	}
	else if (keycode == KEY_CAMERA_LEFT)
	{
		data->player.turn_direction = -1;
		//printf("camera left = %d\n", data->player.turn_direction);
	}
	else if (keycode == KEY_CAMERA_RIGHT)
	{
		data->player.turn_direction = 1;
		//printf("camera right = %d\n", data->player.turn_direction);
	}
	return (0);
}

void	my_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->img.addr + (y * data->img.line_lenght + x * (data->img.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
