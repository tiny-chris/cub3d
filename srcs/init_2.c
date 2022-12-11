/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaillag <cgaillag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 13:56:20 by lmelard           #+#    #+#             */
/*   Updated: 2022/12/11 20:26:06 by cgaillag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float	ft_get_rotation_angle(t_base *base)
{
	float	rotation_angle;

	rotation_angle = 0;
	if (base->p_direction == 'N')
		rotation_angle = (3 * M_PI) / 2;
	else if (base->p_direction == 'S')
		rotation_angle = M_PI / 2;
	else if (base->p_direction == 'E')
		rotation_angle = 0;
	else if (base->p_direction == 'W')
		rotation_angle = M_PI;
	return (rotation_angle);
}

void	ft_init_player(t_data *data)
{
	t_base	*base;

	base = &data->base;
	data->player.p.x = base->p_x * TILE_SIZE;
	data->player.p.y = base->p_y * TILE_SIZE;
	data->player.width = 4;
	data->player.height = 4; // ne garder que width ?
	data->player.turn_direction = 0;
	data->player.walk_direction = 0;
	data->player.side_direction = 0;
	data->player.rotation_angle = ft_get_rotation_angle(base);
	printf("\ndata->playerotationangle %f\n", data->player.rotation_angle); //à enlever
	data->player.turn_speed = 3 * (M_PI / 180);
	data->player.walk_speed = 2.0;
}

void	ft_init_rays(t_data *data)
{
	int	strip_id;

	strip_id = 0;
	while (strip_id < WIN_WIDTH)
	{
		data->rays[strip_id].wall_hit.x = 0;
		data->rays[strip_id].wall_hit.y = 0;
		data->rays[strip_id].distance = 0;
		data->rays[strip_id].wall_hit_vertical = FALSE;
		data->rays[strip_id].is_ray_facing_up = FALSE;
		data->rays[strip_id].is_ray_facing_down = FALSE;
		data->rays[strip_id].is_ray_facing_left = FALSE;
		data->rays[strip_id].is_ray_facing_right = FALSE;
		strip_id++;
	}
}

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
