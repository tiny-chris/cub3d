/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmelard <lmelard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 16:48:15 by cgaillag          #+#    #+#             */
/*   Updated: 2022/11/28 16:22:03 by lmelard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
**	Fonction qui ne prend q'un seul argument peut etre qu'il faudra que
**	la structure envoyee en paramettre pointe vers d'autres structures pour
**	tout free avant d'exit ou bien faire un garbage collector aussiiiiii
*/

void	ft_quit(t_base *data)
{
	mlx_destroy_image(data->img.mlx_ptr, data->img.img);
	mlx_destroy_window(data->img.mlx_ptr, data->img.win_ptr);
	mlx_loop_end(data->img.mlx_ptr);
	mlx_destroy_display(data->img.mlx_ptr);
	free(data->img.mlx_ptr);
	exit(0);
}

/*  ***** Cleaning - display the error message *****
**  *************************
**  <SUMMARY>	Print an error message on stderr (if any)
**				and return the provided error value
*/
int	ft_err_msg(int res, char *msg1, char *msg2)
{
	if (!msg1 && !msg2)
		return (res);
	write(2, "Error\n", 6);
	if (msg1)
	{
		ft_putstr_fd(msg1, STDERR_FILENO);
		write(2, ": ", STDERR_FILENO);
	}
	ft_putendl_fd(msg2, STDERR_FILENO);
	return (res);
}
