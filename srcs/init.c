/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaillag <cgaillag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 13:56:20 by lmelard           #+#    #+#             */
/*   Updated: 2022/12/10 03:13:51 by cgaillag         ###   ########.fr       */
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

/* INIT LES 2 IMG L'UNE APRES L'AUTRE
*/
/*	<SUMMARY> Initialize t_img cub and map2d using only one mlx_ptr
*/
int	ft_init_t_img(t_img *img, int width, int height)
{
	img->img = mlx_new_image(data->mlx_ptr, width, height);
	if (img->img == NULL)
		return (ft_msg_1(0, "mlx_new_image()", NULL, ER_MLX_IMG));
	img->addr = mlx_get_data_addr(img->img, &(img->bits_per_pixel), \
		&(img->line_length), &(img->endian));
	if (img->addr == NULL)
		return (ft_msg_1(0, "mlx_get_data_addr()", NULL, ER_MLX_ADDR));
	return (1);
}

// /* INIT LES 2 IMG EN PARALLELE
// */
// /*	<SUMMARY> Initialize t_img cub and map2d using only one mlx_ptr
// */
// int	ft_init_t_img(t_data *data)
// {
// 	t_img	*cub;
// 	t_img	*m2d;

// 	cub = &(data->cub);
// 	m2d = &(data->img);
// 	cub->img = mlx_new_image(data->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
// 	m2d->img = mlx_new_image(data->mlx_ptr, WIN_WIDTH, WIN_WIDTH);
// 	if (cub->img == NULL || m2d->img == NULL)
// 		return (ft_msg_1(0, "mlx_new_image()", NULL, ER_MLX_IMG));
// 	cub->addr = mlx_get_data_addr(cub->img, &(cub->bits_per_pixel),
// 		&(cub->line_length), &(cub->endian));
// 	m2d->addr = mlx_get_data_addr(m2d->img, &(m2d->bits_per_pixel),
// 		&(m2d->line_length), &(m2d->endian));
// 	if (cub->addr == NULL || m2d->addr == NULL)
// 		return (ft_msg_1(0, "mlx_get_data_addr()", NULL, ER_MLX_IMG));
// 	return (1);
// }

static void	ft_init_data_0(t_data *data)
{
	data->mlx_ptr = NULL;
	data->win_ptr = NULL;
	data->map2d_win_ptr = NULL;
	data->map2d_display = FALSE;
	data->map2d_width = WIN_WIDTH;//a revoir, calculer
	data->map2d_height = WIN_HEIGHT;//a revoir, calculer
	data->cub.img = NULL;
	data->img.img = NULL;
}

/*	<SUMMARY> Initialize data elements except 'base' content
	- set up mlx to start game
	- open textures
	- init t_img for main game & minimap
	- init player
	- init rays
*/
void	ft_init_data(t_data *data)
{
	ft_init_data_0(data);
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
		ft_exit_cub(ft_msg_1(1, "mlx_init()", NULL, ER_MLX_INIT), data);
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIN_WIDTH, WIN_HEIGHT,
			"CUB3D");
	if (data->win_ptr == NULL)
		ft_exit_cub(ft_msg_1(1, "mlx_new_window()", NULL, ER_MLX_WIN),
			data);
	//see where to open texture... see so_long
	// /* cas pour init les 2 images l'une après l'autre : */
	if (!ft_init_t_img(data->cub, WIN_WIDTH, WIN_HEIGHT))
		ft_exit_cub(1, data);
	if (!ft_init_t_img(data->img, WIN_WIDTH, WIN_HEIGHT))
		ft_exit_cub(1, data);
	// /* cas pour init les 2 images en parallèle : */
	// if (!ft_init_t_img(data))
	// 	ft_exit_cub(1, data);
	ft_init_player(data);
	ft_init_rays(data);
}
