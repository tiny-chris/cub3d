/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_clean.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaillag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 09:20:54 by cgaillag          #+#    #+#             */
/*   Updated: 2022/06/23 16:10:46 by cgaillag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../libft/libft.h"
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

/*	Function **FREE GAME** that:
**	1. checks if the map (char **) is not NULL
**		--> if not NULL: free each line + the map itself
**	2. free the struct 'game'
*/
void	ft_free_game(t_game *game)
{
	int	lines;

	if (game != 0)
	{
		if (game->map != 0)
		{
			lines = ft_lines_tabstr(game->map);
			ft_free_tabstr(game->map, lines);
		}
		free(game);
	}	
}

/*	Function **CLEAN GAME** that frees struct 'd_ref'
**	***********
**	Actions:
**	1. clean struct 'game' that contains 'char **map' if not NULL (via sub fct) 
**	2. destroy all graphical elements if not NULL:
**		- images (init images for 01CEP): pointer on mlx + void *img
**		- window: pointer on mlx + pointer on window
**		- display: sub fct for 2 steps = 1.end_loop + 2.destroy & free display
**	3. call fct 'exit' correct exit + error messages, error nb (if applicable)
**	***********
**	Parameters:
**	- t_data = struct 'd_ref' to clean
**	- res = result for the exit (0 = success, INT_MAX = no exit, else = failure)
**	- res_msg = to print
*/
void	ft_clean_game(t_data *d_ref, int res, char *res_msg)
{
	if (d_ref != 0)
	{
		if (d_ref->game != 0)
			ft_free_game(d_ref->game);
		if (d_ref->empty != 0)
			mlx_destroy_image(d_ref->mlx, d_ref->empty);
		if (d_ref->wall != 0)
			mlx_destroy_image(d_ref->mlx, d_ref->wall);
		if (d_ref->coll != 0)
			mlx_destroy_image(d_ref->mlx, d_ref->coll);
		if (d_ref->exit != 0)
			mlx_destroy_image(d_ref->mlx, d_ref->exit);
		if (d_ref->player != 0)
			mlx_destroy_image(d_ref->mlx, d_ref->player);
		if (d_ref->win != 0)
			mlx_destroy_window(d_ref->mlx, d_ref->win);
		if (d_ref->mlx != 0)
		{
			mlx_loop_end(d_ref->mlx);
			mlx_destroy_display(d_ref->mlx);
			free(d_ref->mlx);
		}
		free(d_ref);
	}
	ft_exit_sl(res, res_msg);
}

/*	Function **EXIT so long** that:
**	1. displays the message 'msg'(if not NULL):
**		- on stderr (if failure) 
**		- on stdout (if success)
**	2. and exits as success or failure depending on provided 'res'
**		(0 = success, 1 = no exit, else = failure) 
*/
void	ft_exit_sl(int res, char *res_msg)
{
	if (res == 0)
	{
		if (res_msg != NULL)
			ft_putendl_fd(res_msg, 1);
		exit(EXIT_SUCCESS);
	}
	else if (res == INT_MAX)
		return ;
	ft_error_msg_sl(res_msg);
	exit(EXIT_FAILURE);
}

/*	Function **ERROR MSG so long** that displays a message on stderr depending
**	on provided 'res_msg' for EXIT_FAILURE
*/
void	ft_error_msg_sl(char *res_msg)
{
	if (res_msg == NULL)
		return ;
	write(2, "Error\n", 6);
	ft_putendl_fd(res_msg, 2);
}

/*	Function **DESTROY HOOK so long** that close properly the window when
**	clicking on the "cross"
*/
int	ft_destroy_hook_sl(t_data *d_ref)
{
	ft_clean_game(d_ref, 0, SUCMSG_ES);
	return (0);
}
