/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bin_coll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaillag <cgaillag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 18:09:46 by cgaillag          #+#    #+#             */
/*   Updated: 2022/11/26 19:09:46 by cgaillag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	else if (type == LST_LIN)
		return (sizeof(t_line));
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
	else if (ptr && type == LST_LIN)
		ft_lstdelone_line((t_line *)ptr);
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
		ft_err_msg(1, NULL, ER_MALLOC);
		//nettoyer
		exit(EXIT_FAILURE);//revoir
	}
	return (ptr);
}

static void	ft_failed_malloc(t_bin **bin_head, int flag, t_base *base)
{
	ft_putendl_fd(ERRMAL, 2);
	ft_close_std();
	if (data)
		ft_close_fd(data);
	rl_clear_history();
	if (flag == ADD_C || flag == MALLOC_C)
		g_val_exit = 42;
	else
		g_val_exit = 1;
	ft_free_bin(bin_head);
	exit (g_val_exit);
}

void	*ft_handle_malloc(int flag_type, void *ptr, int size, t_base *base)
{
	static t_bin	*bin_head;
	void			*ptr2;
	int				flag;

	ptr2 = NULL;
	flag = ((flag_type / 1000) * 1000) + (flag_type % 10);
	if (flag == MALLOC)
		ptr2 = malloc(ft_get_sizeof(flag_type - flag) * size);
	else
		ptr2 = ptr;
	if (flag == MALLOC || flag == ADD)
	{
		if (ptr2 == NULL)
			ft_failed_malloc(&bin_head, flag, base);
		if (ft_lstadd_bin(&bin_head, ptr2, (flag_type - flag), size) == 1)
		{
			ft_free_ptr_type(ptr2, (flag_type - flag), size);
			ft_failed_malloc(&bin_head, flag, base);
		}
	}
	else if (flag == DELONE)
		ft_lstclearone_bin(&bin_head, ptr);
	else
		ft_free_bin(&bin_head);
	return (ptr2);
}
