/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmelard <lmelard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 19:10:42 by cgaillag          #+#    #+#             */
/*   Updated: 2022/11/30 19:10:39 by lmelard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_hook(int keycode, t_data *data)
{
	if (keycode == KEY_ESC || keycode == KEY_UP || keycode == KEY_DOWN || keycode == KEY_LEFT || keycode == KEY_RIGHT)
		ft_quit(data);
	// else if (keycode == KEY_UP) // UP
	// else if (keycode == KEY_DOWN) // DOWN
	// else if (keycode == KEY_LEFT) // LEFT
	// else if (keycode == KEY_RIGHT) // RIGHT
	return (0);
}

void	my_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->img.addr + (y * data->img.line_lenght + x * (data->img.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
