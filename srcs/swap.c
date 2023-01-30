/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucaland <aucaland@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 16:26:15 by aucaland          #+#    #+#             */
/*   Updated: 2023/01/04 10:05:05 by aucaland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap_a(t_list_int **list, int is_print)
{
	int	size;
	int	temp;

	size = ft_lstsize_int(*list);
	if (size > 1)
	{
		temp = (*list)->value;
		(*list)->value = (*list)->next->value;
		(*list)->next->value = temp;
	}
	if (is_print)
		ft_putendl_fd("sa", 1);
}

void	swap_b(t_list_int **list, int is_print)
{
	int	size;
	int	temp;

	size = ft_lstsize_int(*list);
	if (size > 1)
	{
		temp = (*list)->value;
		(*list)->value = (*list)->next->value;
		(*list)->next->value = temp;
	}
	if (is_print)
		ft_putendl_fd("sb", 1);
}

void	swap_all(t_list_int **list_a, t_list_int **list_b)
{
	swap_a(list_a, 0);
	swap_b(list_b, 0);
	ft_putendl_fd("ss", 1);
}

void	r_rotate_all(t_list_int **list_a, t_list_int **list_b)
{
	r_rotate_a(list_a, 0);
	r_rotate_b(list_b, 0);
	ft_putendl_fd("rrr", 1);
}
