/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaillag <cgaillag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 11:58:15 by lmelard           #+#    #+#             */
/*   Updated: 2022/12/08 12:27:22 by cgaillag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


/*	Fonction js */

// update() {
// 	// TO DO:
// 	// update player position based on turnDirecion and walk_direction
// 	this.rotationAngle += this.turn_direction * this.rotationSpeed;

// 	var moveStep = this.walk_direction * this.moveSpeed;
// 	//this.x += Math.cos(this.rotationAngle) * moveStep;
// 	//this.y += Math.sin(this.rotationAngle) * moveStep;
// 	var	newPlayerX = this.x + Math.cos(this.rotationAngle) * moveStep;
// 	var newPlayerY = this.y + Math.sin(this.rotationAngle) * moveStep;

// 	// only set new player position if it is not colliding with the map walls
// 	if (!grid.hasWallAt(newPlayerX, newPlayerY)) {
// 		this.x = newPlayerX;
// 		this.y = newPlayerY;
// 	}
// }

// hasWallAt(x, y) {
// 		if (x < 0 || x > WINDOW_WIDTH || y < 0 || y > WINDOW_HEIGHT) {
// 			return true;
// 		}
// 		var mapGridIndexX = Math.floor(x / TILE_size);
// 		var mapGridIndexY = Math.floor(y / TILE_size);
// 		return this.grid[mapGridIndexY][mapGridIndexX] != 0; 

t_bool	ft_check_wall(t_data *data, float x, float y)
{
	int	mapgridindex_x;
	int	mapgridindex_y;

	if (x < 0 || x > WIN_WIDTH || y < 0 \
		|| y > WIN_HEIGHT)
		return (TRUE);
	if (x == 0)
		mapgridindex_x = 0;
	else
		mapgridindex_x = floor(x / TILE_SIZE);
	if (y == 0)
		mapgridindex_y = 0;
	else
		mapgridindex_y = floor(y / TILE_SIZE);
	if (mapgridindex_x < data->base.cols && mapgridindex_y < data->base.rows \
		&& data->base.map[mapgridindex_y][mapgridindex_x] != 0)
		return (TRUE);
	if (mapgridindex_x >= data->base.cols && mapgridindex_y >= data->base.rows)
		return (TRUE);
	return (FALSE);
}

void	ft_update_player(t_data *d)
{
	float		movestep;
	t_player	newplayer;

	movestep = 0;
	d->player.rotation_angle -= d->player.turn_direction * d->player.turn_speed;
	movestep = d->player.walk_direction * d->player.walk_speed;
	newplayer.p.x = d->player.p.x + cos(d->player.rotation_angle) * movestep;
	newplayer.p.y = d->player.p.y - sin(d->player.rotation_angle) * movestep;
	if (ft_check_wall(d, newplayer.p.x, newplayer.p.y) == FALSE)
	{
		d->player.p.x = newplayer.p.x;
		d->player.p.y = newplayer.p.y;
	}
}

void	ft_render_player(t_data *data)
{
	t_point	p;
	t_point	p2;

	p.x = data->player.p.x;
	p.y = data->player.p.y;
	p2.x = p.x + (cos(data->player.rotation_angle) * DIR_LEN);
	p2.y = p.y - (sin(data->player.rotation_angle) * DIR_LEN);
	ft_draw_rect(data, p, COLOR_RED, data->player.width);
	ft_draw_line(data, p, p2, COLOR_BLUE);
}

	// deg_rotation_angle = (data->player.rotation_angle * 180 / M_PI);
	// while (deg_rotation_angle > (2 * M_PI))
	// 	(deg_rotation_angle -= (2 * M_PI));
	// dprintf(2, "deg_rotation_angle = %f\n", deg_rotation_angle);
	// if (deg_rotation_angle < 0)
	// {
	// 	ft_putendl_fd("OUCHHHHHHHHHH rot angle negatif\n", 2);
	// 	ft_quit(data);
	// }
	// if (deg_rotation_angle >= 0 && deg_rotation_angle < 90)
	// {
	// 	p2.x = p.x + (cos(deg_rotation_angle) * LINE_DIR);
	// 	p2.y = p.y - (sin(deg_rotation_angle) * LINE_DIR);
	// }
	// else if (deg_rotation_angle >= 90 && deg_rotation_angle < 180)
	// {
	// 	p2.x = p.x - (sin(deg_rotation_angle - 90) * LINE_DIR);
	// 	p2.y = p.y - (cos(deg_rotation_angle - 90) * LINE_DIR);
	// }
	// else if (deg_rotation_angle >= 180 && deg_rotation_angle < 270)
	// {
	// 	p2.x = p.x - (cos(deg_rotation_angle - 180) * LINE_DIR);
	// 	p2.y = p.y + (sin(deg_rotation_angle - 180) * LINE_DIR);
	// }
	// else
	// {
	// 	p2.x = p.x + (sin(deg_rotation_angle - 270) * LINE_DIR);
	// 	p2.y = p.y + (cos(deg_rotation_angle - 270) * LINE_DIR);
	// }
