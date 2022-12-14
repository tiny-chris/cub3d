/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_3d_projection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmelard <lmelard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 15:42:35 by cgaillag          #+#    #+#             */
/*   Updated: 2022/12/14 18:38:29 by lmelard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_img	*ft_select_texture(t_ray *ray, t_data *data)
{
	if (ray->wall_hit_vertical == TRUE && ray->is_ray_facing_left)
		return (&data->base.ea);
	else if (ray->wall_hit_vertical == TRUE && ray->is_ray_facing_right)
		return (&data->base.we);
	else if (ray->wall_hit_vertical == FALSE && ray->is_ray_facing_up)
		return (&data->base.so);
	else if (ray->wall_hit_vertical == FALSE && ray->is_ray_facing_down)
		return (&data->base.no);
	return (NULL);
}

void	ft_init_proj(t_proj *proj)
{
	proj->y = 0;
	proj->wall_strip_height = 0;
	proj->distance_proj_plane = 0;
	proj->projected_wall_height = 0;
	proj->perp_distance = 0;
	proj->wall_top.x = 0;
	proj->wall_top.y = 0;
	proj->wall_bottom.x = 0;
	proj->wall_bottom.y = 0;
	proj->diff[0] = 0;
	proj->diff[1] = 0;
	proj->color = 0;
}

static void	ft_init_3d_cast(t_data *data, t_ray *ray, t_proj *p, t_img *tex)
{
	// pour supprimer l'effet fishball
	p->perp_distance = ray->distance
		* cos(ray->ray_angle - data->player.rotation_angle);
	// p->distance_proj_plane = (WIN_WIDTH / 2) / tan(FOV_ANGLE / 2);// deja dans data
	p->projected_wall_height = (TILE_SIZE / p->perp_distance)
		* data->dist_proj_plane;//p->distance_proj_plane;
	p->wall_strip_height = (int) p->projected_wall_height;
	p->wall_top.y = (WIN_HEIGHT / 2) - (p->wall_strip_height / 2);
	if (p->wall_top.y < 0)
		p->wall_top.y = 0;
	p->wall_bottom.y = (WIN_HEIGHT / 2) + (p->wall_strip_height / 2);
	if (p->wall_bottom.y > WIN_HEIGHT)
		p->wall_bottom.y = WIN_HEIGHT;	
	if (ray->wall_hit_vertical == TRUE)
		p->diff[0] = (int) ray->wall_hit.y % tex->tile_x;
	else
		p->diff[0] = (int) ray->wall_hit.x % tex->tile_x;
	p->y = p->wall_top.y;
}

void	ft_generate_3d_projection(t_data *data)
{
	int		i;
	t_img	*tex;
	t_proj	p;

	tex = NULL;
	ft_init_proj(&p);
	ft_draw_color_ceiling(data);
	ft_draw_color_floor(data);
	i = 0;
	while (i < NUM_RAYS)
	{
		tex = ft_select_texture(&data->rays[i], data);
		ft_init_3d_cast(data, &data->rays[i], &p, tex);
		p.wall_top.x = i;
		p.wall_bottom.x = i;
		while (p.y < p.wall_bottom.y)
		{
			p.dist_top = p.y + (p.wall_strip_height / 2) - (WIN_HEIGHT / 2);
			p.diff[1] = p.dist_top * ((float) tex->tile_x / p.wall_strip_height);
			tex->color = tex->addr + (p.diff[1] * tex->line_length + p.diff[0] * (tex->bits_per_pixel / 8));
			my_pixel_put2(data->cub, i, p.y, *(int *) tex->color);
			p.y++;
		}
		i++;
	}
}

// void	ft_generate_3d_projection(t_data *data)
// {
// 	int		i;
// 	t_img	*tex;
// 	t_proj	p;

// 	tex = NULL;
// 	// ft_init_t_img_0(tex);
// 	ft_init_proj(&p);
// 	ft_render_color_ceiling(data);
// 	ft_render_color_floor(data);
// 	i = 0;
// 	while (i < NUM_RAYS)
// 	{
// 		// pour recuperer les textures
// 		tex = ft_select_texture(&data->rays[i], data);
// 		ft_init_3d_cast(data, &data->rays[i], &p, tex);
// 		p.wall_top.x = i; // ??
// 		p.wall_bottom.x = i; // ??
// 		while (p.y < p.wall_bottom.y)
// 		{
// 			p.dist_top = p.y + (p.wall_strip_height / 2) - (WIN_HEIGHT / 2);
// 			p.diff[1] = p.dist_top * ((float) tex->tile_x / p.wall_strip_height);
// 			tex->color = tex->addr + (p.diff[1] * tex->line_length + p.diff[0] * (tex->bits_per_pixel / 8));
// 			my_pixel_put2(data->cub, i, p.y, *(int *) tex->color);
// 			p.y++;
// 		}
// 		i++;
// 	}
// }

void	ft_generate_3d_projection(t_data *data)
{
	int				i;
	t_proj			proj;
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
		//proj.distance_proj_plane = (WIN_WIDTH / 2) / tan(FOV_ANGLE / 2);
		proj.projected_wall_height = (TILE_SIZE / proj.perp_distance) * data->dist_proj_plane;
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

