/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmelard <lmelard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 11:58:15 by lmelard           #+#    #+#             */
/*   Updated: 2022/12/02 14:55:31 by lmelard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


/*	Fonction js */

// update() {
// 	// TO DO:
// 	// update player position based on turnDirecion and walkdirection
// 	this.rotationAngle += this.turnDirection * this.rotationSpeed;
	
// 	var moveStep = this.walkDirection * this.moveSpeed;
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


t_bool	ft_check_wall(t_data *data, t_player newplayer)
{
	int	mapgridindex_x;
	int	mapgridindex_y;
	
	if (newplayer.x < 0 || newplayer.x > WIN_WIDTH || newplayer.y < 0 || newplayer.y > WIN_HEIGHT)	
		return (TRUE);
	mapgridindex_x = floor(newplayer.x / TILE_SIZE);
	mapgridindex_y = floor(newplayer.y / TILE_SIZE);
	if (data->base.game->map[mapgridindex_y][mapgridindex_x] != 0)
		return (TRUE);
	return (FALSE);
}

void	ft_update_player(t_data *data)
{
	float		movestep;
	t_player	newplayer;

	movestep = 0;
	data->player.rotationAngle += data->player.turnDirection * data->player.turnSpeed;
	movestep = data->player.walkDirection * data->player.walkSpeed;
	newplayer.x = data->player.x + cos(data->player.rotationAngle) * movestep;
	newplayer.y = data->player.y - sin(data->player.rotationAngle) * movestep;
	if (ft_check_wall(data, newplayer) == FALSE)
	{
		data->player.x  = newplayer.x;
		data->player.y = newplayer.y;
	}
}

void	ft_render_player(t_data *data)
{
	t_point	p;
	t_point	p2;

	p.x = data->player.x;
	p.y = data->player.y;
	p2.x = p.x + (cos(data->player.rotationAngle) * 20);
	p2.y = p.y - (sin(data->player.rotationAngle) * 20);
	ft_draw_rect(data, p, COLOR_RED, data->player.width);
	ft_draw_line(data, p, p2, COLOR_BLUE);
}