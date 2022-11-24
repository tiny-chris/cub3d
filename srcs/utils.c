/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmelard <lmelard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 19:10:42 by cgaillag          #+#    #+#             */
/*   Updated: 2022/11/24 16:39:35 by lmelard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*	<SUMMARY> 	Open a file on "read only" mode
**	
**	<PARAM>		char *file (to open)
**	<RETURN>	a file descriptor or -1, if could not open the file
*/
int	ft_open_read(const char *file)
{
	int	fd;
	int	val_exit;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		val_exit = errno;
		ft_putendl_fd(strerror(errno), 2);
		ft_putendl_fd("fd: ", 2);
		perror(file);
		exit(val_exit); // ou exit(errno);
	}
	return (fd);
}

int	key_hook(int keycode, t_data *data)
{
	if (keycode == 65307)
		ft_quit(data);
	return (0);
}

void	my_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->img.addr + (y * data->img.line_lenght + x * (data->img.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
