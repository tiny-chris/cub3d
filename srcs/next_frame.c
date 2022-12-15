/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_frame.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmelard <lmelard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 13:51:56 by lmelard           #+#    #+#             */
/*   Updated: 2022/12/15 17:18:39 by lmelard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_init_t_img_0(t_img *img)
{
	img->img = NULL;
	img->addr = NULL;
	img->path = NULL;
	img->color = NULL;
	img->bits_per_pixel = 0;
	img->line_length = 0;
	img->endian = 0;
	img->tile_x = 0;
	img->tile_y = 0;
}

/*	<SUMMARY> Initialize t_img cub and map2d using only one mlx_ptr
*/
void	ft_init_t_img(t_data *data, t_img *img, int width, int height)
{
	ft_init_t_img_0(img);
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

/*	<SUMMARY> Follow steps to render game window and minimap window
**	1. update player
**	2. cast all rays
**	3. generate & display 3D projection
**	4. display minimap (under condition)
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
	if (data->map2d_display == TRUE && data->minimap_scale != 0)
	{
		ft_render_minimap_2d(data);
		mlx_put_image_to_window(data->mlx_ptr, data->map2d_win_ptr, \
			data->m2d.img, 0, 0);
	}
	return (0);
}
