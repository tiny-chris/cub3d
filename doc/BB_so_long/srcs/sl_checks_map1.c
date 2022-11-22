/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_checks_map1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaillag <cgaillag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 00:06:09 by cgaillag          #+#    #+#             */
/*   Updated: 2022/06/28 01:37:48 by cgaillag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/*  ***** Check - correct map format *****
**  *************************
**  List of actions:
**  - The map is a rectangular (all lines with same length)
**  - There is only one starting position (exactly one player)
**  - There is at least one exit
**	- There is at least one collectible
**  - There are only the 5 allowed characters
**  - The map is closed by walls
*/
int	ft_check_map_format_sl(char **map, int lines)
{
	if (!map || lines == 0)
		return (ft_error_msg_sl(ERRMSG_M1), 0);
	if (ft_check_rect_len_sl(map) == 0)
		return (ft_error_msg_sl(ERRMSG_M2), 0);
	if (ft_check_walls_sl(map, lines) == 0)
		return (ft_error_msg_sl(ERRMSG_M6), 0);
	if (ft_count_char_sl(map, lines, 'P') != 1)
		return (ft_error_msg_sl(ERRMSG_M3), 0);
	if (ft_count_char_sl(map, lines, 'E') <= 0)
		return (ft_error_msg_sl(ERRMSG_M4), 0);
	if (ft_count_char_sl(map, lines, 'C') <= 0)
		return (ft_error_msg_sl(ERRMSG_M4), 0);
	if (ft_check_allw_char_sl(map, lines, "01CEP") == 0)
		return (ft_error_msg_sl(ERRMSG_M5), 0);
	return (1);
}
