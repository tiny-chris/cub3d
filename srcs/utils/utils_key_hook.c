/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_key_hook.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaillag <cgaillag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 19:41:03 by lmelard           #+#    #+#             */
/*   Updated: 2022/12/15 15:00:46 by cgaillag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*	<SUMMARY> Update the variable that activates/disables the minimap 2D display
**	once the 'm' key is pressed
**	- if "minimap2d_display" is 'TRUE' (is visible)
**		--> destroy the map2d window (keep the map2d image)
**			and change the miniap2d_display to 'FALSE'
**	- if "minimap2d_display" is 'FALSE' (window not open)
**		--> open a new map2d window,
**			and change the miniap2d_display to 'TRUE'  
*/
void	ft_handle_minimap_2d(t_data *data)
{
	if (data->map2d_display == TRUE)
	{
		mlx_destroy_window(data->mlx_ptr, data->map2d_win_ptr);
		data->map2d_win_ptr = NULL;
		data->map2d_display = FALSE;
	}
	else
	{
		data->map2d_win_ptr = mlx_new_window(data->mlx_ptr, data->map2d_width,
				data->map2d_height, "MINIMAP 2D");
		data->map2d_display = TRUE;
	}
}

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
