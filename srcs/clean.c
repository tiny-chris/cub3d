/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmelard <lmelard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 16:48:15 by cgaillag          #+#    #+#             */
/*   Updated: 2022/11/23 17:29:10 by lmelard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
**	Fonction qui ne prend q'un seul argument peut etre qu'il faudra que 
**	la structure envoyee en paramettre pointe vers d'autres structures pour 
**	tout free avant d'exit ou bien faire un garbage collector aussiiiiii
*/ 

void	ft_quit(t_img *img)
{
	mlx_destroy_image(img->mlx_ptr, img->img);
	mlx_destroy_window(img->mlx_ptr, img->win_ptr);
	mlx_loop_end(img->mlx_ptr);
	mlx_destroy_display(img->mlx_ptr);
	free(img->mlx_ptr);
	exit(0);
}

int	key_hook(int keycode, t_img *img)
{
	if (keycode == 65307)
		ft_quit(img);
	return (0);
}

/*  ***** Cleaning - display the error message *****
**  *************************
**  Prints an error message on stderr (if any) and returns the provided error
** value
*/
int	ft_err_msg(int res, char *msg1, char *msg2)
{
	if (!msg1 && !msg2)
		return (res);
	write(2, "Error: ", 7);
	if (msg1)
	{
		ft_putstr_fd(msg1, STDERR_FILENO);
		write(2, ": ", STDERR_FILENO);
	}
	ft_putendl_fd(msg2, STDERR_FILENO);
	return (res);
}
