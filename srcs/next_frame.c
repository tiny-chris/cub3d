/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmelard <lmelard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 13:51:56 by lmelard           #+#    #+#             */
/*   Updated: 2022/12/14 20:12:24 by lmelard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*	<SUMMARY> Initialize t_img cub and map2d using only one mlx_ptr
*/
void	ft_init_t_img(t_data *data, t_img *img, int width, int height)
{
	img->img = mlx_new_image(data->mlx_ptr, width, height);
	if (img->img == NULL)
		ft_exit_cub(ft_msg_1(0, "mlx_new_image()", NULL, ER_MLX_IMG), data);
	img->addr = mlx_get_data_addr(img->img, &(img->bits_per_pixel), \
		&(img->line_length), &(img->endian));
	if (img->addr == NULL)
	{
		ft_exit_cub(ft_msg_1(0, "mlx_get_data_addr()", NULL, ER_MLX_ADDR), \
			data);
	}
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
	mlx_destroy_image(data->mlx_ptr, data->cub.img);
	ft_init_t_img(data, &(data->cub), WIN_WIDTH, WIN_WIDTH);
	ft_generate_3d_projection(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->cub.img, 0, 0);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 20, 20, COLOR_WHITE, \
		"press 'm' for minimap");
	if (data->map2d_display == TRUE)
	{
		ft_render_minimap_2d(data);
		mlx_clear_window(data->mlx_ptr, data->map2d_win_ptr);
		mlx_put_image_to_window(data->mlx_ptr, data->map2d_win_ptr, \
			data->m2d.img, 0, 0);
	}
	return (1);
}
