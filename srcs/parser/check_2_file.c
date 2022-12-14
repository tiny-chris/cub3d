/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_2_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaillag <cgaillag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 16:48:15 by cgaillag          #+#    #+#             */
/*   Updated: 2022/12/14 19:30:38 by cgaillag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*  ***** Parsing - check lines order (subpart) *****
**  *************************
**  <SUMMARY>	Check if there are other line types than 'L_MAP' between first
**	and last L_MAP lines (only L_EMPTY lines are allowed after L_MAP lines)
**	<RETURN>	none
**				if error --> only exit
*/
static void	ft_check_lines_order_post_elem(t_line **list_base)
{
	t_line	*l;

	l = (*list_base);
	if (l && (l->type) == L_MAP)
	{
		l->range = 7;
		while (l && l->type == L_MAP)
			l = l->next;
		if (l && (l->type == L_TEXTURE || l->type == L_COLOR \
			|| l->type == L_UNEXPECT))
			ft_exit_base(ft_msg_1(1, ER_ELE_ERR, l->rank, ER_ELE_UNEX));
		else if (l && l->type == L_EMPTY)
		{
			while (l && l->type == L_EMPTY)
				l = l->next;
			if (l && (l->type == L_TEXTURE || l->type == L_COLOR \
				|| l->type == L_UNEXPECT || l->type == L_MAP))
				ft_exit_base(ft_msg_1(1, ER_ELE_ERR, l->rank, ER_ELE_UNEX));
		}
	}
	else
		ft_exit_base(ft_msg_1(1, ER_MAP_ERR, NULL, ER_MAP_NONE));
}

/*  ***** Parsing - check lines order *****
**  *************************
**  <SUMMARY> Check number of textures & colors and position (before map line)
**	<RETURN>	- if error		--> return 1 + display error message
**  			- if no error	--> return 0
*/
int	ft_check_lines_order_err(t_base *base)
{
	t_line	*l;
	int		nb_text;
	int		nb_color;

	l = base->list_base;
	nb_text = 0;
	nb_color = 0;
	while (l && l->type != L_MAP)
	{
		if (l->type == L_UNEXPECT)
			ft_exit_base(ft_msg_1(1, ER_ELE_ERR, l->rank, ER_ELE_UNEX));
		else if (l->type == L_TEXTURE)
			nb_text++;
		else if (l->type == L_COLOR)
			nb_color++;
		l = l->next;
	}
	if (nb_text != 4)
		ft_exit_base(ft_msg_1(1, NULL, NULL, ER_TEX_NBR));
	if (nb_color != 2)
		ft_exit_base(ft_msg_1(1, NULL, NULL, ER_COL_NBR));
	ft_check_lines_order_post_elem(&l);
	return (0);
}

/*  ***** Parsing - check file content *****
**  *************************
**  <SUMMARY>	Main checking function on detailed content of the file
**	<RETURN>	- EXIT_FAILURE if any error (msg already displayed)
**				- EXIT_SUCCESS to continue the program
*/
int	ft_check_file_err(t_base *base)
{
	if (ft_check_lines_order_err(base))
		return (EXIT_FAILURE);
	ft_update_t_base(base);
	if (ft_check_elem_err(base))
		return (EXIT_FAILURE);
	if (ft_check_map_err(base))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
