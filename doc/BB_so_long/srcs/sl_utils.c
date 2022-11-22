/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaillag <cgaillag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 15:11:40 by cgaillag          #+#    #+#             */
/*   Updated: 2022/06/28 01:37:16 by cgaillag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../libft/libft.h"

/*	***** PLAYER POSITION ******
**
**	Two functions to find the coordinates (x, y) of character 'c' in a table of
**	strings
**	Useful when the char ** is a map (with lines of same length)
*/

int	ft_find_x_tabstr(char **map, int len_lines, int lines, char c)
{
	int				i;
	int				j;
	unsigned char	uc;

	if (!map)
		return (-1);
	i = 0;
	uc = (unsigned char) c;
	while (i < lines)
	{
		j = 0;
		while (j < len_lines)
		{
			if (map[i][j] == uc)
				return (j);
			j++;
		}
		i++;
	}
	return (-1);
}

int	ft_find_y_tabstr(char **map, int len_lines, int lines, char c)
{
	int				i;
	int				j;
	unsigned char	uc;

	if (!map)
		return (-1);
	i = 0;
	uc = (unsigned char) c;
	while (i < lines)
	{
		j = 0;
		while (j < len_lines)
		{
			if (map[i][j] == uc)
				return (i);
			j++;
		}
		i++;
	}
	return (-1);
}

/*	***** DISPLAY PLAYER's MOVEMENTS ******
**	At every move, the current number of movements must be displayed in the
**	shell.
*/
void	ft_display_nmoves(t_data *d_ref)
{
	d_ref->game->moves += 1;
	ft_putnbr_fd(d_ref->game->moves, 1);
	ft_putendl_fd("", 1);
}
