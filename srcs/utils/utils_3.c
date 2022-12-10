/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaillag <cgaillag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 19:10:42 by cgaillag          #+#    #+#             */
/*   Updated: 2022/12/10 03:08:53 by cgaillag         ###   ########.fr       */
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
		data->player.walk_direction = 1;
	else if (keycode == KEY_MOVING_DOWN)
		data->player.walk_direction = -1;
	else if (keycode == KEY_MOVING_RIGHT)
		data->player.side_direction = -1;
	else if (keycode == KEY_MOVING_LEFT)
		data->player.side_direction = 1;
	else if (keycode == KEY_CAMERA_LEFT)
		data->player.turn_direction = -1;
	else if (keycode == KEY_CAMERA_RIGHT)
		data->player.turn_direction = 1;
	else if (keycode == KEY_MINIMAP)
		ft_handle_minimap_2d(data);
	return (0);
}

void	my_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->img.addr + (y * data->img.line_length \
		+ x * (data->img.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	my_pixel_put2(t_img img, int x, int y, int color)
{
	char	*dst;

	if (x > WIN_WIDTH || x < 0)
		return ;
	if (y > WIN_HEIGHT || y < 0)
		return ;
	dst = img.addr + (y * img.line_length + x * (img.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

/*	<SUMMARY>

	A décortiquer :
	If minimap is not open, window is opened and hooks are setup.
	Else, the window is destroyed (but not the minimap image).


*/
void	ft_handle_minimap_2d(t_data *data)
{
	if (data->display_map2d == FALSE)
	{
		data->map2d_win_ptr = mlx_new_window(data->mlx_ptr, data->map2d_width,
				data->map2d_length, "MINIMAP 2D");
		mlx_hook(data->map2d_win_ptr, 17, 0L, (void *) ft_quit, &data);
		mlx_hook(data->map2d_win_ptr, 2, 1L << 0, (void *) ft_key_hook, &data);
		mlx_hook(data->map2d_win_ptr, 3, 1L << 1, (void *) ft_key_release,
			&data);
		data->map2d_display = TRUE;
	}
	else
	{
		mlx_destroy_window(data->mlx_ptr, data->map2d_win_ptr);
		data->map2d_win_ptr = NULL;
		data->map2d_display = FALSE;
	}
}
