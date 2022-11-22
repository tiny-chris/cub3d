/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_player_moves.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaillag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 15:20:45 by cgaillag          #+#    #+#             */
/*   Updated: 2022/06/21 19:54:04 by cgaillag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/*  ***** PLAYER MOVES *****
**  *************************
**  Depending on the pressed button, the player can move up, down, on the left  
**	or on the right.
**  *************************
**  Case 1: new position is a WALL
**		- yes --> nothing to be done (leave the function)
**		- no --> continue to Case 2
**	Case 2: new position is an EXIT
**		- yes --> check the count of collectibles 'ncoll'
**			- if 'ncoll' == 0 --> EXIT_SUCCESS (+ clean)
**			- if 'ncoll' !=0 --> nothing to be done (leave the function)
**		- No --> continue to Case 3
**	Case 3: new position is A COLLECTIBLE or a SPACE 
**		--> if it is a COLLECTIBLE: decrease ncoll--
**		--> "swap" : current position as 'SPACE' and new position as 'PLAYER'
*/
void	ft_move_up(t_data *d_ref)
{
	int	x;
	int	y;

	x = d_ref->game->p_x;
	y = d_ref->game->p_y;
	if (d_ref->game->map[y - 1][x] != '1')
	{
		if (d_ref->game->map[y - 1][x] == 'E')
		{
			if (d_ref->game->ncoll == 0)
			{
				ft_display_nmoves(d_ref);
				ft_clean_game(d_ref, 0, SUCMSG_WD);
			}
		}
		else
		{
			if (d_ref->game->map[y - 1][x] == 'C')
				d_ref->game->ncoll -= 1;
			d_ref->game->map[y - 1][x] = 'P';
			d_ref->game->map[y][x] = '0';
			d_ref->game->p_y -= 1;
			ft_display_nmoves(d_ref);
		}
	}
}

void	ft_move_down(t_data *d_ref)
{
	int	x;
	int	y;

	x = d_ref->game->p_x;
	y = d_ref->game->p_y;
	if (d_ref->game->map[y + 1][x] != '1')
	{
		if (d_ref->game->map[y + 1][x] == 'E')
		{
			if (d_ref->game->ncoll == 0)
			{
				ft_display_nmoves(d_ref);
				ft_clean_game(d_ref, 0, SUCMSG_WD);
			}
		}
		else
		{
			if (d_ref->game->map[y + 1][x] == 'C')
				d_ref->game->ncoll -= 1;
			d_ref->game->map[y + 1][x] = 'P';
			d_ref->game->map[y][x] = '0';
			d_ref->game->p_y += 1;
			ft_display_nmoves(d_ref);
		}
	}
}

void	ft_move_left(t_data *d_ref)
{
	int	x;
	int	y;

	x = d_ref->game->p_x;
	y = d_ref->game->p_y;
	if (d_ref->game->map[y][x - 1] != '1')
	{
		if (d_ref->game->map[y][x - 1] == 'E')
		{
			if (d_ref->game->ncoll == 0)
			{
				ft_clean_game(d_ref, 0, SUCMSG_WD);
				ft_display_nmoves(d_ref);
			}
		}
		else
		{
			if (d_ref->game->map[y][x - 1] == 'C')
				d_ref->game->ncoll -= 1;
			d_ref->game->map[y][x - 1] = 'P';
			d_ref->game->map[y][x] = '0';
			d_ref->game->p_x -= 1;
			ft_display_nmoves(d_ref);
		}
	}
}

void	ft_move_right(t_data *d_ref)
{
	int	x;
	int	y;

	x = d_ref->game->p_x;
	y = d_ref->game->p_y;
	if (d_ref->game->map[y][x + 1] != '1')
	{
		if (d_ref->game->map[y][x + 1] == 'E')
		{
			if (d_ref->game->ncoll == 0)
			{
				ft_display_nmoves(d_ref);
				ft_clean_game(d_ref, 0, SUCMSG_WD);
			}
		}
		else
		{
			if (d_ref->game->map[y][x + 1] == 'C')
				d_ref->game->ncoll -= 1;
			d_ref->game->map[y][x + 1] = 'P';
			d_ref->game->map[y][x] = '0';
			d_ref->game->p_x += 1;
			ft_display_nmoves(d_ref);
		}
	}
}
