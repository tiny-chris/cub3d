/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaillag <cgaillag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 16:48:15 by cgaillag          #+#    #+#             */
/*   Updated: 2022/11/22 16:46:35 by cgaillag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_check_nb_lines(t_data *data)
{
	(void) data;
	return (0);
}

int	ft_check_lines_order(t_data *data)
{
	(void) data;
	return (0);
}

void	ft_get_file_content_detailed(t_data *data)
{
	(void) data;
	return ;
}

int	ft_check_map_err(char **map_base)
{
	(void) map_base;
	return (0);
}

int	ft_check_elem_err(char **elem_base)
{
	(void) elem_base;
	return (0);
}

/*  ***** Parsing - ........ *****
**  *************************
**  <SUMMARY>	
**	
**	nb de lignes
**	position des elements et de la map
**
*/
int	ft_check_file_err(t_data *data)
{
	ft_check_nb_lines(data);
	ft_check_lines_order(data);
	ft_get_file_content_detailed(data);
	if (ft_check_map_err(data->map_base) || ft_check_elem_err(data->elem_base))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
