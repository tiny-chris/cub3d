/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaillag <cgaillag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 19:10:42 by cgaillag          #+#    #+#             */
/*   Updated: 2022/11/25 00:04:23 by cgaillag         ###   ########.fr       */
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

/*	Calculates the length of the string pointed to by str, excluding the
**	termination null byte ('\0') and provided character (e.g. '\n')
*/
int	ft_strlen_spechar(const char *str, char spe_c)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] == spe_c)
			return (i);
		i++;
	}
	return (i);
}

// int	key_hook(int keycode, t_img *img)
// {
// 	if (keycode == 65307)
// 		ft_quit(img);
// 	return (0);
// }

// void	my_pixel_put(t_img *img, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = img->addr + (y * img->line_lenght + x * (img->bits_per_pixel / 8));
// 	*(unsigned int *)dst = color;
// }
