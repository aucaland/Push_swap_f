/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucaland <aucaland@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 15:58:25 by aucaland          #+#    #+#             */
/*   Updated: 2023/01/04 10:05:24 by aucaland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate_a(t_list_int **list, int is_printed)
{
	t_list_int	*top;

	if (!*list || ft_lstsize_int(*list) < 2)
	{
		if (is_printed)
			ft_putendl_fd("rb", 1);
		return ;
	}
	if (*list)
	{
		top = (*list)->next;
		ft_lstadd_back_int(list, *list);
		*list = top;
	}
	if (is_printed)
		ft_putendl_fd("ra", 1);
}

void	rotate_b(t_list_int **list, int is_printed)
{
	t_list_int	*top;

	if (!*list || ft_lstsize_int(*list) < 2)
	{
		if (is_printed)
			ft_putendl_fd("rb", 1);
		return ;
	}
	if (*list)
	{
		top = (*list)->next;
		ft_lstadd_back_int(list, *list);
		*list = top;
	}
	if (is_printed)
		ft_putendl_fd("rb", 1);
}

void	rotate_all(t_list_int **list_a, t_list_int **list_b)
{
	rotate_a(list_a, 0);
	rotate_b(list_b, 0);
	ft_putendl_fd("rr", 1);
}

void	r_rotate_a(t_list_int **list, int is_printed)
{
	t_list_int	*prev;
	t_list_int	*top;

	prev = NULL;
	if (ft_lstsize_int(*list) < 2)
	{
		if (is_printed)
			ft_putendl_fd("rra", 1);
		return ;
	}
	top = *list;
	while (*list && (*list)->next)
	{
		prev = *list;
		*list = (*list)->next;
	}
	ft_lstadd_front_int(&top, *list);
	prev->next = NULL;
	*list = top;
	if (is_printed)
		ft_putendl_fd("rra", 1);
}

void	r_rotate_b(t_list_int **list, int is_printed)
{
	t_list_int	*prev;
	t_list_int	*top;

	prev = NULL;
	if (ft_lstsize_int(*list) < 2)
	{
		if (is_printed)
			ft_putendl_fd("rrb", 1);
		return ;
	}
	top = *list;
	while (*list && (*list)->next)
	{
		prev = *list;
		*list = (*list)->next;
	}
	ft_lstadd_front_int(&top, *list);
	prev->next = NULL;
	*list = top;
	if (is_printed)
		ft_putendl_fd("rrb", 1);
}
