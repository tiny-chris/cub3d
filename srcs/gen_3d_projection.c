/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_3d_projection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmelard <lmelard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 15:42:35 by cgaillag          #+#    #+#             */
/*   Updated: 2022/12/09 18:51:14 by lmelard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
	il faudra faire un render color pour le ceiling + un render color pour le floor

		! ! ! ! ! ! ! ! ! ! ! ! ! ! !
*/
void	ft_render_color(t_data *data)
{
	t_point	p1;
	t_point	p2;

	p1.x = 0;
	p1.y = 0;
	p2.x = 0;
	p2.y = WIN_HEIGHT;
	while (p1.x < data->nbr_rays)
	{
		p2.x = p1.x;
		ft_draw_line(data, p1, p2, COLOR_LOW);
		p1.x++;
	}
}

/*
	n'est-ce pas mieux de draw a rectangle ??
*/

void	ft_render_color_ceiling(t_data *data)
{
	t_point	start;
	t_point	end;

	start.x = 0;
	start.y = 0;
	end.x = 0;
	end.y = WIN_HEIGHT / 2;
	while (start.x < data->nbr_rays)
	{
		end.x = start.x;
		ft_draw_line(data, start, end, COLOR_LOW);//à changer
		start.x++;
	}
}

void	ft_render_color_floor(t_data *data)
{
	t_point	start;
	t_point	end;

	start.x = 0;
	start.y = 0;
	end.x = 0;
	end.y = WIN_HEIGHT / 2;
	while (start.x < data->nbr_rays)
	{
		end.x = start.x;
		ft_draw_line(data, start, end, COLOR_BLUE);//à changer
		start.x++;
	}
}

/*

	distance_proj_plane = how far is my player from the projection plane

	TO DO : render the call from wall_top_pixel to wall_bottom_pixel
*/
// void	ft_generate_3d_projection(t_data *data)
// {
// 	int		i;
// 	int		wall_strip_height;
// 	float	distance_proj_plane;
// 	float	projected_wall_height;
// 	t_point	wall_top_pixel;
// 	t_point	wall_bottom_pixel;

// 	i = 0;
// 	ft_render_color_ceiling(data);
// 	ft_render_color_floor(data);
// 	dprintf(2, "\ntest affichg pour ray[%d]\n", i);
// 	while (i < data->nbr_rays)
// 	{
// 		distance_proj_plane = (WIN_WIDTH / 2) / tan(FOV_ANGLE);
// 		// dprintf(2, "distance pour 1er ray = %f\n", data->rays[i].distance);
// 		projected_wall_height = (TILE_SIZE / data->rays[i].distance) * distance_proj_plane;
// 		wall_strip_height = (int) projected_wall_height;
// 		// dprintf(2, "val wall_strip_height = %d\n", wall_strip_height);
// 		wall_top_pixel.x = i;
// 		wall_bottom_pixel.x = i;
// 		wall_top_pixel.y = (WIN_HEIGHT / 2) - (wall_strip_height / 2);
// 		if (wall_top_pixel.y < 0)
// 			wall_top_pixel.y = 0;
// 		wall_bottom_pixel.y = (WIN_HEIGHT / 2) + (wall_strip_height / 2);
// 		if (wall_bottom_pixel.y > WIN_HEIGHT)
// 			wall_bottom_pixel.y = 0;
// 		// dprintf(2, "coord  wall_top_pixel: x = %f, y = %f\n", wall_top_pixel.x, wall_top_pixel.y);
// 		// dprintf(2, "coord  wall_bottom_pixel: x = %f, y = %f\n", wall_bottom_pixel.x, wall_bottom_pixel.y);
// 		while (wall_top_pixel.y < wall_bottom_pixel.y)
// 		{
// 			my_pixel_put(data, i, wall_top_pixel.y, 0xFF0000);
// 			wall_top_pixel.y += 1;
// 		}
// 		i++;
// 	}
// }

// void	ft_generate_3d_projection(t_data *data)
// {
// 	int		i;
// 	int		wall_strip_height;
// 	float	distance_proj_plane;
// 	float	projected_wall_height;
// 	t_point	wall_top_pixel;
// 	t_point	wall_bottom_pixel;

// 	i = 10;
// 	// while (i < data->nbr_rays)
// 	// {
// 		dprintf(2, "\ngenereate 3D proj: for i = %d\n", i);
// 		distance_proj_plane = (WIN_WIDTH / 2) / tan(FOV_ANGLE / 2);
// 		dprintf(2, "val distance_proj_plane = %f\n", distance_proj_plane);
// 		projected_wall_height = (TILE_SIZE / data->rays[i].distance) * distance_proj_plane;
// 		dprintf(2, "val projected_wall_height = %f\n", projected_wall_height);
// 		dprintf(2, "val data->rays[%d].distance = %f\n", i, data->rays[i].distance);
// 		wall_strip_height = (int) projected_wall_height;
// 		dprintf(2, "val wall_strip_height = %d\n", wall_strip_height);
// 		wall_top_pixel.y = (WIN_HEIGHT / 2) - (wall_strip_height / 2);
// 		if (wall_top_pixel.y < 0)
// 			wall_top_pixel.y = 0;
// 		wall_top_pixel.x = i;
// 		wall_bottom_pixel.y = (WIN_HEIGHT / 2) + (wall_strip_height / 2);
// 		if (wall_bottom_pixel.y > WIN_HEIGHT)
// 			wall_bottom_pixel.y = WIN_HEIGHT;
// 		wall_bottom_pixel.x = i;
// 		//ft_draw_vertical(data, wall_top_pixel, wall_bottom_pixel, COLOR_BLUE);
// 	// 	i++;
// 	// }
// }

int	ft_render_3d_visual(t_data *data)
{
	t_img	*cub;

	cub = &(data->cub);
	mlx_destroy_image(cub->mlx_ptr, cub->img);
	cub->img = mlx_new_image(cub->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	if (!cub->img)
	{
		ft_msg_1(1, NULL, NULL, "cannot get cub image");
		ft_quit(data);
	}
	cub->addr = mlx_get_data_addr(cub->img, &cub->bits_per_pixel, \
		&cub->line_lenght, &cub->endian);
	if (!cub->addr)
	{
		ft_msg_1(1, NULL, NULL, "cannot get cub address");
		ft_quit(data);
	}
	ft_render_color_ceiling(data);
	ft_render_color_floor(data);
	// ft_generate_3d_projection(data);
	//prevoir aussi avant 1er mouvement (donc avant render_map)
	mlx_put_image_to_window(cub->mlx_ptr, cub->win_ptr, cub->img, 0, 0);
	return (1);
}
