/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_3d_projection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmelard <lmelard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 15:42:35 by cgaillag          #+#    #+#             */
/*   Updated: 2022/12/12 17:52:06 by lmelard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	while (start.x < NUM_RAYS)
	{
		end.x = start.x;
		//changer la couleur avec les éléments dans base
		// ft_draw_line2(data->cub, start, end, COLOR_LOW);
		ft_draw_line2(data->cub, start, end, data->base.col_c_hex);
		start.x++;
	}
}

void	ft_render_color_floor(t_data *data)
{
	t_point	start;
	t_point	end;

	start.x = 0;
	start.y = WIN_HEIGHT / 2;
	end.x = 0;
	end.y = WIN_HEIGHT;
	while (start.x < NUM_RAYS)
	{
		end.x = start.x;
		//changer la couleur avec les éléments dans base
		// ft_draw_line2(data->cub, start, end, COLOR_BLUE);
		ft_draw_line2(data->cub, start, end, data->base.col_f_hex);
		start.x++;
	}
}

void	ft_init_proj(t_project_val *proj)
{
	proj->wall_strip_height = 0;
	proj->distance_proj_plane = 0;
	proj->projected_wall_height = 0;
	proj->perp_distance = 0;
	proj->color = 0;
}

void	ft_generate_3d_projection(t_data *data)
{
	int				i;
	t_project_val	proj;
	t_point			wall_top_pixel;
	t_point			wall_bottom_pixel;

	ft_render_color_ceiling(data);
	ft_render_color_floor(data);
	ft_init_proj(&proj);
	i = 0;
	while (i < NUM_RAYS)
	{
		// pour supprimer l'effet fishball
		proj.perp_distance = data->rays[i].distance * cos(data->rays[i].ray_angle - data->player.rotation_angle);
		proj.distance_proj_plane = (WIN_WIDTH / 2) / tan(FOV_ANGLE / 2);
		proj.projected_wall_height = (TILE_SIZE / proj.perp_distance) * proj.distance_proj_plane;
		proj.wall_strip_height = (int) proj.projected_wall_height;
		wall_top_pixel.y = (WIN_HEIGHT / 2) - (proj.wall_strip_height / 2);
		if (wall_top_pixel.y < 0)
			wall_top_pixel.y = 0;
		wall_top_pixel.x = i;
		wall_bottom_pixel.y = (WIN_HEIGHT / 2) + (proj.wall_strip_height / 2);
		if (wall_bottom_pixel.y > WIN_HEIGHT)
			wall_bottom_pixel.y = WIN_HEIGHT;
		wall_bottom_pixel.x = i;
		if (data->rays[i].wall_hit_vertical == TRUE)
			proj.color = COLOR_LIGHT_PURPLE;
		else
			proj.color = COLOR_PURPLE;
		// changer la couleur avec les éléments dans base
		ft_draw_line2(data->cub, wall_top_pixel, wall_bottom_pixel, proj.color);
		i++;
	}
}
