/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bin_coll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaillag <cgaillag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 18:09:46 by cgaillag          #+#    #+#             */
/*   Updated: 2022/12/01 15:50:32 by cgaillag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// *************************voir pour t_img !!!!!!!!!!!!!**********************
// *************************voir pour t_img !!!!!!!!!!!!!**********************

/* <SUMMARY> Gets the 'sizeof' corresponding to the given type
*/
static size_t	ft_get_sizeof(int type)
{
	if (type == TAB_INT1)
		return (sizeof(int));
	else if (type == TAB_INT2 || type == TAB_INTS)
		return (sizeof(int *));
	else if (type == TAB_STR1)
		return (sizeof(char));
	else if (type == TAB_STR2 || type == TAB_STRS)
		return (sizeof(char *));
	else if (type == LST_LINE)
		return (sizeof(t_line));
	else if (type == LST_GAME)
		return (sizeof(t_game));
	return (0);
}

/* <SUMMARY> Refers to the cleaning action depending on the given type
*/
void	ft_free_ptr_type(void *ptr, int type, int size)
{
	if (!ptr)
		return ;
	if (ptr && type == TAB_INT1)
		ft_free_ints((int *)ptr, NULL, NULL);
	else if (ptr && (type == TAB_INT2 || type == TAB_INTS))
		ft_free_tabint2((int **)ptr, size, type);
	else if (ptr && type == TAB_STR1)
		ft_free_strs((char *)ptr, NULL, NULL);
	else if (ptr && (type == TAB_STR2 || type == TAB_STRS))
		ft_free_tabstr2((char **)ptr, type);
	else if (ptr && type == LST_LINE)
		ft_lstdelone_line((t_line *)ptr);
	// else if (ptr && type == LST_GAME)
	// 	ft_lstdelone_game((t_game *)ptr);
	return ;
}

/*  ***** Cleaning - protect memory allocation *****
**  *************************
**  <SUMMARY>	Allocate uninitialized space
**				and return a pointer to the allocated memory
*/
void	*ft_malloc(int type, int size)
{
	void	*ptr;

	ptr = malloc(ft_get_sizeof(type) * size);
	if (!ptr)
	{
		ft_err_msg_1(1, NULL, NULL, ER_MALLOC);
		//nettoyer
		exit(EXIT_FAILURE);//revoir
	}
	return (ptr);
}

static void	ft_failed_malloc(t_bin **bin_head)
{
	ft_putendl_fd(ER_MALLOC, 2);
	ft_close_fd();
	ft_free_bin(bin_head);
	exit (EXIT_FAILURE);
}

void	*ft_magic_malloc(int flag_type, void *ptr, int size)
{
	static t_bin	*bin_head;
	void			*ptr2;
	int				flag;

	ptr2 = NULL;
	flag = ((flag_type / 1000) * 1000);
	if (flag == MALLOC)
		ptr2 = malloc(ft_get_sizeof(flag_type - flag) * size);
	else
		ptr2 = ptr;
	if (flag == MALLOC || flag == ADD)
	{
		if (ptr2 == NULL)
			ft_failed_malloc(&bin_head);
		if (ft_lstadd_bin(&bin_head, ptr2, (flag_type - flag), size) == 1)
		{
			ft_free_ptr_type(ptr2, (flag_type - flag), size);
			ft_failed_malloc(&bin_head);
		}
	}
	else if (flag == DELONE)
		ft_lstclearone_bin(&bin_head, ptr);
	else
		ft_free_bin(&bin_head);
	return (ptr2);
}
